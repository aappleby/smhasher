#include "pstdint.h"

uint32_t MurmurHash1        ( const void * key, int len, uint32_t seed );
uint32_t MurmurHash2        ( const void * key, int len, uint32_t seed );
uint64_t MurmurHash64A      ( const void * key, int len, uint64_t seed );
uint64_t MurmurHash64B      ( const void * key, int len, uint64_t seed );
uint32_t MurmurHash2A       ( const void * key, int len, uint32_t seed );
uint32_t MurmurHashNeutral2 ( const void * key, int len, uint32_t seed );
uint32_t MurmurHashAligned2 ( const void * key, int len, uint32_t seed );


void MurmurHash1_test ( const void * key, int len, uint32_t seed, void * out )
{
	*(uint32_t*)out = MurmurHash1(key,len,seed);
}

void MurmurHash2_test ( const void * key, int len, uint32_t seed, void * out )
{
	*(uint32_t*)out = MurmurHash2(key,len,seed);
}

void MurmurHash2A_test ( const void * key, int len, uint32_t seed, void * out )
{
	*(uint32_t*)out = MurmurHash2A(key,len,seed);
}

