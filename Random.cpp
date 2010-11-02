#include "Random.h"

Rand g_rand1(1);
Rand g_rand2(2);
Rand g_rand3(3);
Rand g_rand4(4);

//-----------------------------------------------------------------------------
// Pseudo-random oracle. Mix avalanches x/y/z to < 0.07% bias.

inline void omix ( uint32_t & x, uint32_t & y, uint32_t & z )
{
	uint64_t m = 0x65a3d38b;
	uint64_t t = 0;

	t = x * m; y ^= t; z ^= (t >> 32);
	t = z * m; x ^= t; y ^= (t >> 32);
	t = y * m; z ^= t; x ^= (t >> 32);
	t = x * m; y ^= t; z ^= (t >> 32);
	t = z * m; x ^= t; y ^= (t >> 32);
	t = y * m; z ^= t; x ^= (t >> 32);
}

void oracle ( uint32_t key, uint32_t nonce, void * blob, int size )
{
	uint32_t x = 0x498b3bc5;
	uint32_t y = 0x9c3ed699;
	uint32_t z = 0x5a05089a;

	x ^= key;
	y ^= nonce;
	z ^= size;

	uint8_t * cursor = (uint8_t*)blob;

	while(size)
	{
		omix(x,y,z);

		if(size > 4)
		{
			*(uint32_t*)cursor = x;

			cursor += 4;
			size -= 4;
		}
		else
		{
			switch(size)
			{
			case 3: cursor[2] = (uint8_t)(x >> 16);
			case 2: cursor[1] = (uint8_t)(x >>  8);
			case 1: cursor[0] = (uint8_t)(x >>  0);
			};

			return;
		}
	}
}

//-----------------------------------------------------------------------------
