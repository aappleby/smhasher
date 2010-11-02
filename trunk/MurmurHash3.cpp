#include "MurmurHash3.h"

#include <stdlib.h>    // for _rotl

#pragma warning(disable:4100)

//-----------------------------------------------------------------------------
// need to replace this

inline uint32_t kmix ( uint32_t k, uint32_t c1, uint32_t c2 ) 
{
	k *= c1; 
	k  = _rotl(k,11); 
	k *= c2;

	return k;
}

// block mix

inline void bmix1 ( uint32_t & h, uint32_t k, uint32_t c1, uint32_t c2 )
{
	k = kmix(k,c1,c2);
	
	h = h*5+0xa6b84e31;
	h ^= k;
}

// xor before mul is faster on x64

inline void bmix2 ( uint32_t & h, uint32_t k, uint32_t c1, uint32_t c2 )
{
	k = kmix(k,c1,c2);
	
	h ^= k;
	h = h*3+0xa6b84e31;
}

// block constant mix

inline void cmix ( uint32_t & c1, uint32_t & c2 )
{
	c1 = c1*9+0x273581d8;
	c2 = c2*5+0xee700bac;
}

// finalizer mix - avalanches all bits to within 0.25% bias

inline uint32_t fmix32 ( uint32_t h )
{
	h ^= h >> 16;
	h *= 0x85ebca6b;
	h ^= h >> 13;
	h *= 0xc2b2ae35;
	h ^= h >> 16;

	return h;
}

// 64-bit finalizer mix - avalanches all bits to within 0.05% bias

inline uint64_t fmix64 ( uint64_t k )
{
	k ^= k >> 33;
	k *= 0xff51afd7ed558ccd;
	k ^= k >> 33;
	k *= 0xc4ceb9fe1a85ec53;
	k ^= k >> 33;

	return k;
}

//-----------------------------------------------------------------------------

void MurmurHash3_x86_32 ( const void * key, int len, uint32_t seed, void * out )
{
	uint32_t h = 0x971e137b ^ seed;

	const uint8_t * tail = (const uint8_t*)(key) + (len & ~3);

	//----------
	// body

	const uint32_t * block = (const uint32_t *)tail;

	uint32_t c1 = 0x95543787;
	uint32_t c2 = 0x2ad7eb25;

	for(int l = -(len/4); l; l++)
	{
		bmix1(h,block[l],c1,c2);
		cmix(c1,c2);
	}

	//----------
	// tail

	uint32_t k = 0;

	switch(len & 3)
	{
	case 3: k ^= tail[2] << 16;
	case 2: k ^= tail[1] << 8;
	case 1: k ^= tail[0];
			bmix1(h,k,c1,c2);
	};

	//----------
	// finalization

	h ^= len;

	h = fmix32(h);

	*(uint32_t*)out = h;
} 

//-----------------------------------------------------------------------------

void merge64 ( uint32_t h[2], const uint32_t * blocks, uint32_t c1, uint32_t c2 )
{
	h[0] = _rotl(h[0],9);
	h[1] = _rotl(h[1],24);

	h[0] += h[1];
	h[1] += h[0];

	bmix1(h[0],blocks[0],c1,c2);
	bmix1(h[1],blocks[1],c1,c2);
}

//----------

void MurmurHash3_x86_64 ( const void * data, int len, uint32_t seed, void * out )
{
	uint32_t h[2];

	h[0] = 0x8de1c3ac ^ seed;
	h[1] = 0xbab98226 ^ seed;

	//----------
	// body

	const uint32_t * blocks = (const uint32_t *)data;

	uint32_t c1 = 0x95543787;
	uint32_t c2 = 0x2ad7eb25;

	while(len >= 8)
	{
		merge64(h,blocks,c1,c2);
		cmix(c1,c2);

		blocks += 2;
		len -= 8;
	}

	//----------
	// tail
	
	uint32_t k[2] = { 0, 0 };

	const uint8_t * tail = (const uint8_t*)blocks;

	switch(len)
	{
	case 7: k[1] ^= tail[6] << 16;
	case 6: k[1] ^= tail[5] << 8;
	case 5: k[1] ^= tail[4] << 0;
	case 4: k[0] ^= tail[3] << 24;
	case 3: k[0] ^= tail[2] << 16;
	case 2: k[0] ^= tail[1] << 8;
	case 1: k[0] ^= tail[0] << 0;
			merge64(h,k,c1,c2);
	};

	//----------
	// finalization

	h[1] ^= len;

	h[0] =  fmix32(h[0]);
	h[1] ^= kmix(h[0],c1,c2);
	h[0] ^= fmix32(h[1]);
	h[1] ^= kmix(h[0],c1,c2);

	((uint32_t*)out)[0] = h[0];
	((uint32_t*)out)[1] = h[1];
}

//-----------------------------------------------------------------------------

void merge128 ( uint32_t h[4], const uint32_t * blocks, uint32_t c1, uint32_t c2 )
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

	bmix1(h[0],blocks[0],c1,c2);
	bmix1(h[1],blocks[1],c1,c2);
	bmix1(h[2],blocks[2],c1,c2);
	bmix1(h[3],blocks[3],c1,c2);
}

//----------

void MurmurHash3_x86_128 ( const void * data, int len, uint32_t seed, uint32_t * out )
{
	uint32_t h[4] =
	{
		0x8de1c3ac ^ seed,
		0xbab98226 ^ seed,
		0xfcba5b2d ^ seed,
		0x32452e3e ^ seed
	};

	//----------
	// body

	const uint32_t * blocks = (const uint32_t *)data;

	uint32_t c1 = 0x95543787;
	uint32_t c2 = 0x2ad7eb25;

	while(len >= 16)
	{
		merge128(h,blocks,c1,c2);
		cmix(c1,c2);

		blocks += 4;
		len -= 16;
	}

	//----------
	// tail

	uint32_t k[4] = { 0, 0, 0, 0 };

	const uint8_t * tail = (const uint8_t*)blocks;

	switch(len)
	{
	case 15: k[3] ^= tail[14] << 16;
	case 14: k[3] ^= tail[13] << 8;
	case 13: k[3] ^= tail[12] << 0;
	case 12: k[2] ^= tail[11] << 24;
	case 11: k[2] ^= tail[10] << 16;
	case 10: k[2] ^= tail[ 9] << 8;
	case  9: k[2] ^= tail[ 8] << 0;
	case  8: k[1] ^= tail[ 7] << 24;
	case  7: k[1] ^= tail[ 6] << 16;
	case  6: k[1] ^= tail[ 5] << 8;
	case  5: k[1] ^= tail[ 4] << 0;
	case  4: k[0] ^= tail[ 3] << 24;
	case  3: k[0] ^= tail[ 2] << 16;
	case  2: k[0] ^= tail[ 1] << 8;
	case  1: k[0] ^= tail[ 0] << 0;
			merge128(h,k,c1,c2);
	};

	//----------
	// finalization

	h[3] ^= len;

	h[0] ^= fmix32(h[1]); h[2] ^= fmix32(h[3]);
	h[1] ^= kmix(h[0],c1,c2); h[3] ^= kmix(h[2],c1,c2);
	h[3] ^= fmix32(h[0]); h[1] ^= fmix32(h[2]);
	h[0] ^= kmix(h[3],c1,c2); h[2] ^= kmix(h[1],c1,c2);
	h[1] ^= fmix32(h[0]); h[3] ^= fmix32(h[2]);

	out[0] = h[0];
	out[1] = h[1];
	out[2] = h[2];
	out[3] = h[3];
}

//-----------------------------------------------------------------------------

