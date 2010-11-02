#include "Junk.h"

#include "Random.h"

//-----------------------------------------------------------------------------
// Given a 64->32 bit compression function and a set of differentials, compute
// the number of collisions

typedef uint32_t (*pfCompress32) ( uint64_t x );

int TestCompress ( pfCompress32 comp, std::vector<uint64_t> & diffs, const int reps )
{
	int total = 0;

	for(int j = 0; j < (int)diffs.size(); j++)
	{
		uint64_t d = diffs[j];

		int collisions = 0;

		for(int i = 0; i < reps; i++)
		{
			uint64_t a = rand_u64();
			uint64_t b = a ^ d;

			uint32_t ca = comp(a);
			uint32_t cb = comp(b);

			if(ca == cb) collisions++;
		}

		if(collisions > 1) total += collisions;
	}

	return total;
}

//-----------------------------------------------------------------------------
