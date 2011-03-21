#include "Types.h"

uint32_t MurmurOAAT ( const void * blob, int len, uint32_t seed );

//-----------------------------------------------------------------------------

#pragma optimize( "", off )

void blackhole ( uint32_t )
{
}

uint32_t whitehole ( void )
{
  return 0;
}

#pragma optimize( "", on ) 

uint32_t g_verify = 1;

void MixVCode ( const void * blob, int len )
{
	g_verify = MurmurOAAT(blob,len,g_verify);
}

//-----------------------------------------------------------------------------
