//-----------------------------------------------------------------------------
// Flipping a single bit of a key should cause an "avalanche" of changes in
// the hash function's output. Ideally, each output bits should flip 50% of
// the time - if the probability of an output bit flipping is not 50%, that bit
// is "biased". Too much bias means that patterns applied to the input will
// cause "echoes" of the patterns in the output, which in turn can cause the
// hash function to fail to create an even, random distribution of hash values.

#include "AvalancheTest.h"

#include "Bitvec.h"
#include "Random.h"

#include <math.h>

// Avalanche fails if a bit is biased by more than 1%

double gc_avalancheFail = 0.01;

//-----------------------------------------------------------------------------

void PrintAvalancheDiagram ( int x, int y, int reps, double scale, int * bins )
{
	const char * symbols = ".123456789X";

	for(int i = 0; i < y; i++)
	{
		printf("[");
		for(int j = 0; j < x; j++)
		{
			int k = (y - i) -1;

			int bin = bins[k + (j*y)];

			double b = double(bin) / double(reps);
			b = fabs(b*2 - 1);

			b *= scale;

			int s = (int)floor(b*10);

			if(s > 10) s = 10;
			if(s < 0) s = 0;

			printf("%c",symbols[s]);
		}

		printf("]\n");
	}
}

//----------------------------------------------------------------------------

double maxBias ( std::vector<int> & counts, int reps )
{
	double worst = 0;

	for(int i = 0; i < (int)counts.size(); i++)
	{
		double c = double(counts[i]) / double(reps);

		double d = fabs(c * 2 - 1);
			
		if(d > worst)
		{
			worst = d;
		}
	}

	return worst;
}

double rmsBias ( std::vector<int> & counts, int reps )
{
	double rms = 0;

	for(int i = 0; i < (int)counts.size(); i++)
	{
		double d = double(counts[i]) / reps;

		d = fabs(d * 2 - 1);

		rms += d*d;
	}

	rms /= counts.size();
	rms = sqrt(rms);

	return rms;
}

//-----------------------------------------------------------------------------

void calcBias ( pfHash hash, const int nbitsIn, const int nbitsOut, std::vector<int> & counts, int reps )
{
	const int nbytesIn = nbitsIn / 8;
	const int nbytesOut = nbitsOut / 8;

	uint8_t * K = new uint8_t[nbytesIn];
	uint8_t * A = new uint8_t[nbytesIn];
	uint8_t * B = new uint8_t[nbytesIn];

	Rand r(378473);

	for(int irep = 0; irep < reps; irep++)
	{
		r.rand_p(K,nbytesIn);

		hash(K,nbytesIn,0,A);

		int * cursor = &counts[0];

		for(int iBit = 0; iBit < nbitsIn; iBit++)
		{
			flipbit(K,nbytesIn,iBit);
			hash(K,nbytesIn,0,B);
			flipbit(K,nbytesIn,iBit);

			for(int iOut = 0; iOut < nbitsOut; iOut++)
			{
				int bitA = getbit(A,nbytesOut,iOut);
				int bitB = getbit(B,nbytesOut,iOut);

				(*cursor++) += (bitA ^ bitB);
			}
		}
	}

	delete [] K;
	delete [] A;
	delete [] B;
}

//-----------------------------------------------------------------------------

bool AvalancheTest ( pfHash hash, const int keybits, const int hashbits, const int reps )
{
	printf("Avalanche for %3d-bit keys -> %3d-bit hashes, %8d reps - ",keybits,hashbits,reps);

	std::vector<int> bins(keybits*hashbits,0);

	calcBias(hash,keybits,hashbits,bins,reps);
	
	double b = maxBias(bins,reps);

	printf("Max avalanche bias is %f\n",b);

	if(b > gc_avalancheFail)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//----------------------------------------------------------------------------
// Computing whether a given mix function produces a low bias can take many 
// millions of tests when the bias is low.  This code tries to speed up the 
// process by early-outing if the probability that the bias will fall outside
// the given range is over 99%

/*
bool testMixAvalanche32_Fast ( pfMix32 mix, double cutmin, double cutmax, bool winlose )
{
	int counts[32*32];

	memset(counts,0,sizeof(counts));

	double pmin = 0;
	double pmax = 0;
	double n = 0;
	double s = 4.75;
	int w = 0;

	int batchsize = 512;

	for(int iBatch = 0; iBatch < 1024 * 1024; iBatch++)
	{
		calcMixBias<uint32_t>(mix,counts,batchsize);

		n = (iBatch+1) * batchsize;
		w = maxIntBias(32,32,counts,(int)n);

		// compute p such that w is at the bottom of the confidence interval

		double a = s*s*n + n*n;
		double b = -2.0*double(w)*n - s*s*n;
		double c = double(w)*double(w);

		SolveQuadratic(a,b,c,pmin,pmax);

		double win = 0;
		double tie = 0;
		double lose = 0;

		if(winlose)
		{
			if(pmax < cutmax)
			{
				printf("\n+!!! %f - %f : %f - %d\n",double(w)/n,pmin,pmax,int(n));
				return true;
			}

			if(pmin > cutmax)
			{
				//printf("\n-!!! %f - %f : %f - %d\n",double(w)/n,pmin,pmax,int(n));
				return false;
			}

			// doesn't fail or win outright. does it have a chance of winning?

			if(pmin < cutmin)
			{
				// pmin:pmax contains cutmin:cutmax

				assert(cutmin > pmin);
				assert(cutmax < pmax);

				win = (cutmin-pmin) / (pmax-pmin);
				tie = (cutmax-cutmin) / (pmax-pmin);
				lose = (pmax-cutmax) / (pmax-pmin);
			}
			else
			{
				// pmin:pmax overlaps above cutmin:cutmax

				assert(cutmin < pmin);

				win = 0;
				tie = ((cutmax - pmin) / (pmax-pmin)) * ((cutmax-pmin) / (cutmax-cutmin));
				lose = (pmax-cutmax) / (pmax-pmin);

				return false;
			}

			double frac = win + tie*0.5;

			if((pmax-pmin)/(cutmax-cutmin) < 5)
			{
				if(frac < 0.20)
				{
					// 99% chance of loss
					//printf("\n--- %f - %f : %f - %d\n",double(w)/n,pmin,pmax,int(n));
					return false;
				}

				if(frac > 0.80)
				{
					// 99% chance of win
					printf("\n+++ %f - %f : %f - %d\n",double(w)/n,pmin,pmax,int(n));
					return true;
				}
			}
		}

		if(!winlose && (n > 0) && ((int)n % (128 * 1024) == 0))
		{
			printf("%f - %f : %f - %d - %f : %f : %f\n",double(w)/n,pmin,pmax,int(n),win,tie,lose);
		}

	}

	// We failed to determine whether this mix function passes or fails

	printf("\n??? %f - %f : %f",double(w)/n,pmin,pmax);

	return true;
}
*/

//-----------------------------------------------------------------------------
