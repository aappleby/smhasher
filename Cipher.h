#pragma once

//----------------------------------------------------------------------------

class Cipher
{
public:

	Cipher ( void ) {}
	virtual ~Cipher ( void ) {}

	virtual void encrypt ( void * key, int keySize, void * plain, void * crypt, int size ) = 0;
	virtual void decrypt ( void * key, int keySize, void * crypt, void * plain, int size ) = 0;
};

//----------------------------------------------------------------------------
