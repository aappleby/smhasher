#pragma once

#include "Types.h"

void BulkSpeedTest ( pfHash hash );

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
