#pragma once

#include "Types.h"

template < typename hashtype >
bool CycleTest ( pfHash hash, int cycleLen, int cycleReps, const int reps )
{
	printf("Keyset 'Cycles' (%dk keys, %d cycles, %d bytes)",reps / 1000,cycleReps,cycleLen);

	bool result = true;

	std::vector<hashtype> hashes;
	hashes.resize(reps);

	int keyLen = cycleLen * cycleReps;

	uint8_t * cycle = new uint8_t[cycleLen + 16];
	uint8_t * key = new uint8_t[keyLen];

	for(int i = 0; i < reps; i++)
	{
		if(i % (reps/10) == 0) printf(".");

		oracle(i,0,cycle,cycleLen);

		*(uint32_t*)cycle = f3mix(i ^ 0x746a94f1);

		for(int j = 0; j < keyLen; j++)
		{
			key[j] = cycle[j % cycleLen];
		}

		hash(key,keyLen,0,&hashes[i]);
	}
	printf("\n");

	testhashlist(hashes,true,false);

	delete [] cycle;
	delete [] key;

	return result;
}


