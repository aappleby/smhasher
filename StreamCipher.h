#pragma once
#include "Cipher.h"

//----------------------------------------------------------------------------

class StreamCipher : public Cipher
{
public:

	StreamCipher ( void );
	virtual ~StreamCipher ( void );

	virtual void encrypt ( void * k, int keySize, void * p, void * c, int size ) = 0;
	virtual void decrypt ( void * k, int keySize, void * c, void * p, int size ) = 0;
};

//----------------------------------------------------------------------------
