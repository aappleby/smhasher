#include "SparseKeyTest.h"

#include "Types.h"
#include "Stats.h" // for testkeylist

//----------------------------------------------------------------------------

template < int keybits, typename hashtype >
bool SparseKeyTest3 ( hashfunc<hashtype> hash, const int setbits, bool inclusive, bool testColl, bool testDist, bool drawDiagram  )
{
	printf("Testing %d-bit keys with %s %d bits set - ",keybits, inclusive ? "up to" : "exactly", setbits);

	typedef Blob<keybits> keytype;

	std::vector<keytype> keys;

	keytype k;
	memset(&k,0,sizeof(k));

	if(inclusive) keys.push_back(k);

	SparseKeygenRecurse(0,setbits,inclusive,k,keys);

	printf("%d keys, %d bytes\n",(int)keys.size(),(int)keys.size() * sizeof(keytype));

	bool result = testkeylist<keytype,hashtype>(hash,keys,testColl,testDist,drawDiagram);

	printf("\n");

	return result;
}

//----------------------------------------------------------------------------

template< typename hashtype >
bool SparsePermuteKeyTest2 ( hashfunc<hashtype> hash, bool testColl, bool testDist, bool drawDiagram )
{
	bool result = true;

	typedef Blob<320> keytype;

	std::vector<keytype> keys;

	printf("Testing %d-bit sparse-permute keys - ",sizeof(keytype)*8);

	//----------

	keytype key;

	const int ndwords = sizeof(keytype) / 4;
	uint32_t * dwords = (uint32_t*)&key;

	for(int i = 0; i < ndwords; i++)
	{
		dwords[i] = uint32_t(1) << ((i+2) * 3);
	}

	SPKeygenRecurse2(key,0,keys);

	printf("%d keys, %d bytes\n",(int)keys.size(),(int)keys.size() * sizeof(keytype));

	//----------

	result &= testkeylist<keytype,hashtype>(hash,keys,testColl,testDist,drawDiagram);

	return result;
}

//----------------------------------------------------------------------------
// Inclusive test produces about the same distribution on poor hashes, and
// tends to create more collisions.

template < typename hashtype >
bool SparseKeyTest2 ( hashfunc<hashtype> hash, bool drawDiagram )
{
	bool result = true;

	result &= SparseKeyTest3<32,hashtype>(hash,6,true,true,true,drawDiagram);
	result &= SparseKeyTest3<40,hashtype>(hash,6,true,true,true,drawDiagram);
	result &= SparseKeyTest3<48,hashtype>(hash,5,true,true,true,drawDiagram);
	result &= SparseKeyTest3<56,hashtype>(hash,5,true,true,true,drawDiagram);

	result &= SparseKeyTest3<64,hashtype>(hash,5,true,true,true,drawDiagram);
	result &= SparseKeyTest3<96,hashtype>(hash,4,true,true,true,drawDiagram); 
	result &= SparseKeyTest3<256,hashtype>(hash,3,true,true,true,drawDiagram);
	result &= SparseKeyTest3<1536,hashtype>(hash,2,true,true,true,drawDiagram);

	// 192-bit sparse keys with 4 bits set generates 1.4 gigs of keydata - use
	// at your own risk

	// SparseKeyTest3<192,4,hashtype>(hash,true,true,true); 

	result &= SparsePermuteKeyTest2<hashtype>(hash,true,true,drawDiagram);

	return result;
}

bool SparseKeyTest ( hashfunc<uint32_t> hash, bool drawDiagram )
{
	return SparseKeyTest2<uint32_t>(hash,drawDiagram);
}

bool SparseKeyTest ( hashfunc<uint64_t> hash, bool drawDiagram )
{
	return SparseKeyTest2<uint64_t>(hash,drawDiagram);
}

bool SparseKeyTest ( hashfunc<u128> hash, bool drawDiagram )
{
	return SparseKeyTest2<u128>(hash,drawDiagram);
}
