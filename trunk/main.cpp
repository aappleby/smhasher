#include <stdio.h>

#include <time.h>
#include "hashes.h"
#include "tests.h"

#include <windows.h>

#pragma warning(disable:4702)

//----------------------------------------------------------------------------

template < typename hashtype >
void test ( hashfunc<hashtype> hash, const char * hashname )
{
	printf("Testing %s\n",hashname);

	//const int hbytes = sizeof(hashtype);
	//const int hbits  = hbytes * 8;

	TwiddleTest(hash);
	AlignmentTest(hash);
	AppendedZeroesTest(hash);
	QuickBrownFox(hash);
	printf("\n");

	BulkSpeedTest(hash);

	TinySpeedTest<hashtype,4>(hash);
	TinySpeedTest<hashtype,5>(hash);
	TinySpeedTest<hashtype,6>(hash);
	TinySpeedTest<hashtype,7>(hash);
	TinySpeedTest<hashtype,8>(hash);
	TinySpeedTest<hashtype,256>(hash);
	printf("\n");

	// # of bytes in the cycle must be at least # of bytes in the hash output

	//CycleTest<hashtype>(hash,sizeof(hashtype)+0,8,10000000);
	//CycleTest<hashtype>(hash,sizeof(hashtype)+1,8,10000000);
	//CycleTest<hashtype>(hash,sizeof(hashtype)+2,8,10000000);
	//CycleTest<hashtype>(hash,sizeof(hashtype)+3,8,10000000);
	//CycleTest<hashtype>(hash,sizeof(hashtype)+4,8,10000000);

	printf("\n");

	/*
	DiffTest< Blob<64>,  hashtype >(hash,5,1000);
	DiffTest< Blob<128>, hashtype >(hash,4,1000);
	DiffTest< Blob<256>, hashtype >(hash,3,1000);

	printf("\n");

	AvalancheTest(hash);
	*/

	SparseKeyTest(hash,false);

	//BitrangeKeysetTest(hash,false);
	//TextKeyTest(hash.m_hash);
}

//-----------------------------------------------------------------------------

void optimize_fmix64 ( void );

void main ( void )
{
	SetProcessAffinityMask(GetCurrentProcess(),2);

	int a = clock();

	//----------

	//test<uint32_t>  ( md5_32,  "MD5, first 32 bits" );
	//test<uint32_t>  ( lookup3_test,  "Jenkins lookup3" );
	//test<uint32_t>  ( SuperFastHash,  "SuperFastHash" );
	//test<uint32_t>  ( MurmurHash2_test,  "MurmurHash2 32-bit" );
	//test<uint32_t>  ( MurmurHash2A_test,  "MurmurHash2 32-bit" );
	//test<uint32_t>  ( FNV,  "FNV 32-bit" );
	//test<uint32_t>  ( crc32,  "CRC-32" );
	//test<uint32_t>  ( DoNothingHash,  "MurmurHash3 32-bit" );

	//test<uint32_t>  ( MurmurHash3_x86_32,  "MurmurHash3 32-bit" );
	test<uint64_t>  ( MurmurHash3_x86_64,  "MurmurHash3 64-bit" );
	//test<k128> ( MurmurHash3_128, "MurmurHash3 128-bit" );

	//test<uint32_t>  ( MurmurHash3x64_32,  "MurmurHash3 32-bit" );

	int b = clock();

	printf("time %d\n",b-a);
}