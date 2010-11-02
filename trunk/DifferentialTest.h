//-----------------------------------------------------------------------------
// Differential collision & distribution tests - generate a bunch of random keys,
// see what happens to the hash value when we flip a few bits of the key.

#pragma once
#include "Types.h"

//-----------------------------------------------------------------------------
// Check all possible keybits-choose-N differentials for collisions, report
// ones that occur significantly more often than expected.

// Random collisions can happen with probability 1 in 2^32 - if we do more than
// 2^32 tests, we'll probably see some spurious random collisions, so don't report
// them.

template < typename keytype, typename hashtype >
void DiffTest ( pfHash hash, int diffbits, int reps )
{
	const int keybits = sizeof(keytype) * 8;
	const int hashbits = sizeof(hashtype) * 8;

	double diffcount = chooseUpToK(keybits,diffbits);
	double testcount = (diffcount * double(reps));
	double expected  = testcount / 4294967296.0;

	std::vector<keytype> diffs;

	keytype k1,k2;
	hashtype h1,h2;

	printf("Testing %0.f up-to-%d-bit differentials in %d-bit keys -> %d bit hashes.\n",diffcount,diffbits,keybits,hashbits);
	printf("%d reps, %0.f total tests, expecting %2.2f random collisions",reps,testcount,expected);

	for(int i = 0; i < reps; i++)
	{
		if(i % (reps/10) == 0) printf(".");

		rand_p(&k1,sizeof(k1));
		k2 = k1;

		hash(&k1,sizeof(k1),0,(uint32_t*)&h1);

		DiffTestRecurse<keytype,hashtype>(hash,k1,k2,h1,h2,0,diffbits,diffs);
	}
	printf("\n");

	printdiffs(diffs,reps);
	printf("\n");
}

//----------

template < typename keytype, typename hashtype >
void DiffTestRecurse ( pfHash hash, keytype & k1, keytype & k2, hashtype & h1, hashtype & h2, int start, int bitsleft, std::vector<keytype> & diffs )
{
	const int bits = sizeof(keytype)*8;

	for(int i = start; i < bits; i++)
	{
		flipbit(&k2,sizeof(k2),i);
		bitsleft--;

		hash(&k2,sizeof(k2),0,&h2);

		if(h1 == h2)
		{
			diffs.push_back(k1 ^ k2);
		}

		if(bitsleft)
		{
			DiffTestRecurse(hash,k1,k2,h1,h2,i+1,bitsleft,diffs);
		}

		flipbit(&k2,sizeof(k2),i);
		bitsleft++;
	}
}

//----------

template < class keytype >
void printdiffs ( std::vector<keytype> & diffs, int reps )
{
	std::sort(diffs.begin(), diffs.end());

	int count = 1;
	int ignore = 0;

	if(diffs.size())
	{
		keytype kp = diffs[0];

		for(int i = 1; i < (int)diffs.size(); i++)
		{
			if(diffs[i] == kp)
			{
				count++;
				continue;
			}
			else
			{
				if(count > 1)
				{
					double pct = 100 * (double(count) / double(reps));
					printbits((unsigned char*)&kp,sizeof(kp));
					printf(" - %4.2f%%\n", pct );
				}
				else 
				{
					ignore++;
				}

				kp = diffs[i];
				count = 1;
			}
		}

		if(count > 1)
		{
			double pct = 100 * (double(count) / double(reps));
			printbits((unsigned char*)&kp,sizeof(kp));
			printf(" - %4.2f%%\n", pct );
		}
		else 
		{
			ignore++;
		}
	}

	printf("%d total collisions, of which %d single collisions were ignored\n",(int)diffs.size(),ignore);
}

//-----------------------------------------------------------------------------
// Differential distribution test - for each N-bit input differential, generate
// a large set of differential key pairs, hash them, and test the output 
// differentials using our distribution test code.

// This is a very hard test to pass - even if the hash values are well-distributed,
// the differences between hash values may not be. It's also not entirely relevant
// for testing hash functions, but it's still interesting.

// This test is a _lot_ of work, as it's essentially a full keyset test for
// each of a potentially huge number of input differentials. To speed things
// along, we do only a few distribution tests per keyset instead of the full
// grid.

// #TODO - put diagram drawing back on

template < typename keytype, typename hashtype >
void DiffDistTest ( pfHash hash, const int diffbits, int trials, double & worst, double & avg )
{
	std::vector<keytype>  keys(trials);
	std::vector<hashtype> A(trials),B(trials);

	for(int i = 0; i < trials; i++)
	{
		rand_t(keys[i]);

		hash(&keys[i],sizeof(keys[i]),0,(uint32_t*)&A[i]);
	}

	//----------

	std::vector<keytype> diffs;

	keytype temp(0);

	SparseKeygenRecurse<keytype>(0,diffbits,true,temp,diffs);

	//----------

	worst = 0;
	avg = 0;

	hashtype h2;

	for(size_t j = 0; j < diffs.size(); j++)
	{
		keytype & d = diffs[j];

		for(int i = 0; i < trials; i++)
		{
			keytype k2 = keys[i] ^ d;

			hash(&k2,sizeof(k2),0,&h2);

			B[i] = A[i] ^ h2;
		}

		double dworst,davg;

		TestDistributionFast(B,dworst,davg);

		avg += davg;
		worst = (dworst > worst) ? dworst : worst;
	}

	avg /= double(diffs.size());
}

//----------------------------------------------------------------------------
