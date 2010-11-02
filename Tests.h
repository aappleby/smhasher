#pragma once

#include "Types.h"
#include "Random.h"
//#include "Stats.h"

//#include <intrin.h>

#include "AvalancheTest.h"
#include "CycleTest.h"
#include "DifferentialTest.h"

//-----------------------------------------------------------------------------

template< typename hashtype >
void QuickBrownFox ( hashfunc<hashtype> hash )
{
	const char * text1 = "The quick brown fox jumps over the lazy dog";
	const char * text2 = "The quick brown fox jumps over the lazy cog";

	hashtype h1, h2;

	hash(text1,(int)strlen(text1),0,&h1);
	hash(text2,(int)strlen(text2),0,&h2);

	printf("Quick Brown Fox -\n");
	printhex32(&h1,sizeof(hashtype)); printf("\n");
	printhex32(&h2,sizeof(hashtype)); printf("\n");
	printf("\n");
}

//-----------------------------------------------------------------------------

void BulkSpeedTest ( pfHash hash );

/*
template < typename hashtype >
void BulkSpeedTest ( hashfunc<hashtype> hash )
{
	BulkSpeedTest(hash,sizeof(hashtype) * 8);
}
*/

//----------------------------------------------------------------------------

template < typename hashtype, int keysize >
void TinySpeedTest ( pfHash hash )
{
	const int trials = 100000;

	printf("Small key speed test - %4d-byte keys - ",keysize);

	uint8_t k[keysize];
	hashtype h;

	double bestcycles = 1e9;

	for(int itrial = 0; itrial < trials; itrial++)
	{
		__int64 begin,end;

		rand_p(k,keysize);

		begin = __rdtsc();
		
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);

		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);

		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);

		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);
		hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);   hash(k,keysize,itrial,&h);

		end = __rdtsc();

		blackhole(*(uint32_t*)(&h));

		double cycles = double(end-begin) / 64;
		if(cycles < bestcycles) bestcycles = cycles;
	}

	double bestbpc = double(keysize) / bestcycles;
	printf("%8.2f cycles/hash, %8.4f bytes/cycle\n",bestcycles,bestbpc);
}

//-----------------------------------------------------------------------------

void AlignmentTest ( pfHash hash, const int hashbits );

template < typename hashtype >
void AlignmentTest ( hashfunc<hashtype> hash )
{
	AlignmentTest(hash,sizeof(hashtype) * 8);
}

//-----------------------------------------------------------------------------

void AppendedZeroesTest ( pfHash hash, const int hashbits );

template < typename hashtype >
void AppendedZeroesTest ( hashfunc<hashtype> hash )
{
	AppendedZeroesTest(hash,sizeof(hashtype) * 8);
}

//-----------------------------------------------------------------------------

bool TwiddleTest ( pfHash hash, const int hashbits );

template < typename hashtype >
bool TwiddleTest ( hashfunc<hashtype> hash )
{
	return TwiddleTest(hash,sizeof(hashtype) * 8);
}

//-----------------------------------------------------------------------------

template < typename hashtype >
bool AvalancheTest ( hashfunc<hashtype> hash )
{
	bool result = true;

	const int nbytes = sizeof(hashtype);
	const int nbits = nbytes * 8;

	for(int i = 4; i <= 10; i++)
	{
		result &= AvalancheTest(hash,8*i,nbits,2000000);
	}

	if(!result) printf("*********FAIL*********\n");


	return result;
}

//-----------------------------------------------------------------------------

template < typename hashtype >
bool SparseKeyTest2 ( hashfunc<hashtype> hash, bool drawDiagram );

template < typename hashtype >
bool SparseKeyTest ( hashfunc<hashtype> hash, bool drawDiagram )
{
	return SparseKeyTest2<hashtype>(hash,drawDiagram);
}

//-----------------------------------------------------------------------------
// For a given 20-bit window of a 64-bit key, generate all possible keys with
// bits set in that window

template < typename hashtype >
void BitrangeKeysetTest ( hashfunc<hashtype> hash, bool drawDiagram )
{
	const int keybits = 64;

	for(int j = 0; j <= (keybits-20); j++)
	{
		int minbit = j;
		int maxbit = j+20-1;

		int keycount = 1 << (maxbit - minbit + 1);

		printf("Bitrange keyset (%2d,%2d) - %d keys - ",minbit,maxbit,keycount);

		std::vector<uint64_t> keys;
		keys.reserve(keycount);

		for(int i = 0; i < keycount; i++)
		{
			uint64_t k = i;

			k = k << minbit;

			keys.push_back(k);
		}

		testkeylist<uint64_t,hashtype>(hash,keys,true,true,drawDiagram);
	}
}

//-----------------------------------------------------------------------------
