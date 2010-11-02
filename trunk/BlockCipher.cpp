#include "BlockCipher.h"

#include <assert.h>
#include <memory.h>

//----------------------------------------------------------------------------

BlockCipher::BlockCipher ( void )
{
	clear();

	setMode(ECB);
}

BlockCipher::BlockCipher ( CipherMode mode )
{
	clear();

	setMode(mode);
}

BlockCipher::~BlockCipher ( void )
{
}

void BlockCipher::clear ( void )
{
	memset(m_plain,  0, 64);
	memset(m_input,  0, 64);
	memset(m_temp,   0, 64);
	memset(m_output, 0, 64);
	memset(m_crypt,  0, 64);
}

//----------------------------------------------------------------------------

void BlockCipher::setMode ( CipherMode m )
{
	switch(m)
	{
		case ECB:  m_pEncrypt = &BlockCipher::encrypt_ECB;  m_pDecrypt = &BlockCipher::decrypt_ECB;  break;
		case ECBN: m_pEncrypt = &BlockCipher::encrypt_ECBN; m_pDecrypt = &BlockCipher::decrypt_ECBN; break;
		case CBC:  m_pEncrypt = &BlockCipher::encrypt_CBC;  m_pDecrypt = &BlockCipher::decrypt_CBC;  break;
		case CFB:  m_pEncrypt = &BlockCipher::encrypt_CFB;  m_pDecrypt = &BlockCipher::decrypt_CFB;  break;
		case OFB:  m_pEncrypt = &BlockCipher::encrypt_OFB;  m_pDecrypt = &BlockCipher::decrypt_OFB;  break;
		case PCBC: m_pEncrypt = &BlockCipher::encrypt_PCBC; m_pDecrypt = &BlockCipher::decrypt_PCBC; break;
		case CTR:  m_pEncrypt = &BlockCipher::encrypt_CTR;  m_pDecrypt = &BlockCipher::decrypt_CTR;  break;

		default:   assert(false); setMode(PCBC); break;
	};
}

//----------------------------------------------------------------------------

void BlockCipher::encrypt ( void * key, int keySize, void * plain, void * crypt, int size )
{
	clear();

	uint8_t * in = (uint8_t*)plain;
	uint8_t * out = (uint8_t*)crypt;

	int blockSize = getBlockSize();
	int blockCount = size / blockSize;

	setKey(key,keySize);

	for(m_blockIndex = 0; m_blockIndex < blockCount; m_blockIndex++)
	{
		copy(m_plain,in);

		(this->*m_pEncrypt)();

		copy(out,m_crypt);

		in  += blockSize;
		out += blockSize;
	}
}

void BlockCipher::decrypt ( void * key, int keySize, void * crypt, void * plain, int size )
{
	clear();

	uint8_t * in = (uint8_t*)crypt;
	uint8_t * out = (uint8_t*)plain;

	int blockSize = getBlockSize();
	int blockCount = size / blockSize;

	setKey(key,keySize);

	for(m_blockIndex = 0; m_blockIndex < blockCount; m_blockIndex++)
	{
		copy(m_crypt,in);

		(this->*m_pDecrypt)();

		copy(out,m_plain);

		in  += blockSize;
		out += blockSize;
	}
}

//----------------------------------------------------------------------------
// Electronic Codebook

void BlockCipher::encrypt_ECB ( void )
{
	copy(m_crypt,m_plain);

	encrypt(m_crypt,0);
}

//----------

void BlockCipher::decrypt_ECB ( void )
{
	copy(m_plain,m_crypt);

	decrypt(m_plain,0);
}

//----------------------------------------------------------------------------
// Electronic Codebook + Nonce

void BlockCipher::encrypt_ECBN ( void )
{
	copy(m_crypt,m_plain);

	encrypt(m_crypt,m_blockIndex);
}

//----------

void BlockCipher::decrypt_ECBN ( void )
{
	copy(m_plain,m_crypt);

	decrypt(m_plain,m_blockIndex);
}

//----------------------------------------------------------------------------
// Cipher Block Chaining

void BlockCipher::encrypt_CBC ( void )
{
	xor(m_temp,m_plain,m_input);

	encrypt(m_temp,0);

	copy(m_input,m_temp);
	copy(m_crypt,m_temp);
}

//----------

void BlockCipher::decrypt_CBC ( void )
{
	copy(m_temp,m_crypt);

	decrypt(m_temp,0);

	xor(m_plain,m_temp,m_output);
	copy(m_output,m_crypt);
}

//----------------------------------------------------------------------------
// Cipher Feedback

void BlockCipher::encrypt_CFB ( void )
{
	copy(m_temp,m_input);

	encrypt(m_temp,0);

	xor(m_crypt,m_temp,m_plain);
	copy(m_input,m_crypt);
}

//----------

void BlockCipher::decrypt_CFB ( void )
{
	copy(m_temp,m_input);

	encrypt(m_temp,0);

	xor(m_plain,m_temp,m_crypt);
	copy(m_input,m_crypt);
}

//----------------------------------------------------------------------------
// Output Feedback

void BlockCipher::encrypt_OFB ( void )
{
	copy(m_temp,m_input);

	encrypt(m_temp,0);

	xor(m_crypt,m_temp,m_plain);
	copy(m_input,m_temp);
}

//----------

void BlockCipher::decrypt_OFB( void )
{
	copy(m_temp,m_input);

	encrypt(m_temp,0);

	xor(m_plain,m_temp,m_crypt);
	copy(m_input,m_temp);
}

//----------------------------------------------------------------------------
// Propagating Cipher Block Chaining

// P = M(i)
// I = M(i-1)
// C = C(i-1)

void BlockCipher::encrypt_PCBC ( void )
{
	xor(m_temp,m_input,m_crypt);
	xor(m_temp,m_temp,m_plain);
	copy(m_input,m_plain);

	encrypt(m_temp,0);

	copy(m_crypt,m_temp);
}

//----------

// P = M(i-1)
// I = C(i-1)
// C = C(i)

void BlockCipher::decrypt_PCBC ( void )
{
	copy(m_temp,m_crypt);

	decrypt(m_temp,0);

	xor(m_plain,m_plain,m_temp);
	xor(m_plain,m_plain,m_input);

	copy(m_input,m_crypt);
}

//----------------------------------------------------------------------------
// Counter mode

void BlockCipher::encrypt_CTR ( void )
{
	*(int*)m_temp = m_blockIndex;

	encrypt(m_temp,0);

	xor(m_crypt,m_temp,m_plain);
}

//----------

void BlockCipher::decrypt_CTR ( void )
{
	*(int*)m_temp = m_blockIndex;

	encrypt(m_temp,0);

	xor(m_plain,m_temp,m_crypt);
}

//----------------------------------------------------------------------------

void BlockCipher::copy ( uint8_t * dst, const uint8_t * src )
{
	memcpy(dst,src,getBlockSize());
}

void BlockCipher::xor ( uint8_t * dst, const uint8_t * a, const uint8_t * b )
{
	int blockSize = getBlockSize();

	for(int i = 0; i < blockSize; i++)
	{
		dst[i] = a[i] ^ b[i];
	}
}

//----------------------------------------------------------------------------
