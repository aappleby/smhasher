#include "Core.h"

#include <math.h>

//-----------------------------------------------------------------------------

int SolveLinear ( double a, double b, double & r )
{
	if(a == 0)
	{
		return 0;
	}

	r = -b/a;

	return 1;
}

//----------

int SolveQuadratic ( double a, double b, double c, double & r1, double & r2 )
{
	if(a == 0)
	{
		return SolveLinear(b,c,r1);
	}

	double d = (b*b) - (4*a*c);

	if(d < 0) return 0;

	double d2 = sqrt(d);

	r1 = (-b - d2) / (2.0 * a);
	r2 = (-b + d2) / (2.0 * a);

	return (r1 == r2) ? 1 : 2;
}

//----------

uint32_t multinv ( uint32_t x )
{
	uint32_t y = 1;
	uint32_t t = x;

	for(int i = 1; i < 32; i++)
	{
		uint32_t b = (1 << i);

		if(t & b)
		{
			y |= b;
			t += (x << i);
		}
	}

	return y;
};

//-----------------------------------------------------------------------------
// this is random stuff that needs to go somewhere else

uint32_t modmul ( uint32_t k, uint32_t m )
{
	uint64_t k2 = k;
	
	k2 *= m;
	k2 -= k2 >> 32;

	return (uint32_t)k2;
}

uint32_t splitmul ( uint32_t k, uint32_t m )
{
	k *= m;
	k -= k >> 16;

	return k;
}

uint32_t expand16 ( uint32_t k, uint32_t m )
{
	return modmul(k+1,m);
}

bool compare_ham16 ( uint32_t mulA, uint32_t mulB, 
                     int cutoffA, int cutoffXA, int cutoffAB,
                     int & minA, int & minB, int & minXA, int & minXB, int & minAB )
{
	const int count = 65536;

	uint32_t fA[count];
	uint32_t fB[count];

	for(int i = 0; i < count; i++)
	{
		fA[i] = expand16(i,mulA);
		fB[i] = expand16(i,mulB);
	}

	minA = 100000;
	minB = 100000;

	minXA = 100000;
	minXB = 100000;
	minAB = 100000;

	for(int j =   0; j < count-1; j++)
	for(int k = j+1; k < count;   k++)
	{
		int X = popcount(j^k);
		int A = popcount(fA[j]^fA[k]);
		int B = popcount(fB[j]^fB[k]);

		int XA = X+A;
		int XB = X+B;
		int AB = A+B;

		if(A < minA) minA = A;
		if(B < minB) minB = B;
		if(XA < minXA) minXA = XA;
		if(XB < minXB) minXB = XB;
		if(AB < minAB) minAB = AB;

		if(A < cutoffA) 
			goto dead;

		if(B < cutoffA) 
			goto dead;

		if(XA < cutoffXA) 
			goto dead;

		if(XB < cutoffXA) 
			goto dead;

		if(AB < cutoffAB) 
			goto dead;
	}

	return true;

	dead:

	return false;
}

bool test_ham16 ( uint32_t mulA, int cutoffA, int cutoffXA, int & minA, int & minXA )
{
	int minB,minXB,minAB;

	return compare_ham16(mulA,mulA, cutoffA,cutoffXA,0, minA,minB,minXA,minXB,minAB);
}

inline uint32_t foldmul ( uint32_t k, uint32_t m )
{
	uint64_t k2 = k;
	
	k2 *= m;
	k2 ^= k2 >> 32;

	return (uint32_t)k2;
}

inline uint32_t revmul ( const uint32_t v, const uint32_t m )
{
	uint32_t k1 = (uint32_t)(uint64_t(v) * m);
	uint32_t k2 = (uint32_t)((uint64_t(v) * m) >> 32);

	uint32_t k = k1-k2;

	if(k2 > k1) k++;

	return k;
}

inline uint32_t idmul ( const uint32_t v, const uint32_t m )
{
	uint32_t k1 = (uint32_t)(uint64_t(v) * m);
	uint32_t k2 = (uint32_t)((uint64_t(v) * m) >> 32);

	return k1 - k2;
}

//-----------------------------------------------------------------------------
