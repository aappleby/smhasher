#include "Platform.h"

//-----------------------------------------------------------------------------

void MurmurHash3_x86_32  ( const void * key, int len, uint32_t seed, void * out );
void MurmurHash3_x86_64  ( const void * key, int len, uint32_t seed, void * out );
void MurmurHash3_x86_128 ( const void * key, int len, uint32_t seed, void * out );

void MurmurHash3_x64_32  ( const void * key, int len, uint32_t seed, void * out );
void MurmurHash3_x64_64  ( const void * key, int len, uint32_t seed, void * out );
void MurmurHash3_x64_128 ( const void * key, int len, uint32_t seed, void * out );

//-----------------------------------------------------------------------------

