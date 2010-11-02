#include "Hamming.h"

#include "Types.h"
#include "Random.h"

// Code to measure the hamming weight of mix functions, etc.

// (documentation needed)

// If I change N bits of the input, how many bits of the output change on average?


//-----------------------------------------------------------------------------
// compute table of differential hamming weight for input differentials
// up to 5 bits

void hamtest ( uint32_t (*mix)(uint32_t), uint32_t d, const int reps, double out[33] )
{
	double temp[33];

	memset(temp,0,sizeof(temp));

	for(int i = 0; i < reps; i++)
	{
		uint32_t a = rand_u32();
		uint32_t b = a ^ d;

		uint32_t ma = mix(a);
		uint32_t mb = mix(b);

		uint32_t md = ma ^ mb;

		temp[popcount(md)] += 1.0 / double(reps);
	}

	for(int i = 0; i < 33; i++)
	{
		if(temp[i] > out[i]) out[i] = temp[i];
	}
}

void SparseDiffHamming32 ( uint32_t (*mix)(uint32_t), double accum[33] )
{
	uint32_t d = 0;

	memset(accum,0,sizeof(accum));

	//const double c32_1 = 32;
	//const double c32_2 = 496;
	//const double c32_3 = 4960;
	//const double c32_4 = 35960;
	//const double c32_5 = 201376;
	//const double c32[5] = { c32_1, c32_2, c32_3, c32_4, c32_5 };

	const int reps = 1000;

	double temp[6][33];

	for(int i = 0; i < 6; i++)
	{
		memset(temp[i],0,33 * sizeof(double));
	}

	for(int i = 0; i < 32; i++)
	{
		d ^= (1 << i);
		hamtest(mix,d,reps,temp[1]);

		for(int j = i+1; j < 32; j++)
		{
			d ^= (1 << j);
			hamtest(mix,d,reps,temp[2]);

			for(int k = j+1; k < 32; k++)
			{
				d ^= (1 << k);
				hamtest(mix,d,reps,temp[3]);

				for(int l = k+1; l < 32; l++)
				{
					d ^= (1 << l);
					hamtest(mix,d,reps,temp[4]);

					//for(int m = l+1; m < 32; m++)
					//{
					//	d ^= (1 << m);
					//	hamtest(mix,d,reps,temp[5]);
					//
					//	d ^= (1 << m);
					//}

					d ^= (1 << l);
				}
				d ^= (1 << k);
			}
			d ^= (1 << j);
		}
		d ^= (1 << i);
	}

	for(int i = 0; i < 33; i++)
	{
		accum[i] = 0;
	}

	for(int j = 0; j < 33; j++)
	{
		for(int i = 0; i < 6; i++)
		{
			if((i+j) >= 33) continue;

			double t = temp[i][j];

			if(t > accum[i+j]) accum[i+j] = t;
		}
	}

	for(int i = 0; i < 33; i++)
	{
		accum[i] *= 100;
	}
}

bool hamless ( int count, double * a, double * b )
{
	for(int i = 0; i < count; i++)
	{
		if(a[i] < b[i]) return true;
		if(a[i] > b[i]) return false;
	}

	return false;
}
