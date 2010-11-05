#include "Hashes.h"

#include "Random.h"

//----------------------------------------------------------------------------
// fake / bad hashes

void randhash_32 ( const void *, int, uint32_t, void * out )
{
	((uint32_t*)out)[0] = rand_u32();
}

void randhash_64 ( const void *, int, uint32_t, void * out )
{
	((uint32_t*)out)[0] = rand_u32();
	((uint32_t*)out)[1] = rand_u32();
}

void randhash_128 ( const void *, int, uint32_t, void * out )
{
	((uint32_t*)out)[0] = rand_u32();
	((uint32_t*)out)[1] = rand_u32();
	((uint32_t*)out)[2] = rand_u32();
	((uint32_t*)out)[3] = rand_u32();
}

void BadHash ( const void * key, int len, uint32_t seed, void * out )
{
	uint32_t h = seed;

	const uint8_t * data = (const uint8_t*)key;

	for(int i = 0; i < len; i++)
	{
		h ^= h >> 3;
		h ^= h << 5;
		h ^= data[i];
	}

	*(uint32_t*)out = h;
}

void sumhash ( const void * key, int len, uint32_t seed, void * out )
{
	uint32_t h = seed;

	const uint8_t * data = (const uint8_t*)key;

	for(int i = 0; i < len; i++)
	{
		h += data[i];
	}

	*(uint32_t*)out = h;
}

void DoNothingHash ( const void *, int, uint32_t, void * )
{
	return;
}

//-----------------------------------------------------------------------------
// One-byte-at-a-time hash based on Murmur's mix

uint32_t MurmurOAAT ( const void * key, int len, uint32_t h )
{
	const uint8_t * data = (const uint8_t*)key;

	h ^= len;

	for(int i = 0; i < len; i++)
	{
		h ^= data[i];
		h *= 0x5bd1e995;
		h ^= h >> 16;
	}

	return h;
}

//----------------------------------------------------------------------------

void FNV ( const void * key, int len, uint32_t seed, void * out )
{
	unsigned int h = seed;

	const uint8_t * data = (const uint8_t*)key;

	h ^= 2166136261;

	for(int i = 0; i < len; i++)
	{
		h ^= data[i];
		h *= 16777619;
	}

	*(uint32_t*)out = h;
}

//-----------------------------------------------------------------------------

uint32_t x17 ( const void * key, int len, uint32_t h ) 
{
	const uint8_t * data = (const uint8_t*)key;
    
	for(int i = 0; i < len; ++i) 
	{
        h = 17 * h + (data[i] - ' ');
    }

    return h ^ (h >> 16);
}

//-----------------------------------------------------------------------------

uint32_t Bernstein ( const void * key, int len, uint32_t h ) 
{
	const uint8_t * data = (const uint8_t*)key;
    
	for(int i = 0; i < len; ++i) 
	{
        h = 33 * h + data[i];
    }

	return h;
}

//-----------------------------------------------------------------------------
