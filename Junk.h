#include "Types.h"

//-----------------------------------------------------------------------------

template < typename mixtype >
void calcMixBias ( mixtype (*mix)(mixtype), std::vector<int>& bins, int reps )
{
	const int inbits  = sizeof(mixtype) * 8;
	const int outbits = sizeof(mixtype) * 8;

	mixtype K,A,B,C;

	for(int irep = 0; irep < reps; irep++)
	{
		rand_t(K);

		A = mix(K);

		for(int iBit = 0; iBit < inbits; iBit++)
		{
			B = mix(K ^ (mixtype(1) << iBit));

			C = A ^ B;

			for(int iOut = 0; iOut < outbits; iOut++)
			{
				bins[(iBit*outbits) + iOut] += (C >> iOut) & 1;
			}
		}
	}
}

//----------

template < typename mixtype >
double calcMixBias ( mixtype (*mix)(mixtype), int reps )
{
	const int bits = sizeof(mixtype) * 8;
	std::vector<int> bins(bits*bits);

	calcMixBias<mixtype>(mix,bins,reps);

	return maxBias(bins,reps);
}

//-----------------------------------------------------------------------------
