#pragma once

#include "Types.h"

#include "MurmurHash1.h"
#include "MurmurHash2.h"
#include "MurmurHash3.h"

void DoNothingHash         ( const void * key, int len, uint32_t seed, void * out );
void FNV                   ( const void * key, int len, uint32_t seed, void * out );
void SuperFastHash         ( const void * key, int len, uint32_t seed, void * out );
void lookup3_test          ( const void * key, int len, uint32_t seed, void * out );
void md5_32                ( const void * key, int len, uint32_t seed, void * out );
void crc32                 ( const void * key, int len, uint32_t seed, void * out );

void MurmurHash2_test      ( const void * key, int len, uint32_t seed, void * out );
void MurmurHash2A_test     ( const void * key, int len, uint32_t seed, void * out );

//-----------------------------------------------------------------------------

inline void MurmurHash1_test ( const void * key, int len, uint32_t seed, void * out )
{
	*(uint32_t*)out = MurmurHash1(key,len,seed);
}

inline void MurmurHash2_test ( const void * key, int len, uint32_t seed, void * out )
{
	*(uint32_t*)out = MurmurHash2(key,len,seed);
}

inline void MurmurHash2A_test ( const void * key, int len, uint32_t seed, void * out )
{
	*(uint32_t*)out = MurmurHash2A(key,len,seed);
}

