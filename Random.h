#pragma once

#include "Types.h"

//-----------------------------------------------------------------------------
// random oracle (stateless)

void oracle ( uint32_t key, uint32_t nonce, void * blob, int size );

//-----------------------------------------------------------------------------
// Xorshift-based RNG from George Marsaglia, algorithm taken from Wikipedia

struct Rand
{
	uint32_t x;
	uint32_t y;
	uint32_t z;
	uint32_t w;

	Rand()
	{
		reseed(uint32_t(0));
	}

	Rand( uint32_t seed )
	{
		reseed(seed);
	}

	uint32_t rand_u32 ( void )
	{
		uint32_t t = x ^ (x << 11);

		x = y; 
		y = z; 
		z = w;
		w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));

		return w;
	}


	void reseed ( uint32_t seed )
	{
		x = 0x498b3bc5 ^ seed;
		y = 0x9c3ed699 ^ seed;
		z = 0x5a05089a ^ seed;
		w = 0x2c8a5c59 ^ seed; 

		for(int i = 0; i < 10; i++) rand_u32();
	}

	void reseed ( uint64_t seed )
	{
		x = 0x498b3bc5 ^ (uint32_t)(seed >>  0);
		y = 0x9c3ed699 ^ (uint32_t)(seed >> 11);
		z = 0x5a05089a ^ (uint32_t)(seed >> 22);
		w = 0x2c8a5c59 ^ (uint32_t)(seed >> 32); 

		for(int i = 0; i < 10; i++) rand_u32();
	}

	//-----------------------------------------------------------------------------

	operator uint32_t ( void ) 
	{
		return rand_u32();
	}

	operator uint64_t ( void ) 
	{
		uint64_t a = rand_u32();

		a <<= 32;
		a |= rand_u32();

		return a;
	}

	void rand_p ( void * blob, int bytes )
	{
		uint32_t * blocks = (uint32_t*)blob;

		while(bytes >= 4)
		{
			*blocks++ = rand_u32();
			bytes -= 4;
		}

		uint8_t * tail = (uint8_t*)blocks;

		for(int i = 0; i < bytes; i++)
		{
			tail[i] = (uint8_t)rand_u32();
		}
	}
};

//-----------------------------------------------------------------------------

extern Rand g_rand1;

inline uint32_t rand_u32 ( void ) { return g_rand1; }
inline uint64_t rand_u64 ( void ) { return g_rand1; }

inline void rand_p ( void * blob, int bytes )
{
	uint32_t * blocks = (uint32_t*)blob;

	while(bytes >= 4)
	{
		*blocks++ = rand_u32();
		bytes -= 4;
	}

	uint8_t * tail = (uint8_t*)blocks;

	for(int i = 0; i < bytes; i++)
	{
		tail[i] = (uint8_t)rand_u32();
	}
}

//-----------------------------------------------------------------------------

template < typename T >
inline void rand_t ( T & t )
{
	rand_p(&,sizeof(t));
}

template<> inline void rand_t ( uint32_t & t ) { t = rand_u32(); }
template<> inline void rand_t ( uint64_t & t ) { t = rand_u64(); }

template<> inline void rand_t ( u128 & t )
{
	uint32_t * b  = (uint32_t*)&t;
	b[0] = rand_u32();
	b[1] = rand_u32();
	b[2] = rand_u32();
	b[3] = rand_u32();
}

//-----------------------------------------------------------------------------
