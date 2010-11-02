#pragma once

#include "pstdint.h"
#include "Bitvec.h"
#include <vector>
#include <assert.h>

void     blackhole ( uint32_t x );
uint32_t whitehole ( void );

typedef void (*pfHash) ( const void * blob, int len, uint32_t seed, void * out );

template < typename T >
void swap ( T & a, T & b )
{
	T t = a;
	a = b;
	b = t;
}

//-----------------------------------------------------------------------------

template < class T >
class hashfunc
{
public:

	hashfunc ( pfHash h ) : m_hash(h)
	{
	}

	inline void operator () ( const void * key, int len, uint32_t seed, uint32_t * out )
	{
		m_hash(key,len,seed,out);
	}

	inline operator pfHash ( void ) const
	{
		return m_hash;
	}

	inline T operator () ( const void * key, int len, uint32_t seed ) 
	{
		T result;

		m_hash(key,len,seed,(uint32_t*)&result);

		return result;
	}

	/*
	T operator () ( T const & key )
	{
		T result;

		m_hash(&key,sizeof(T),0,&result);

		return result;
	}
	*/

	pfHash m_hash;
};

//-----------------------------------------------------------------------------

template < class T >
class mixfunc
{
public:

	typedef T (*pfMix) ( T key );

	mixfunc ( pfMix m ) : m_mix(m)
	{
	}

	T operator () ( T key )
	{
		return m_mix(key);
	}

	pfMix m_mix;
};

//-----------------------------------------------------------------------------

template < int _bits >
class Blob
{
public:

	Blob()
	{
	}

	Blob ( int x )
	{
		for(int i = 0; i < nbytes; i++)
		{
			bytes[i] = 0;
		}

		*(int*)bytes = x;
	}

	Blob ( const Blob & k )
	{
		for(int i = 0; i < nbytes; i++)
		{
			bytes[i] = k.bytes[i];
		}
	}

	Blob & operator = ( const Blob & k )
	{
		for(int i = 0; i < nbytes; i++)
		{
			bytes[i] = k.bytes[i];
		}

		return *this;
	}

	void set ( const void * blob, int len )
	{
		const uint8_t * k = (const uint8_t*)blob;

		len = len > nbytes ? nbytes : len;

		for(int i = 0; i < len; i++)
		{
			bytes[i] = k[i];
		}

		for(int i = len; i < nbytes; i++)
		{
			bytes[i] = 0;
		}
	}

	uint8_t & operator [] ( int i )
	{
		return bytes[i];
	}

	const uint8_t & operator [] ( int i ) const
	{
		return bytes[i];
	}

	//----------
	// boolean operations
	
	bool operator < ( const Blob & k ) const
	{
		for(int i = 0; i < nbytes; i++)
		{
			if(bytes[i] < k.bytes[i]) return true;
			if(bytes[i] > k.bytes[i]) return false;
		}

		return false;
	}

	bool operator == ( const Blob & k ) const
	{
		for(int i = 0; i < nbytes; i++)
		{
			if(bytes[i] != k.bytes[i]) return false;
		}

		return true;
	}

	bool operator != ( const Blob & k ) const
	{
		return !(*this == k);
	}

	//----------
	// bitwise operations

	Blob operator ^ ( const Blob & k ) const 
	{
		Blob t;

		for(int i = 0; i < nbytes; i++)
		{
			t.bytes[i] = bytes[i] ^ k.bytes[i];
		}

		return t;
	}

	Blob & operator ^= ( const Blob & k )
	{
		for(int i = 0; i < nbytes; i++)
		{
			bytes[i] ^= k.bytes[i];
		}

		return *this;
	}

	int operator & ( int x )
	{
		return (*(int*)bytes) & x;
	}

	Blob & operator &= ( const Blob & k )
	{
		for(int i = 0; i < nbytes; i++)
		{
			bytes[i] &= k.bytes[i];
		}
	}

	Blob operator << ( int c )
	{
		Blob t = *this;

		lshift(t.bytes,nbytes,c);

		return t;
	}

	Blob operator >> ( int c )
	{
		Blob t = *this;

		rshift(t.bytes,nbytes,c);

		return t;
	}

	Blob & operator <<= ( int c )
	{
		lshift(bytes,nbytes,c);

		return *this;
	}

	Blob & operator >>= ( int c )
	{
		rshift(bytes,nbytes,c);

		return *this;
	}

	//----------
	
	enum
	{
		nbits = _bits,
		nbytes = (_bits+7)/8,

		align4  = (nbytes & 2) ? 0 : 1,
		align8  = (nbytes & 3) ? 0 : 1,
		align16 = (nbytes & 4) ? 0 : 1,
	};

private:

	uint8_t bytes[nbytes];
};

typedef Blob<128> u128;

//-----------------------------------------------------------------------------

class VBlob : public std::vector<uint8_t>
{
public:

	VBlob( int len ) : std::vector<uint8_t>(len,0)
	{
	}

	/*
	VBlob ( const VBlob & k )
	{
		for(size_t i = 0; i < size(); i++)
		{
			at(i) = k.at(i);
		}
	}
	*/

	/*
	VBlob & operator = ( const VBlob & k )
	{
		for(size_t i = 0; i < size(); i++)
		{
			at(i) = k.at(i);
		}

		return *this;
	}
	*/

	void set ( const void * VBlob, int len )
	{
		assert(size() == (size_t)len);

		const uint8_t * k = (const uint8_t*)VBlob;

		len = len > (int)size() ? (int)size() : len;

		for(int i = 0; i < len; i++)
		{
			at(i) = k[i];
		}

		for(size_t i = len; i < size(); i++)
		{
			at(i) = 0;
		}
	}

	//----------
	// boolean operations
	
	bool operator < ( const VBlob & k ) const
	{
		assert(size() == k.size());

		for(size_t i = 0; i < size(); i++)
		{
			if(at(i) < k.at(i)) return true;
			if(at(i) > k.at(i)) return false;
		}

		return false;
	}

	bool operator == ( const VBlob & k ) const
	{
		assert(size() == k.size());

		for(size_t i = 0; i < size(); i++)
		{
			if(at(i) != k.at(i)) return false;
		}

		return true;
	}

	bool operator != ( const VBlob & k ) const
	{
		assert(size() == k.size());

		return !(*this == k);
	}

	//----------
	// bitwise operations

	VBlob operator ^ ( const VBlob & k ) const 
	{
		assert(size() == k.size());

		VBlob t((int)k.size());

		for(size_t i = 0; i < size(); i++)
		{
			t.at(i) = at(i) ^ k.at(i);
		}

		return t;
	}

	VBlob & operator ^= ( const VBlob & k )
	{
		assert(size() == k.size());

		for(size_t i = 0; i < size(); i++)
		{
			at(i) ^= k.at(i);
		}

		return *this;
	}

	VBlob & operator &= ( const VBlob & k )
	{
		assert(size() == k.size());

		for(size_t i = 0; i < size(); i++)
		{
			at(i) &= k.at(i);
		}
	}

	VBlob & operator <<= ( int c )
	{
		lshift(&at(0),(int)size(),c);

		return *this;
	}

	VBlob & operator >>= ( int c )
	{
		rshift(&at(0),(int)size(),c);

		return *this;
	}
};

//-----------------------------------------------------------------------------

/*
class Blobvec
{
public:

	Blobvec ( int stride, int size )
	{
		m_data = new uint8_t[stride*size];
	}

	~Blobvec ( void )
	{
		delete [] m_data;
	}

	int size ( void ) const
	{
		return m_size;
	}

	const void * operator [] ( const int index ) const
	{
		return &m_data[index * m_stride];
	}

	void * operator [] ( const int index )
	{
		return &m_data[index * m_stride];
	}

	int m_stride;
	int m_size;

	uint8_t * m_data;
};
*/

//-----------------------------------------------------------------------------
