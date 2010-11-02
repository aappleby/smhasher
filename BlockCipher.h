#pragma once
#include "Cipher.h"
#include "pstdint.h"

//----------------------------------------------------------------------------

class BlockCipher : public Cipher
{
public:

	enum CipherMode
	{
		ECB,  // Electronic Codebook
		ECBN, // Electronic Codebook + Nonce
		CBC,  // Cipher block chaining
		CFB,  // Cipher feedback
		OFB,  // Output feedback
		PCBC, // Propagating CBC
		CTR,  // Counter
		MAX = CTR,
	};

	//----------

	BlockCipher ( void );
	BlockCipher ( CipherMode mode );
	virtual ~BlockCipher ( void );

	virtual void clear ( void );

	//----------
	// Subclass interface

	virtual int  getBlockSize ( void ) = 0;

	virtual void setKey  ( void * k, int keySize ) = 0;

	virtual void encrypt ( void * block, unsigned int nonce ) const = 0;
	virtual void decrypt ( void * block, unsigned int nonce ) const = 0;

	//----------
	// Client interface

	void setMode ( CipherMode m );

	virtual void encrypt ( void * key, int keySize, void * plain, void * crypt, int size );
	virtual void decrypt ( void * key, int keySize, void * crypt, void * plain, int size );

	//----------

private:

	void encrypt_ECB  ( void );
	void encrypt_ECBN ( void );
	void encrypt_CBC  ( void );
	void encrypt_CFB  ( void );
	void encrypt_OFB  ( void );
	void encrypt_PCBC ( void );
	void encrypt_CTR  ( void );

	void decrypt_ECB  ( void );
	void decrypt_ECBN ( void );
	void decrypt_CBC  ( void );
	void decrypt_CFB  ( void );
	void decrypt_OFB  ( void );
	void decrypt_PCBC ( void );
	void decrypt_CTR  ( void );

	//----------

	virtual void copy ( uint8_t * dst, const uint8_t * src );
	virtual void xor  ( uint8_t * dst, const uint8_t * a, const uint8_t * b );

	//----------

	uint8_t  m_plain[64];
	uint8_t  m_input[64];
	uint8_t  m_temp[64];
	uint8_t  m_output[64];
	uint8_t  m_crypt[64];

	int m_blockIndex;

	typedef void (BlockCipher::*pFunc)(void);

	pFunc m_pEncrypt;
	pFunc m_pDecrypt;
};

//----------------------------------------------------------------------------
