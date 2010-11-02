#include <stdio.h>
#include <tchar.h>

#include "Types.h"
#include "Stats.h"
#include "Tests.h"
#include "Hamming.h"
#include "Junk.h"
#include "SimAnneal.h"

#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <intrin.h>

#pragma warning(disable : 4702)

//-----------------------------------------------------------------------------

template < int nbits > 
void printkey ( Blob<nbits> & k )
{
	int nbytes = nbits/8;

	printf("{");

	uint8_t * d = (uint8_t*)&k;

	for(int i = 0; i < nbytes; i++)
	{
		printf("0x%02x,",d[i]);
	}
	printf("};\n");
}


//-----------------------------------------------------------------------------
// Test code for Murmur3's mix function

/*
uint32_t i1 = 0x95543787;
uint32_t i2 = 0x2ad7eb25;

uint32_t m1 = 9;
uint32_t a1 = 0x273581d8;

uint32_t m2 = 5;
uint32_t a2 = 0xee700bac;

uint32_t m3 = 3;
uint32_t a3 = 0xa6b84e31;

uint32_t r1 = 5;

int stage = 0;

uint32_t m3mix ( uint32_t k )
{
	//return rand_u32();

	uint32_t h = 0x971e137b;
	uint32_t c1 = i1;
	uint32_t c2 = i2;

	for(int i = 0; i < stage; i++)
	{
		h   = h*m3+a3;
		c1  = c1*m1+a1;
		c2  = c2*m2+a2;
	}

	k  *= c1;
	k   = _rotl(k,r1);
	h   = h*m3+a3;
	k  *= c2;
	c1  = c1*m1+a1;
	c2  = c2*m2+a2;
	h  ^= k;

	return h;
}
*/

/*
uint32_t m1 = 0x85ebca6b;
uint32_t m2 = 0xc2b2ae35;
uint32_t m3 = 0x893ed583;

int s1 = 16;
int s2 = 13;
int s3 = 16;

uint32_t fmix ( uint32_t k )
{
	return rand_u32();

	k ^= k >> 16;
	k *= 0x85ebca6b;
	k ^= k >> 13;
	k *= 0xc2b2ae35;
	k ^= k >> 16;

	return k;
}
*/

//-----------------------------------------------------------------------------

/*
struct mixconfig
{
	uint32_t m1;
	uint32_t m2;
};

mixconfig mc = 
{
	0x010d5a2d,
	0xd3636b39,
};

uint32_t fmix32 ( uint32_t k )
{
	//return rand_u32();

	k ^= k >> 16;
	k *= mc.m1;
	k ^= k >> 16;
	k *= mc.m2;
	k ^= k >> 16;

	return k;
}

double mixfit ( void * block, int )
{
	mixconfig * pc = (mixconfig*)block;

	mc.m1 = pc->m1 | 1;
	mc.m2 = pc->m2 | 1;

	Stats s = testMixAvalanche<uint32_t>(mixfunc<uint32_t>(blahmix),2000000);

	return 1.0 - s.m_max;
}

void mixdump ( void * block, int )
{
	mixconfig * pc = (mixconfig*)block;

	printf("0x%08x 0x%08x",pc->m1, pc->m2 );
}
*/

//-----------------------------------------------------------------------------
// SimAnneal optimize of fmix64

struct mixconfig
{
	//uint8_t s1;
	uint64_t m1;
	//uint8_t s2;
	uint64_t m2;
	//uint8_t s3;
};

mixconfig mc = { 0xff51afd7ed558ccd, 0xc4ceb9fe1a85ec53 };

uint64_t fmix64_test ( uint64_t k )
{
	k ^= k >> 33;
	//k ^= k >> mc.s1;

	k *= mc.m1;

	k ^= k >> 33;
	//k ^= k >> mc.s2;

	k *= mc.m2;

	k ^= k >> 33;
	//k ^= k >> mc.s3;

	return k;
}

double fmix64_fit ( void * block, int )
{
	mixconfig * pc = (mixconfig*)block;

	mc.m1 = pc->m1 | 1;
	mc.m2 = pc->m2 | 1;

	//mc.s1 = pc->s1 & 63;
	//mc.s2 = pc->s1 & 63;
	//mc.s3 = pc->s1 & 63;

	double bias = calcMixBias<uint64_t>(fmix64_test,50000000);

	return 1.0 - bias;
}

void fmix64_dump ( void * block, int )
{
	mixconfig * pc = (mixconfig*)block;

	//pc->s1 &= 63;
	//pc->s2 &= 63;
	//pc->s3 &= 63;

	//printf("{ %2d, 0x%016I64x, %2d, 0x%016I64x, %2d }; ",pc->s1, pc->m1, pc->s2, pc->m2, pc->s3 );
	printf("{ 0x%016I64x, 0x%016I64x }; ", pc->m1, pc->m2 );
}

uint32_t fmix32_test ( uint32_t h )
{
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;

	return h;
}

void optimize_fmix64 ( void )
{
	printf("lskdflksj\n");
	double bias = calcMixBias<uint32_t>(fmix32_test,500000000);

	printf("%f\n",bias);

	//SimAnneal(&mc,sizeof(mc),fmix64_fit,fmix64_dump,4,100);
}


//-----------------------------------------------------------------------------
// Fitness == distribution of Hamming weights.
// Optimize mix by minmaxing Hamming weights

// (we want the smallest differential hamming weight to be as large as possible)

void HammingOptimize ( uint32_t (*mix)(uint32_t) )
{
	double best[33];
	best[0] = 2000000000;

	double c[33];

	printf("0x%08x\n",rand_u32());

	//for(m3 = 0; m3 < 32; m3++)
	
	for(int i = 0; i < 100000; i++)
	{
		//for(r1 = 12; r1 < 18; r1++)
		{
			memset(c,0,sizeof(c));
			SparseDiffHamming32(mix,c);

			if(hamless(33,c,best))
			{
				memcpy(best,c,sizeof(c));

				//printf("{%6.3f, %6.3f, %6.3f, %6.3f, %6.3f, %6.3f, %6.3f, %6.3f, %6.3f } - ",c[0],c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8]);

				printf("{");

				for(int i = 0; i < 33; i++) printf("%6.3f ",c[i]);
				printf("} - ");

				//printf("0x%08x, %2d, 0x%08x %2d\n",m1,r1,m2,m3);
				//printf("0x%08x, 0x%08x\n",m1,m2);
				printf("\n");
			}
		}
	}
}

//-----------------------------------------------------------------------------

u128 mix128 ( u128 h2 )
{
	uint32_t * h = (uint32_t*)&h2;

	for(int i = 0; i < 30; i++)
	{
		h[0] = _rotl(h[0],3);
		h[1] = _rotl(h[1],10);
		h[2] = _rotl(h[2],19);
		h[3] = _rotl(h[3],26);

		h[0] += h[1];
		h[0] += h[2];
		h[0] += h[3];

		h[1] += h[0];
		h[2] += h[0];
		h[3] += h[0];
	}

	return h2;
}

//-----------------------------------------------------------------------------

void scratchmain ( void )
{
	/*
	double worst = 1000;

	double worstStage = 0;

	for(stage = 0; stage < 16; stage++)
	{
		Stats s = testMixAvalanche<uint32_t>(mixfunc<uint32_t>(m3mix),300);

		if(s.m_nbad > worstStage) worstStage = s.m_nbad;
	}

	if(worstStage < worst)
	{
		worst = worstStage;

		printf("%3.4f : 0x%08x 0x%08x %2d 0x%08x %2d 0x%08x %2d 0x%08x %2d\n",worst,i1,i2,m1,a1,m2,a2,m3,a3,r1);
	}

	//----------

	for(int i = 0; i < 1000000; i++)
	{
		for(m1 = 3; m1 < 10; m1 += 2)
		for(m2 = 3; m2 < 10; m2 += 2)
		for(m3 = 3; m3 < 10; m3 += 2)
		for(r1 = 0; r1 < 32; r1++)
		//for(int bit = 0; bit < 32; bit++)
		{
			//i2 ^= (1 << bit);

			if(m1 == 7) continue;
			if(m2 == 7) continue;
			if(m3 == 7) continue;

			double worstStage = 0;

			for(stage = 0; stage < 16; stage++)
			{
				Stats s = testMixAvalanche<uint32_t>(mixfunc<uint32_t>(m3mix),300);

				if(s.m_nbad > worstStage) worstStage = s.m_nbad;
			}

			if(worstStage < worst)
			{
				worst = worstStage;

				printf("%3.4f : 0x%08x 0x%08x %2d 0x%08x %2d 0x%08x %2d 0x%08x %2d\n",worst,i1,i2,m1,a1,m2,a2,m3,a3,r1);
			}
			else
			{
				//i2 ^= (1 << bit);
			}
		}

		//i1 = rand_u32();
		//i2 = rand_u32();

		//a1 = rand_u32();
		//a2 = rand_u32();
		//a3 = rand_u32();
	}
	*/
}

//-----------------------------------------------------------------------------

/*
void Pathological ( void )
{
	std::set<uint32_t> s;

	uint32_t c = 0;
	uint32_t seed = 0xdeadbeef * 16;

	for(int j = 0; j < 5000; j++)
	{
		for(uint32_t i = 0; i < 10000; i++)
		{
			uint32_t key[4] = {c,c,c,c};

			uint32_t hash = MurmurHash2(key,16,seed);

			//v.push_back(hash);
			s.insert(hash);
			c++;
		}

		printf("%8d %8f\n",s.size(),double(s.size()) / double(c));
	}
}
*/

/*
void Pathological ( void )
{
	const int nbytes = 512 * 1024 * 1024;

	unsigned char * block = new unsigned char[nbytes];

	memset(block,0,nbytes);

	unsigned int k = 0;
	unsigned int key[256];
	unsigned int collisions = 0;
	
	do
	{
		for(int i = 0; i < 256; i++) key[i] = k;

		unsigned int h;
		h = MurmurHash2(&key[0],256*4,(0xdeadbeef * 16));
		//MurmurHash3_x86_32(&key[0],32,(0xdeadbeef * 16),&h);

		//printf("0x%08x\n",h);

		if(getbit(block,nbytes,h))
		{
			collisions++;
		}

		setbit(block,nbytes,h);

		if(k % 10000000 == 0)
		{
			printf("%12d : %9d : %f\n",k,collisions,double(collisions) / double(k));
		}

		k++;
	}
	while(k != 0);

	printf("%d total collisions",collisions);

	delete [] block;
}
*/

/*
void Pathological ( void )
{
	const int nbytes = 512 * 1024 * 1024;

	unsigned char * block = new unsigned char[nbytes];

	memset(block,0,nbytes);

	unsigned int k = 0;
	unsigned int unique = 0;
	
	do
	{
		const uint32_t m = 0xdeadbeef;
		const int r = 24;

		uint32_t x = 0;
		uint32_t h = 0;

		x = k;
		x *= m;
		x ^= x >> r;
		x *= m;

		h *= m;
		h ^= x;

		x = k;
		x *= m;
		x ^= x >> r;
		x *= m;

		h *= m;
		h ^= x;

		if(!getbit(block,nbytes,h))
		{
			unique++;
		}

		setbit(block,nbytes,h);

		if(k % 10000000 == 0)
		{
			printf("%12d : %9d :%f\n",k,unique,double(unique) / double(k));
		}

		k++;
	}
	while(k);

	printf("%d unique",unique);

	delete [] block;
}
*/

/*
void Pathological ( void )
{
	typedef std::map<uint32_t,uint32_t> cmap;
	
	cmap collisionmap;

	const int nbytes = 512 * 1024 * 1024;

	unsigned char * block = new unsigned char[nbytes];

	memset(block,0,nbytes);

	unsigned int k = 0;
	unsigned int key[4];
	unsigned int collisions = 0;
	
	do
	{
		for(int i = 0; i < 4; i++) key[i] = k;

		unsigned int h;
		h = MurmurHash2(&key[0],4*sizeof(uint32_t),16);
		//MurmurHash3_x86_32(&key[0],32,(0xdeadbeef * 16),&h);

		//printf("0x%08x\n",h);

		if(getbit(block,nbytes,h))
		{
			collisions++;
			collisionmap[h]++;
		}

		setbit(block,nbytes,h);

		if(k % 10000000 == 0)
		{
			printf("%12d : %9d : %9d :%f\n",k,collisionmap.size(),collisions,double(collisions) / double(k));
		}

		k++;
	}
	//while(k);
	while(k <= 200000000);

	uint32_t most = 0;
	for(cmap::iterator i = collisionmap.begin(); i != collisionmap.end(); ++i)
	{
		uint32_t h = (*i).first;
		uint32_t c = (*i).second;

		if(c > most)
		{
			most = c;
			printf("0x%08x : %d\n",h,c);
		}
	}

	printf("%d total collisions",collisions);

	delete [] block;
}
*/

/*
void Pathological ( void )
{
	unsigned int k = 0;
	unsigned int key[4];

	std::vector<uint32_t> v;
	
	do
	{
		for(int i = 0; i < 4; i++) key[i] = k;

		unsigned int h;
		h = MurmurHash2(&key[0],4*sizeof(uint32_t),16);

		if(h == 0xb5abf828) 
		{
			v.push_back(k);
		}

		if(k % 100000000 == 0)
		{
			printf("%12u : %12d\n",k,v.size());
		}


		k++;
	}
	while(k);

	for(size_t i = 0; i < v.size(); i++)
	{
		printf("0x%08x,",v[i]);
		if(i%8==7) printf("\n");
	}
	printf("\n");
}
*/

/*
uint32_t bad[] = 
{
0x0017f1a9,0x00f8c102,0x01685768,0x01c6d69e,0x02109e20,0x02ea2120,0x03615606,0x03bab745,
0x03eb73e9,0x03f7db48,0x04391e64,0x04747fa7,0x04b81cf5,0x04fbcab0,0x054bf06a,0x05d33abc,
0x05d8eb48,0x06560ce6,0x0697bcfa,0x06a40faa,0x071977fb,0x073a4306,0x073eb088,0x0751c777,
0x07534cb4,0x079d2fbe,0x07a0ba13,0x07cff5fc,0x082b2d13,0x08457c35,0x093de81e,0x09711b75,
0x097fdb48,0x09ba9060,0x0a06228a,0x0a5f8691,0x0a63881c,0x0a70bcd7,0x0aed67dd,0x0b0ed19a,
0x0bc68125,0x0c29fe48,0x0ca1eb57,0x0cbfc528,0x0d4017e2,0x0d6d91c2,0x0d7388de,0x0f0133e9,
0x0f8d17e7,0x0f90e980,0x0fe6be43,0x1033d71d,0x1087872c,0x10b52186,0x12005768,0x12c817e2,
0x12ed3caf,0x1343eae2,0x137b2949,0x1407d537,0x1462906a,0x156742a0,0x15f44042,0x17204969,
0x18c86d6a,0x192c6777,0x1950b0f3,0x19548454,0x1961fb59,0x19e92685,0x1a24be52,0x1a72ccfa,
0x1a7caf9b,0x1a9d7aa6,0x1b9407c9,0x1b9d472c,0x1bdc3c3f,0x1c2a955f,0x1c44f065,0x1c75fda6,
0x1c934985,0x1cd45315,0x1d1dce3e,0x1d695a2a,0x1e88f490,0x203a3985,0x2050669c,0x20a34f82,
0x221b4985,0x222718dc,0x2240aa13,0x22a67680,0x24bdf477,0x250ead99,0x255d00e9,0x2652bb8e,
0x26823b4d,0x27298fd2,0x27bf3042,0x27e2e537,0x282dbcdc,0x295777e2,0x2ab449ff,0x2d347ad3,
0x2d3c176d,0x2d4c5e25,0x2d72b111,0x2d9f768f,0x2ddfe73b,0x2e00b246,0x2f9f1523,0x2fdbdba7,
0x30831cfa,0x30cc91ca,0x3129f75c,0x313f9486,0x315255e3,0x31e70a31,0x33490a31,0x33622c30,
0x33863468,0x3441b8a7,0x349f03ad,0x3715eda6,0x374df66c,0x3766e2fc,0x3848010c,0x385325bb,
0x38a843f3,0x398e8722,0x39cc0d5b,0x39e572ed,0x3ace4477,0x3afb8c19,0x3b98b8d4,0x3ce6212a,
0x3cec46c6,0x3d43761a,0x3de45e25,0x3e1e5a2c,0x3f612a36,0x4008f490,0x41431edb,0x4163e9e6,
0x41742120,0x41854564,0x41ca60f3,0x41fa37f6,0x421e16a3,0x4263b66c,0x42bc7a4a,0x434286ad,
0x435858a7,0x43bbf5f2,0x43e43d7e,0x442fc96a,0x443e6342,0x44b58d83,0x45378356,0x45df4db0,
0x46b09971,0x47337cff,0x47f46fc3,0x48023b4d,0x4823a50a,0x49691a36,0x497767dd,0x4a50eadd,
0x4ad26a3b,0x4b8463b7,0x4bc34e34,0x4bcd5cc3,0x4bf245e3,0x4c62946d,0x4d18b7f9,0x4da4d029,
0x4dcac8e3,0x4df83139,0x4e2514b8,0x4e859f82,0x4ea95477,0x4ef42c1c,0x4f68a832,0x4f7acba7,
0x4fa478d9,0x4ffe8c21,0x50ee3486,0x514795c5,0x51948107,0x51c5fce4,0x51e3eaec,0x52015e27,
0x526260f3,0x5288a930,0x5360193c,0x53e7ac58,0x54a6567b,0x54c72186,0x54cb8f08,0x54dea5f7,
0x552d9893,0x555d6f96,0x55b80b93,0x56cac69e,0x56fdf9f5,0x5793010a,0x57d7b747,0x57ec6511,
0x57f0669c,0x57fd9b57,0x5818c523,0x58fe6cff,0x5a011a36,0x5a4ca3a8,0x5b00675e,0x5c50bfbc,
0x5c6a50f3,0x5d19f667,0x5d2504a9,0x5ddbc685,0x5e85812a,0x5ed4c61f,0x5f4d0056,0x5fd14dba,
0x5fd77356,0x608b5837,0x60d6c07e,0x610807c9,0x610986bc,0x6194b3b7,0x62f42120,0x62f774b3,
0x63233736,0x6361c3c1,0x63811ec2,0x64ad27e9,0x650011e5,0x66b945f7,0x66dd8f73,0x67361999,
0x67471347,0x67760505,0x6789c685,0x68098e1b,0x683ac4a9,0x68ca7a40,0x69b773df,0x69d5acdc,
0x6a1ec7e7,0x6a202805,0x6a613195,0x6a6a70f8,0x6a74f315,0x6a838109,0x6aaaacbe,0x6af638aa,
0x6b4727f6,0x6b7bfcc3,0x6d4eb4ac,0x6dc71805,0x6ef55b70,0x6fa82805,0x6fb3f75c,0x6fcd8893,
0x7014bf91,0x70fc7fc8,0x724ad2f7,0x729b8c19,0x72b8b523,0x735e4f12,0x7378556e,0x73ac5dba,
0x74b66e52,0x74e8531f,0x754c0ec2,0x7564261f,0x7567c4bd,0x756fc3b7,0x75af8e66,0x75ba9b5c,
0x7841287f,0x7973ca45,0x7aaa7fc8,0x7ac8f5ed,0x7aec261f,0x7b2c550f,0x7b6cc5bb,0x7d2bf3a3,
0x7d68ba27,0x7d8f1e39,0x7d98de70,0x7edf3463,0x80626b7a,0x80b1ec4c,0x81ce9727,0x827aca36,
0x82944f12,0x86352273,0x8831268f,0x885b22f7,0x887d51bd,0x889f261a,0x89259754,0x89bcadba,
0x8a323fd7,0x8a72ffaa,0x8a792546,0x8ad0549a,0x8b209af1,0x8bbe27e7,0x8c066fc3,0x8c4464b3,
0x8cd4d306,0x8cee08b6,0x8d4ab321,0x8ecffd5b,0x8f1223e4,0x8f573f73,0x8f871676,0x904958ca,
0x904f7e66,0x90e53727,0x91711bfe,0x91859d88,0x919dfef4,0x91cb41c2,0x92426c03,0x92c461d6,
0x92fffef4,0x936c2c30,0x93dd8269,0x94351cd9,0x94c05b7f,0x94e87d04,0x954e3aba,0x95814e43,
0x95bbcab0,0x96f5f8b6,0x985f48bb,0x99502cb4,0x995a3b43,0x997f2463,0x99ef72ed,0x9a4e3c2b,
0x9b57a763,0x9b850fb9,0x9bb1f338,0x9bc723cb,0x9be0895d,0x9c3632f7,0x9c7c176d,0x9c810a9c,
0x9cf586b2,0x9d07aa27,0x9d315759,0x9d8b6aa1,0x9e99eeef,0x9f215f87,0x9f70c96c,0x9fc195cf,
0x9fef3f73,0xa06af1b8,0xa06d0dbf,0xa0840b00,0xa12e0083,0xa14df1d4,0xa1748ad8,0xa1884c58,
0xa2ea4e16,0xa307c528,0xa3f0607e,0xa40bfafb,0xa4558d79,0xa547228c,0xa56495c7,0xa5a5a3a3,
0xa68b4b7f,0xa728daba,0xa78df8b6,0xa8de0999,0xa90e5479,0xa9dd9e3c,0xa9f72f73,0xa9fd51bd,
0xaab1e329,0xab3aeee7,0xab68a505,0xab9c9eea,0xabfd18dc,0xac125faa,0xac61a49f,0xac9edbac,
0xacd9ded6,0xad5e2c3a,0xad6451d6,0xae1836b7,0xae639efe,0xae96653c,0xaee4ad99,0xaef795cf,
0xaf11f9ff,0xaf43c0fd,0xb0845333,0xb0b015b6,0xb0eea241,0xb1114807,0xb28cf065,0xb3db78e8,
0xb439f81e,0xb483bfa0,0xb4c2f819,0xb4d3f1c7,0xb516a505,0xb55d42a0,0xb5c7a329,0xb65758c0,
0xb65e9569,0xb66afcc8,0xb72b3e75,0xb7628b5c,0xb7aba667,0xb7bf11ea,0xb7f74f78,0xb801d195,
0xb8105f89,0xb84c0cc8,0xb8c92e66,0xb8d40676,0xb908db43,0xb90ade7a,0xb917312a,0xb9c66e34,
0xba10513e,0xba43177c,0xbab89db5,0xbadb932c,0xbbf2fcc8,0xbc2db1e0,0xbc8239f0,0xbd60895d,
0xbd81f31a,0xbda19e11,0xbe39a2a5,0xbe895e48,0xbe9d1fc8,0xbf150cd7,0xbfb33962,0xbfe0b342,
0xc04593a3,0xc0eb2d92,0xc10533ee,0xc1393c3a,0xc1745569,0xc2040b00,0xc259dfc3,0xc275319f,
0xc2a6f89d,0xc2f1049f,0xc2f4a33d,0xc2faa8ac,0xc3284306,0xc33c6ce6,0xc47378e8,0xc53b3962,
0xc5605e2f,0xc5b70c62,0xc6d5b1ea,0xc700a8c5,0xc8375e48,0xc879049f,0xcb1bfcb9,0xcb25bcf0,
0xcb3b8eea,0xcbc7a5d4,0xcbd51cd9,0xcc97dfd2,0xcce5ee7a,0xcd109c26,0xcdef49fa,0xce072949,
0xce1068ac,0xce3ecacc,0xce4f5dbf,0xceb811e5,0xcee91f26,0xd007a8b6,0xd0212d92,0xd0fc1610,
0xd2c3881c,0xd3167102,0xd5199800,0xd5be050f,0xd60a303d,0xd62c049a,0xd7498c3a,0xd7bf1e57,
0xd7d02269,0xd8ad7971,0xd8c5dd0e,0xd8f55ccd,0xd94b0667,0xd9934e43,0xd9d14333,0xda61b186,
0xdad791a1,0xdbca9962,0xdddc5ce6,0xdf127c08,0xdf2add74,0xdfa79c53,0xdfbf7fa5,0xdfe5d291,
0xe073d3c6,0xe08cdd74,0xe16a60e9,0xe1c1fb59,0xe2755b84,0xe2db193a,0xe2f63e7a,0xe33fb34a,
0xe348a930,0xe39d18dc,0xe3b2b606,0xe45a2bb1,0xe5bc2bb1,0xe5d54db0,0xe5f955e8,0xe712252d,
0xe7db1aab,0xe954024b,0xe96d67dd,0xe9890f26,0xe9c117ec,0xe9da047c,0xea08f5ed,0xeabb228c,
0xeac6473b,0xec01a8a2,0xec26cd6f,0xec3f2edb,0xec58946d,0xed4e744f,0xed6ead99,0xedf7d038,
0xedf9ec3f,0xee10e980,0xeebadf03,0xeedad054,0xef152ad8,0xf0577fa5,0xf0917bac,0xf094a3a8,
0xf17d3efe,0xf198d97b,0xf1e26bf9,0xf27c1610,0xf2d4010c,0xf3d70b66,0xf3e742a0,0xf4913823,
0xf4b5b93a,0xf4d6d7ec,0xf5b5a82d,0xf62f1772,0xf66ae819,0xf69b32f9,0xf6a2eaea,0xf78a303d,
0xf8c7cd67,0xf923baf1,0xf9297d6a,0xf989f75c,0xfa2bba2c,0xfa755ccd,0xfa96c68a,0xfbea895d,
0xfc718c19,0xfc84744f,0xfc9ed87f,0xfcc40c5d,0xfcd09f7d,0xfdf78537,0xfe9e2687,0xff8bd979,
};

void Pathological ( void )
{
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.

	const uint32_t m = 0x5bd1e995;
	const int r = 24;

	for(int i = 0; i < 100; i++)
	{
		uint32_t h = 0;
		uint32_t k = bad[i];

		printf("0x%08x : ",k);
		k *= m;
		printf("0x%08x : ",k);
		k ^= k >> r;
		printf("0x%08x : ",k);
		k *= m;
		printf("0x%08x : ",k);

		printf(" - ");

		h = k;
		printf("0x%08x : ",h);
		h *= m;
		printf("0x%08x : ",h);
		h ^= k;
		printf("0x%08x : ",h);
		h *= m;
		printf("0x%08x : ",h);
		h ^= k;
		printf("0x%08x : ",h);
		h *= m;
		printf("0x%08x : ",h);
		h ^= k;
		printf("0x%08x\n",h);

	}
}
*/

/*
void Pathological ( void )
{
	const int nbytes = 512 * 1024 * 1024;

	unsigned char * block = new unsigned char[nbytes];

	memset(block,0,nbytes);

	unsigned int k = 0;
	unsigned int collisions = 0;
	
	do
	{
		//const uint32_t m = 0x5bd1e995;
		unsigned int h = 0;

		uint32_t m1 = 0x5bd1e995;
		uint32_t m2 = 0x5bd1e995;
		uint32_t m3 = 0x5bd1e995;
		uint32_t x;

		x = k; x *= m1; x ^= x >> 25; x *= m2; h ^= x; h *= m3;
		m2 = m2*9+0x273581d8;
		x = k; x *= m1; x ^= x >> 25; x *= m2; h ^= x; h *= m3;
		m2 = m2*9+0x273581d8;
		
		//printf("0x%08x : 0x%08x\n",k,h);
		//h *= 3;

		if(getbit(block,nbytes,h))
		{
			collisions++;
		}

		setbit(block,nbytes,h);

		if(k % 10000000 == 0)
		{
			printf("%12u : %9u : %f\n",k,collisions,double(collisions) / double(k));
		}

		k++;
	}
	while(k != 0);

	printf("%u total collisions, %f",collisions,double(collisions) / 4294967296.0);

	delete [] block;
}
*/

/*
// Applying FWT to fmix32 to look for linearities (it found some bias, but nothing above a fraction of a percent)

void find_linear_approximation_walsh2 ( mixfunc<uint32_t> f, uint32_t mask, int inbits, uint32_t & outL, int64_t & outBias );
void find_linear_approximation_walsh  ( mixfunc<uint32_t> f, uint32_t mask, int inbits, uint32_t & outL, int64_t & outBias );
uint32_t test_linear_approximation ( mixfunc<uint32_t> f, uint32_t l, uint32_t mask, int inbits );

uint32_t bitrev ( uint32_t v );

uint32_t FWTMix ( uint32_t x )
{
	x ^= x >> 16;
	x *= 0x85ebca6b;
	x ^= x >> 13;
	x *= 0xc2b2ae35;
	x ^= x >> 16;

	return x;
}

double test_linear_approximation ( mixfunc<uint32_t> f, uint32_t l, uint32_t mask, int64_t size );

void WalshStuff(void )
{
	const int64_t nbits = 32;
	const int64_t size = int64_t(1) << nbits;

	mixfunc<uint32_t> f(FWTMix);

	for(int i = 0; i < nbits; i++)
	{
		uint32_t mask = (1 << i);
		uint32_t outL = 0;
		int64_t bias = 0;
		find_linear_approximation_walsh2(f,mask,nbits,outL,bias);

		double b = test_linear_approximation ( f, outL, mask, size);

		printf("0x%08x, 0x%08x, %8I64d, %f\n",mask,outL,bias,b);
	}
}
*/