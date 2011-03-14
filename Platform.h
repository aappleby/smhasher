// Platform-specific functions and macros

void SetAffinity ( int cpu );

//-----------------------------------------------------------------------------
// Microsoft Visual Studio

#if defined(_MSC_VER)

#define FORCE_INLINE	__forceinline

#include <stdlib.h>
#include "pstdint.h"

#define ROTL32(x,y)	_rotl(x,y)
#define ROTL64(x,y)	_rotl64(x,y)

#pragma warning(disable : 4127) // "conditional expression is constant" in the if()s for avalanchetest
#pragma warning(disable : 4100)
#pragma warning(disable : 4702)

#define BIG_CONSTANT(x) (x)

//-----------------------------------------------------------------------------
// Other compilers

#else	//	defined(_MSC_VER)

#include <stdint.h>

#define	FORCE_INLINE __attribute__((always_inline))

uint32_t inline rotl32 ( uint32_t x, int8_t r )
{
	return (x << r) | (x >> (32 - r));
}

uint64_t inline rotl64 ( uint64_t x, int8_t r )
{
	return (x << r) | (x >> (64 - r));
}

#define	ROTL32(x,y)	rotl32(x,y)
#define ROTL64(x,y)	rotl64(x,y)

#define BIG_CONSTANT(x) (x##LLU)

#endif	//	!defined(_MSC_VER)
