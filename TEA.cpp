#include "TEA.h"

#include <memory.h>
#include <algorithm>

// The TEA algorithm is public domain

//-----------------------------------------------------------------------------

void TEACipher::setKey ( void * key, int keySize )
{
	memset(m_key,0,16);
	memcpy(m_key,key,std::min(keySize,16));
}

//----------------------------------------------------------------------------

void TEACipher::encrypt ( void * block, unsigned int /*nonce*/ ) const
{
	unsigned int * v = (unsigned int*)block;
	unsigned int * k = (unsigned int*)m_key;

	unsigned int sum   = 0;
	unsigned int delta = 0x9E3779B9;

	for( int i = 0; i < 32; i++ )
	{
		sum += delta;
		v[0] += ((v[1]<<4) + k[0]) ^ (v[1] + sum) ^ ((v[1]>>5) + k[1]);
		v[1] += ((v[0]<<4) + k[2]) ^ (v[0] + sum) ^ ((v[0]>>5) + k[3]);
	}
}

//----------

void TEACipher::decrypt ( void * block, unsigned int /*nonce*/ ) const
{
	unsigned int * v = (unsigned int*)block;
	unsigned int * k = (unsigned int*)m_key;

	unsigned int sum   = 0xC6EF3720;
	unsigned int delta = 0x9E3779B9;

	for( int i = 0; i < 32; i++ )
	{
		v[1] -= ((v[0]<<4) + k[2]) ^ (v[0] + sum) ^ ((v[0]>>5) + k[3]);
		v[0] -= ((v[1]<<4) + k[0]) ^ (v[1] + sum) ^ ((v[1]>>5) + k[1]);
		sum -= delta;
	}
}

//----------------------------------------------------------------------------
