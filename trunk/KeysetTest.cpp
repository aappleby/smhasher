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
// Alignment of the keys should not affect the hash value - if it does,
// something is broken.

void AlignmentTest ( pfHash hash, const int hashbits )
{
	const int hashbytes = hashbits / 8;

	printf("Testing alignment handling..........");

	char testblob[512];
	rand_p(testblob,512);

	char * bufs[16];
	char * strings[16];

	for(int i = 0; i < 16; i++)
	{
		bufs[i] = new char[1024];
		uint32_t b = uint32_t(bufs[i]);

		b = (b+15)&(~15);

		strings[i] = (char*)(b + i);
		
		memcpy(strings[i],testblob,512);
	}

	bool result = true;

	uint32_t hash1[64];
	uint32_t hash2[64];

	for(int k = 1; k <= 512; k++)
	for(int j = 0; j < 15; j++)
	for(int i = j+1; i < 16; i++)
	{
		const char * s1 = strings[i];
		const char * s2 = strings[j];

		hash(s1,k,0,hash1);
		hash(s2,k,0,hash2);

		if(memcmp(hash1,hash2,hashbytes) != 0)
		{
			result = false;
		}
	}

	if(!result)
	{
		printf("*********FAIL*********\n");
	}
	else
	{
		printf("PASS\n");
	}

	for(int i = 0; i < 16; i++) delete [] bufs[i];
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

//----------------------------------------------------------------------------
// Basic sanity checks -

// A hash function should not be reading outside the bounds of the key.

// Flipping a bit of a key should, with overwhelmingly high probability,
// result in a different hash.

// Hashing the same key twice should always produce the same result.

bool SanityTest ( pfHash hash, const int hashbits )
{
	bool result = true;

	const int hashbytes = hashbits/8;
	const int reps = 100;

	printf("Testing bit twiddling");

	uint8_t buffer[256];
	uint8_t * key = &buffer[64];

	uint8_t * h1 = new uint8_t[hashbytes];
	uint8_t * h2 = new uint8_t[hashbytes];

	for(int irep = 0; irep < reps; irep++)
	{
		if(irep % (reps/10) == 0) printf(".");

		for(int len = 1; len <= 128; len++)
		{
			// Generate a random key in the middle of the buffer, hash it,
			// and then fill the space around the key with garbage. If a
			// broken hash function reads past the ends of the key, it should
			// fail the "did we get the same hash?" test below.

			rand_p(key,len);
			hash(key,len,0,h1);

			rand_p(buffer,64);
			rand_p(key+len,64);

			// Flip a bit, hash the key -> we should get a different result.
			// Flip it back, hash again -> we should get the same result.

			for(int bit = 0; bit < (len * 8); bit++)
			{
				flipbit(key,len,bit);
				hash(key,len,0,h2);

				if(memcmp(h1,h2,hashbytes) == 0)
				{
					result = false;
				}

				flipbit(key,len,bit);
				hash(key,len,0,h2);

				if(memcmp(h1,h2,hashbytes) != 0)
				{
					result = false;
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

	delete [] h1;
	delete [] h2;

	return result;
}

//-----------------------------------------------------------------------------
