#include "Tests.h"

#include "Stats.h"  // for CountCollisions
#include "Random.h"
#include "Bitvec.h"

#include <string.h>
#include <math.h>
#include <set>
#include <vector>
#include <intrin.h>

#pragma warning(disable:4127)

#pragma warning(disable:4127) // warning C4985: 'ceil': attributes not present on previous declaration.

//-----------------------------------------------------------------------------
// 256k blocks seem to give the best results.

void BulkSpeedTest ( pfHash hash )
{
	const int trials = 9999;
	const int blocksize = 256 * 1024;

	printf("Bulk speed test - %d-byte keys\n",blocksize);

	char * block = new char[blocksize + 16];

	rand_p(block,blocksize+16);

	uint32_t temp[16];

	for(int align = 0; align < 4; align++)
	{
		double bestbpc = 0;

		for(int itrial = 0; itrial < trials; itrial++)
		{
			__int64 begin,end;

			begin = __rdtsc();

			hash(block + align,blocksize,itrial,temp);

			end = __rdtsc();

			blackhole(temp[0]);

			double cycles = double(end-begin);
			double bpc = double(blocksize) / cycles;
			if(bpc > bestbpc) bestbpc = bpc;
		}

		double bestbps = (bestbpc * 3000000000.0 / 1048576.0);
		printf("Alignment %2d - %8.4f bytes/cycle, (%.2f MiB/sec @ 3 ghz)\n",align,bestbpc,bestbps);
	}
	printf("\n");

	delete [] block;
}

//----------------------------------------------------------------------------
// Tests the Bit Independence Criteron. Not sure if this still works.

template< int _bits, int _reps, class hashtype >
void BicTest ( hashfunc<uint32_t> hash )
{
	const int bits = _bits;
	const int reps = _reps;
	const int bytes = bits / 8;
	const int hashbytes = sizeof(hashtype);
	const int hashbits = hashbytes * 8;

	int counts[bits][hashbits][hashbits];

	memset(counts,0,sizeof(counts));

	unsigned char k[bytes];

	for(int irep = 0; irep < reps; irep++)
	{
		if(irep % 1000 == 0) printf(".");

		rand_p(k,bytes);
		unsigned int h1 = hash(k,bytes,0);

		for(int in = 0; in < bits; in++)
		{
			flipbit(k,in);
			unsigned int h2 = hash(k,bytes,0);
			flipbit(k,in);

			unsigned int h = h1 ^ h2;

			for(int out1 = 0; out1 < hashbits; out1++)
			for(int out2 = out1; out2 < hashbits; out2++)
			{
				int b1 = (h >> out1) & 1;
				int b2 = (h >> out2) & 1;

				int b = b1 ^ b2;

				if(b1 ^ b2)
				{
					counts[in][out1][out2]++;
				}
			}
		}
	}

	printf("\n");

	int biases[4] = {0,0,0,0};

	for(int i = 0; i < hashbits; i++)
	{
		for(int j = 0; j < hashbits; j++)
		{
			if(i == j)
			{
				printf("\\");
			}
			else if(i > j)
			{
				printf(" ");
			}
			else
			{
				double d = double(counts[16][i][j]) / double(reps);

				int b = (int)(fabs(d * 2 - 1) * 100);

				if(b == 0) printf(".");
				else if(b < 5) printf("o");
				else if(b < 33) printf("O");
				else printf("X");

				if(b == 0)      biases[0]++;
				else if(b < 5)  biases[1]++;
				else if(b < 33) biases[2]++;
				else            biases[3]++;
			}
		}

		printf("\n");
	}


	printf("Bias distribution - %3d : %3d : %3d : %3d\n",biases[0],biases[1],biases[2],biases[3]);

	printf("\n");
}

//----------------------------------------------------------------------------
// Bijection test = hash all possible 32-bit keys, see how many 32-bit values
// are missing. Each missing value indicates a collision.

void BijectionTest ( hashfunc<uint32_t> hash )
{
	const int nbytes = 512 * 1024 * 1024;

	unsigned char * block = new unsigned char[nbytes];

	memset(block,0,nbytes);

	printf("Testing bijection for 32-bit keys");

	unsigned int k = 0;
	
	do
	{
		unsigned int h = hash(&k,4,0);
		setbit(block,nbytes,h);

		if(k % 100000000 == 0) printf(".");

		k++;
	}
	while(k != 0);

	int missing = 0;

	do
	{
		if(!getbit(block,nbytes,k)) missing++;

		k++;
	}
	while(k != 0);

	printf("\nMissing values - %d\n",missing);

	delete [] block;
}

//----------------------------------------------------------------------------
// Loop counting

// Repeatedly hash the same 4-byte value over and over, and track how many
// loops are in the output. 

void LoopTest ( hashfunc<uint32_t> hash )
{
	const int nbytes = 512 * 1024 * 1024;

	unsigned char * block = new unsigned char[nbytes];

	memset(block,0,nbytes);

	int loops = 0;
	unsigned int start = 0;

	while(1)
	{
		if(!getbit(block,nbytes,start)) 
		{
			loops++;

			unsigned int r = 0;
			unsigned int h = start;

			printf("Testing loop starting at %u",start);

			while(1)
			{
				setbit(block,nbytes,h);
				r++;
				h = hash(&h,4,0);

				if(h == start) break;

				if(r % 100000000 == 0) printf(".");
			}

			printf("\nStart point %u looped after %u\n",start,r);
		}

		start++;
		if(start == 0) break;
	}

	printf("Total loops - %d\n",loops);

	delete [] block;
}

//-----------------------------------------------------------------------------
// Trickle test, not really usable by itself. Used for testing the diffusion
// properties of a sequence of adds, xors, rotates, etc - replace the adds and
// xors with ors, compute how many iterations it takes to convert an input with
// a single 1 bit into all 1s.

// I was using it to find optimal rotation constants for various types of 
// diffusion functions, but didn't end up using them

int trickle ( int r[4], int reps )
{
	int worst = 1000;

	for(int i = 0; i < 128; i++)
	{
		uint32_t t[4] = { 0, 0, 0, 0 };

		setbit(t,4,i);

		for(int j = 0; j < reps; j++)
		{
			t[0] |= t[1];
			t[2] |= t[3];
			t[1] |= t[0];
			t[0] |= t[2];

			t[2] |= t[1];
			t[1] |= t[0];
			t[3] |= t[0];

			t[0] = _rotl(t[0],r[0]); 
			t[1] = _rotl(t[1],r[1]);
			t[2] = _rotl(t[2],r[2]); 
			t[3] = _rotl(t[3],r[3]);
		}

		int p = popcount(t[0]) + popcount(t[1]) +  popcount(t[2]) + popcount(t[3]);

		if(p < worst) worst = p;
	}

	return worst;
}

void TrickleTest ( void )
{
	int best = 0;

	int r[4];

	for(int i = 0; i < 1024*1024; i++)
	{
		r[0] = (i >>  0) & 31;
		r[1] = (i >>  5) & 31;
		r[2] = (i >> 10) & 31;
		r[3] = (i >> 15) & 31;

		//if(trickle(r,2) < 16) continue;
		//if(trickle(r,3) < 40) continue;
		//if(trickle(r,4) < 80) continue;

		int worst = trickle(r,6);

		if(worst >= best)
		//if(i % 10000 == 0)
		{
			best = worst;

			printf("\t{");
			for(int i = 0; i < 4; i++)
			{
				printf("%2d, ",r[i]);
			}
			printf("}, // %3d\n",worst);
		}
	}
}

//----------------------------------------------------------------------------
// Alignment of the keys should not affect the hash value - if it does,
// something is broken.

void AlignmentTest ( pfHash hash, const int hashbits )
{
	const int hashbytes = hashbits / 8;

	printf("Testing alignment handling on small keys..........");

	char bufs[16][64];

	char * strings[16];

	for(int i = 0; i < 16; i++)
	{
		uint32_t b = uint32_t(&bufs[i][0]);

		b = (b+15)&(~15);

		strings[i] = (char*)(b + i);

		strcpy_s(strings[i],32,"DeadBeefDeadBeef");
	}

	uint32_t hash1[64];
	uint32_t hash2[64];

	for(int k = 1; k <= 16; k++)
	for(int j = 0; j < 15; j++)
	for(int i = j+1; i < 16; i++)
	{
		const char * s1 = strings[i];
		const char * s2 = strings[j];

		hash(s1,k,0,hash1);
		hash(s2,k,0,hash2);

		if(memcmp(hash1,hash2,hashbytes) != 0)
		{
			printf("*********FAIL*********\n");
			return;
		}
	}

	printf("PASS\n");
}

//----------------------------------------------------------------------------
// Appending zero bytes to a key should always cause it to produce a different
// hash value

void AppendedZeroesTest ( pfHash hash, const int hashbits )
{
	const int hashbytes = hashbits/8;

	printf("Testing zero-appending..........");

	for(int rep = 0; rep < 100; rep++)
	{
		if(rep % 10 == 0) printf(".");

		unsigned char key[256];

		memset(key,0,sizeof(key));

		rand_p(key,32);

		uint32_t h1[16];
		uint32_t h2[16];

		memset(h1,0,hashbytes);
		memset(h2,0,hashbytes);

		for(int i = 0; i < 32; i++)
		{
			hash(key,32+i,0,h1);

			if(memcmp(h1,h2,hashbytes) == 0)
			{
				printf("\n*********FAIL*********\n");
				return;
			}

			memcpy(h2,h1,hashbytes);
		}
	}

	printf("\nPASS\n");
}

//----------------------------------------------------------------------------
// Flipping a bit of a key should, with very high probability, result in a 
// different hash.

bool TwiddleTest ( pfHash hash, const int hashbits )
{
	bool result = true;

	const int hashbytes = hashbits/8;

	printf("Testing bit twiddling..........");

	uint8_t key[256];
	uint32_t h1[16];
	uint32_t h2[16];

	for(int len = 1; len < 16; len++)
	{
		for(int bit = 0; bit < (len * 8); bit++)
		{
			rand_p(key,len);

			hash(key,len,0,h1);
			flipbit(key,len,bit);
			hash(key,len,0,h2);

			if(memcmp(h1,h2,hashbytes) == 0)
			{
				//printf("X");
				result = false;
			}
			else
			{
				//printf(".");
			}
		}

		//printf("\n");
	}

	if(result == false)
		printf("*********FAIL*********\n");
	else
		printf("PASS\n");

	return result;
}

//-----------------------------------------------------------------------------
// Create a bunch of zero-byte keys of different lengths and check distribution.

// We reuse one block of empty bytes, otherwise the RAM cost is enormous.
// The distribution table will have some random 1s in the bottom rows due to
// there not being enough keys for a good test.

void NullKeysetTest ( hashfunc<uint32_t> hash, bool drawDiagram )
{
	int keycount = 64*1024;

	unsigned char * nullblock = new unsigned char[keycount];
	memset(nullblock,0,keycount);

	//----------

	std::vector<uint32_t> hashes;

	hashes.resize(keycount);

	//----------

	printf("Collision test - Hash keyset 100 times, count collisions");

	for(int i = 0; i < keycount; i++)
	{
		if(i % (keycount/10) == 0) printf(".");

		uint32_t h = hash(nullblock,i,0);
		hashes[i] = h;
	}

	testhashlist(hashes,true,true,drawDiagram);

	delete [] nullblock;
}

//-----------------------------------------------------------------------------
// Simple collections of alphanumeric strings

template < typename hashtype >
void TextKeyTest2 ( hashfunc<hashtype> hash, bool drawDiagram )
{
	const char * s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456790123456789";

	const int nbytes = 7;
	const int nbits = 56;
	const int nkeys = 1024*1024;

	printf("Testing %d 7-character text keys - \n",nkeys,nbits);

	//----------
	// generate keyset

	typedef Blob<nbits> keytype;

	std::vector<keytype> keys;
	keys.reserve(nkeys);

	keytype key;

	uint8_t * bytes = (uint8_t*)&key;

	for(int i = 0; i < nkeys; i++)
	{
		for(int j = 0; j < nbytes; j++)
		{
			int d = i >> (j * 3);

			bytes[j] = s[d % 64];
		}

		keys.push_back(key);
	}

	//----------

	testkeylist<keytype,hashtype>(hash,keys,true,true,drawDiagram);
}
