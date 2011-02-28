#include "KeysetTest.h"

#include "Random.h"

//-----------------------------------------------------------------------------

void QuickBrownFox ( pfHash hash, const int hashbits )
{
	const int hashbytes = hashbits / 8;

	const char * text1 = "The quick brown fox jumps over the lazy dog";
	const char * text2 = "The quick brown fox jumps over the lazy cog";

	uint8_t h1[128];
	uint8_t h2[128];

	hash(text1,(int)strlen(text1),0,h1);
	hash(text2,(int)strlen(text2),0,h2);

	printf("\"%s\" => ",text1);
	printhex32(h1,hashbytes);
	printf("\n");

	printf("\"%s\" => ",text2);
	printhex32(h2,hashbytes);
	printf("\n");

	printf("\n");
}

//----------------------------------------------------------------------------
// Basic sanity checks -

// A hash function should not be reading outside the bounds of the key.

// Flipping a bit of a key should, with overwhelmingly high probability,
// result in a different hash.

// Hashing the same key twice should always produce the same result.

// The memory alignment of the key should not affect the hash result.

bool SanityTest ( pfHash hash, const int hashbits )
{	printf("Testing bit twiddling");

	bool result = true;

	const int hashbytes = hashbits/8;
	const int reps = 10;
	const int keymax = 128;
	const int pad = 16;
	const int buflen = keymax + pad*3;
	
	uint8_t * buffer1 = new uint8_t[buflen];
	uint8_t * buffer2 = new uint8_t[buflen];

	uint8_t * hash1 = new uint8_t[hashbytes];
	uint8_t * hash2 = new uint8_t[hashbytes];

	//----------
	
	for(int irep = 0; irep < reps; irep++)
	{
		if(irep % (reps/10) == 0) printf(".");

		for(int len = 4; len <= keymax; len++)
		{
			for(int offset = pad; offset < pad*2; offset++)
			{
				uint8_t * key1 = &buffer1[pad];
				uint8_t * key2 = &buffer2[pad+offset];

				rand_p(buffer1,buflen);
				rand_p(buffer2,buflen);

				memcpy(key2,key1,len);

				hash(key1,len,0,hash1);

				for(int bit = 0; bit < (len * 8); bit++)
				{
					// Flip a bit, hash the key -> we should get a different result.

					flipbit(key2,len,bit);
					hash(key2,len,0,hash2);

					if(memcmp(hash1,hash2,hashbytes) == 0)
					{
						result = false;
					}

					// Flip it back, hash again -> we should get the original result.

					flipbit(key2,len,bit);
					hash(key2,len,0,hash2);

					if(memcmp(hash1,hash2,hashbytes) != 0)
					{
						result = false;
					}
				}
			}
		}
	}

	if(result == false)
	{
		printf("*********FAIL*********\n");
	}
	else
	{
		printf("PASS\n");
	}

	delete [] hash1;
	delete [] hash2;

	return result;
}

//----------------------------------------------------------------------------
// Appending zero bytes to a key should always cause it to produce a different
// hash value

void AppendedZeroesTest ( pfHash hash, const int hashbits )
{
	const int hashbytes = hashbits/8;

	printf("Testing zero-appending");

	for(int rep = 0; rep < 100; rep++)
	{
		if(rep % 10 == 0) printf(".");

		unsigned char key[256];

		memset(key,0,sizeof(key));

		rand_p(key,32);

		uint32_t h1[16];
		uint32_t h2[16];

		memset(h1,0,hashbytes);
		memset(h2,0,hashbytes);

		for(int i = 0; i < 32; i++)
		{
			hash(key,32+i,0,h1);

			if(memcmp(h1,h2,hashbytes) == 0)
			{
				printf("\n*********FAIL*********\n");
				return;
			}

			memcpy(h2,h1,hashbytes);
		}
	}

	printf("PASS\n");
}

//-----------------------------------------------------------------------------
