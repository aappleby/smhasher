#include "FWTransform.h"

#include "Random.h"

// FWT1/2/3/4 are tested up to 2^16 against a brute-force implementation.

//----------------------------------------------------------------------------

double test_linear_approximation ( mixfunc<uint32_t> f, uint32_t l, uint32_t mask, int64_t size )
{
	int64_t d = 0;

	for(int64_t i = 0; i < size; i++)
	{
		uint32_t x = (uint32_t)i;
		uint32_t b1 = parity( f(x) & mask );
		uint32_t b2 = parity( x & l );

		d += (b1 ^ b2);
	}

	return double(d) / double(size);
}

//----------------------------------------------------------------------------
// In-place, non-recursive FWT transform. Reference implementation.

void FWT1 ( int * v, int64_t count )
{
	for(int64_t width = 2; width <= count; width *= 2)
	{
		int64_t blocks = count / width;

		for(int64_t i = 0; i < blocks; i++)
		{
			int64_t ia = i * width;
			int64_t ib = ia + (width/2);

			for(int64_t j = 0; j < (width/2); j++)
			{
				int a = v[ia];
				int b = v[ib];
				
				v[ia++] = a + b;
				v[ib++] = a - b;
			}
		}
	}
}

//-----------------------------------------------------------------------------
// recursive, but fall back to non-recursive for tables of 4k or smaler

// (this proved to be fastest)

void FWT2 ( int * v, int64_t count )
{
	if(count <= 4*1024) return FWT1(v,(int32_t)count);

	int64_t c = count/2;

	for(int64_t i = 0; i < c; i++) 
	{
		int a = v[i];
		int b = v[i+c];
		
		v[i] = a + b;
		v[i+c] = a - b;
	}

	if(count > 2)
	{
		FWT2(v,c);
		FWT2(v+c,c);
	}
}

//-----------------------------------------------------------------------------
// fully recursive (slow)

void FWT3 ( int * v, int64_t count )
{
	int64_t c = count/2;

	for(int64_t i = 0; i < c; i++) 
	{
		int a = v[i];
		int b = v[i+c];
		
		v[i] = a + b;
		v[i+c] = a - b;
	}

	if(count > 2)
	{
		FWT3(v,c);
		FWT3(v+c,c);
	}
}

//----------------------------------------------------------------------------
// some other method

void FWT4 ( int * data, const int64_t count )
{
	int nbits = 0;

	for(int64_t c = count; c; c >>= 1) nbits++;

	for (int i = 0; i < nbits; i++)
	{
		int64_t block = (int64_t(1) << i);
		int64_t half  = (int64_t(1) << (i-1));

		for (int64_t j = 0; j < count; j += block)
		{
			for (int k = 0; k < half; ++k)
			{
				int64_t ia = j+k;
				int64_t ib = j+k+half;

				int a = data[ia];
				int b = data[ib];

				data[ia] = a+b;
				data[ib] = a-b;
			}
		}
	}
}

//----------------------------------------------------------------------------
// Evaluate a single point in the FWT hierarchy

/*
int FWTPoint ( mixfunc<uint32_t> f, int level, int nbits, uint32_t y )
{
	if(level == 0)
	{
		return f(y);
	}
	else
	{
		uint32_t mask = 1 << (nbits - level);

		if(y & mask)
		{
			return 
		}
	}
}
*/


//----------------------------------------------------------------------------
// compute 2 tiers down into FWT, so we can break a table up into 4 chunks

int computeWalsh2 ( mixfunc<uint32_t> f, int64_t y, int bits, uint32_t mask )
{
	uint32_t size1 = 1 << (bits-1);
	uint32_t size2 = 1 << (bits-2);

	int a = parity(f((uint32_t)y        ) & mask) ? 1 : -1;
	int b = parity(f((uint32_t)y ^ size2) & mask) ? 1 : -1;

	int ab = (y & size2) ? b-a : a+b;

	int c = parity(f((uint32_t)y ^ size1        ) & mask) ? 1 : -1;
	int d = parity(f((uint32_t)y ^ size1 ^ size2) & mask) ? 1 : -1;

	int cd = (y & size2) ? d-c : c+d;

	int e = (y & size1) ? cd-ab : ab+cd;

	return e;
}

int computeWalsh2 ( int * func, int64_t y, int bits )
{
	uint32_t size1 = 1 << (bits-1);
	uint32_t size2 = 1 << (bits-2);

	int a = parity((uint32_t)func[(uint32_t)y        ]) ? 1 : -1;
	int b = parity((uint32_t)func[(uint32_t)y ^ size2]) ? 1 : -1;

	int ab = (y & size2) ? b-a : a+b;

	int c = parity((uint32_t)func[(uint32_t)y ^ size1        ]) ? 1 : -1;
	int d = parity((uint32_t)func[(uint32_t)y ^ size1 ^ size2]) ? 1 : -1;

	int cd = (y & size2) ? d-c : c+d;

	int e = (y & size1) ? cd-ab : ab+cd;

	return e;
}

//----------------------------------------------------------------------------
// this version computes the entire table at once - needs 16 gigs of RAM for
// 32-bit FWT (!!!)

void find_linear_approximation_walsh ( mixfunc<uint32_t> f, uint32_t mask, int inbits, uint32_t & outL, int64_t & outBias )
{
	// create table

	const int64_t count = int64_t(1) << inbits;

	int * table = new int[(int)count];

	// fill table

	for(int64_t i = 0; i < count; i++)
	{
		table[i] = parity(f((uint32_t)i) & mask) ? 1 : -1;
	}

	// apply walsh transform

	FWT1(table,count);

	// find maximum value in transformed table, which corresponds
	// to closest linear approximation to F

	outL = 0;
	outBias = 0;

	for(unsigned int l = 0; l < count; l++)
	{
		if(abs(table[l]) > outBias)
		{
			outBias = abs(table[l]);
			outL = l;
		}
	}

	delete [] table;
}

//-----------------------------------------------------------------------------
// this version breaks the task into 4 pieces, or 4 gigs of RAM for 32-bit FWT

void find_linear_approximation_walsh2 ( mixfunc<uint32_t> f, uint32_t mask, int inbits, uint32_t & outL, int64_t & outBias )
{
	const int64_t count = int64_t(1) << inbits;
 	const int64_t stride = count/4;

	int * table2 = new int[(int)stride];

	uint32_t worstL = 0;
	int64_t worstBias = 0;

	for(int64_t j = 0; j < count; j += stride)
	{
		printf(".");

		for(int i = 0; i < stride; i++)
		{
			table2[i] = computeWalsh2(f,i+j,inbits,mask);
		}

		FWT2(table2,stride);

		for(int64_t l = 0; l < stride; l++)
		{
			if(abs(table2[l]) > worstBias)
			{
				worstBias = abs(table2[l]);
				worstL = uint32_t(l)+uint32_t(j);
			}
		}
	}

	outBias = worstBias/2;
	outL = worstL;

	delete [] table2;
}


//----------------------------------------------------------------------------

void printtab ( int * tab, int size )
{
	for(int j = 0; j < 16; j++)
	{
		printf("[");
		for(int i = 0; i < (size/16); i++)
		{
			printf("%3d ",tab[j*16+i]);
		}
		printf("]\n");
	}
}

void comparetab ( int * tabA, int * tabB, int size )
{
	bool fail = false;

	for(int i = 0; i < size; i++)
	{
		if(tabA[i] != tabB[i])
		{
			fail = true;
			break;
		}
	}

	printf(fail ? "X" : "-");
}

void testFWT ( void )
{
	const int bits = 12;
	const int size = (1 << bits);

	int * func = new int[size];
	int * resultA = new int[size];
	int * resultB = new int[size];

	for(int rep = 0; rep < 1; rep++)
	{
		// Generate a random boolean function

		for(int i = 0; i < size; i++)
		{
			func[i] = rand_u32() & 1;

			//func[i] = (i ^ (i >> 2)) & 1;
		}

		//printf("Input boolean function -\n");
		//printtab(func);
		//printf("\n");

		// Test against all 256 linear functions


		memset(resultA,0,size * sizeof(int));

		//printf("Result - \n");
		for(uint32_t linfunc = 0; linfunc < size; linfunc++)
		{
			resultA[linfunc] = 0;

			for(uint32_t k = 0; k < size; k++)
			{
				int b1 = func[k];
				int b2 = parity( k & linfunc );

				if(b1 == b2) resultA[linfunc]++;
			}

			resultA[linfunc] -= (size/2);
		}

		//printtab(resultA);
		//printf("\n");


		// Test with FWTs

		for(int i = 0; i < size; i++) resultB[i] = (func[i] == 0) ? -1 : 1;
		FWT1(resultB,size);
		for(int i = 0; i < size; i++) resultB[i] = -resultB[i]/2;
		comparetab(resultA,resultB,size);

		for(int i = 0; i < size; i++) resultB[i] = (func[i] == 0) ? -1 : 1;
		FWT2(resultB,size);
		for(int i = 0; i < size; i++) resultB[i] = -resultB[i]/2;
		comparetab(resultA,resultB,size);

		for(int i = 0; i < size; i++) resultB[i] = (func[i] == 0) ? -1 : 1;
		FWT3(resultB,size);
		for(int i = 0; i < size; i++) resultB[i] = -resultB[i]/2;
		comparetab(resultA,resultB,size);

		// Test with subdiv-by-4

		{
			for(int i = 0; i < size; i++) resultB[i] = (func[i] == 0) ? -1 : 1;

			const int64_t count = int64_t(1) << bits;
			const int64_t stride = count/4;

			for(int64_t j = 0; j < count; j += stride)
			{
				for(int i = 0; i < stride; i++)
				{
					resultB[i+j] = computeWalsh2(func,i+j,bits);
				}

				FWT2(&resultB[j],stride);
			}

			for(int i = 0; i < size; i++) resultB[i] = -resultB[i]/2;
			comparetab(resultA,resultB,size);
		}

		printf(" ");
	}

	delete [] func;
	delete [] resultA;
	delete [] resultB;
}

//-----------------------------------------------------------------------------
// Compare known-good implementation against optimized implementation

void testFWT2 ( void )
{
	const int bits = 24;
	const int size = (1 << bits);

	int * func = new int[size];
	int * resultA = new int[size];
	int * resultB = new int[size];

	for(int rep = 0; rep < 4; rep++)
	{
		// Generate a random boolean function

		for(int i = 0; i < size; i++)
		{
			func[i] = rand_u32() & 1;
		}

		// Test with FWTs

		for(int i = 0; i < size; i++) resultA[i] = resultB[i] = (func[i] == 0) ? -1 : 1;

		FWT1(resultA,size);
		FWT4(resultB,size);
		
		comparetab(resultA,resultB,size);

		printf(" ");
	}

	delete [] func;
	delete [] resultA;
	delete [] resultB;
}