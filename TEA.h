#pragma once

#include "BlockCipher.h"

//----------------------------------------------------------------------------

class TEACipher : public BlockCipher
{
public:

	int getBlockSize ( void ) { return 8; }

	void setKey  ( void * key, int keySize );

	void encrypt ( void * block, unsigned int nonce ) const;
	void decrypt ( void * block, unsigned int nonce ) const;

protected:

	uint32_t m_key[4];
};

//----------------------------------------------------------------------------
