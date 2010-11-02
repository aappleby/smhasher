#include "XTEA.h"

#include <algorithm>

static const int g_rounds = 64;

// The XTEA and BTEA algorithms are public domain

//----------------------------------------------------------------------------

void XTEACipher::setKey ( void * key, int keySize )
{
	memset(m_key,0,16);
	memcpy(m_key,key,std::min(keySize,16));
}

//----------------------------------------------------------------------------

void XTEACipher::encrypt ( void * block, unsigned int nonce ) const
{
	uint32_t * v = (uint32_t*)block;
	uint32_t * k = (uint32_t*)m_key;

	uint32_t delta = 0x9E3779B9;
	uint32_t sum = 0;

	v[0] ^= nonce;

	for(int i = 0; i < g_rounds; i++)
	{
		v[0] += (((v[1] << 4) ^ (v[1] >> 5)) + v[1]) ^ (sum + k[sum & 3]);
	    
		sum += delta;
	    
		v[1] += (((v[0] << 4) ^ (v[0] >> 5)) + v[0]) ^ (sum + k[(sum>>11) & 3]);
	}
}

//----------

void XTEACipher::decrypt ( void * block, unsigned int nonce ) const
{
	uint32_t * v = (uint32_t*)block;
	uint32_t * k = (uint32_t*)m_key;

	uint32_t delta = 0x9E3779B9;
	uint32_t sum = delta * g_rounds;

	for(int i = 0; i < g_rounds; i++)
	{
		v[1] -= (((v[0] << 4) ^ (v[0] >> 5)) + v[0]) ^ (sum + k[(sum>>11) & 3]);
	    
		sum -= delta;
	    
		v[0] -= (((v[1] << 4) ^ (v[1] >> 5)) + v[1]) ^ (sum + k[sum & 3]);
	}

	v[0] ^= nonce;
}

//----------------------------------------------------------------------------

#define DELTA 0x9e3779b9
#define MX ((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (k[(p&3)^e] ^ z));

void btea ( unsigned int *v, int n, unsigned int const k[4]) 
{
	const int rounds = 6 + (52/n);
	unsigned int sum = 0;

	unsigned int y = 0;
	unsigned int z = v[n-1];

	for(int round = 0; round < rounds; round++)
	{
		sum += DELTA;
		unsigned int e = (sum >> 2) & 3;

		int p;

		for( p=0; p < n-1; p++ )
		{
			y = v[p+1];
			z = v[p] += MX;
		}
		
		y = v[0];
		z = v[n-1] += MX;
	} 
}

void btea_decrypt ( unsigned int *v, int n, unsigned int const k[4]) 
{
	const int rounds = 6 + (52/n);
	unsigned int sum = rounds*DELTA;

	unsigned int y = v[0];
	unsigned int z = 0;

	for(int round = 0; round < rounds; round++)
	{
		unsigned int e = (sum >> 2) & 3;
		
		int p;

		for( p = n-1; p > 0; p-- )
		{
			z = v[p-1];
			y = v[p] -= MX;
		}
		
		z = v[n-1];
		y = v[0] -= MX;

		sum -= DELTA;
	} 
}

//----------------------------------------------------------------------------
