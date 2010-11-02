#pragma once

#include "Types.h"

#pragma warning(push)
#pragma warning(disable:4200) // user-defined type contains zero length array
#pragma warning(disable:4127) // conditional expression is constant

//-----------------------------------------------------------------------------

template < typename keytype >
void SparseKeygenRecurse ( int start, int bitsleft, bool inclusive, keytype & k, std::vector<keytype> & keys )
{
	const int nbytes = sizeof(keytype);
	const int nbits = nbytes * 8;

	for(int i = start; i < nbits; i++)
	{
		flipbit(&k,nbytes,i);

		if(inclusive || (bitsleft == 1))
		{
			keys.push_back(k);
		}

		if(bitsleft > 1)
		{
			SparseKeygenRecurse(i+1,bitsleft-1,inclusive,k,keys);
		}

		flipbit(&k,nbytes,i);
	}
}

//----------

template < typename keytype >
void SparseKeygenRecurse_R ( int start, int bitsleft, bool inclusive, keytype & k, std::vector<keytype> & keys )
{
	const int nbytes = sizeof(keytype);
	const int nbits = nbytes * 8;

	for(int i = start; i < nbits; i++)
	{
		flipbit(&k,nbytes,(bits-i-1));

		if(inclusive || (bitsleft == 1))
		{
			keys.push_back(k);
		}

		if(bitsleft > 1)
		{
			SparseKeygenRecurse(i+1,bitsleft-1,inclusive,k,keys);
		}

		flipbit(&k,nbytes,(bits-i-1));
	}
}

//----------

template< typename keytype >
void SPKeygenRecurse2 ( keytype & key, int k, std::vector<keytype> & keys )
{
	//assert(keytype::align4);

	const int ndwords = key.nbytes/4;
	uint32_t * dwords = (uint32_t*)&key;

	if(k == ndwords-1)
	{
		keys.push_back(key);
		return;
	}

	for(int i = k; i < ndwords; i++)
	{
		swap(dwords[k],dwords[i]);

		SPKeygenRecurse2(key,k+1,keys);

		swap(dwords[k],dwords[i]);
	}
}

//-----------------------------------------------------------------------------

#pragma warning(pop)
