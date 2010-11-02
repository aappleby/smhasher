#include "Types.h"

// Throw a value in the oubliette to prevent the compiler from optimizing away
// the code that calculated it

#pragma optimize( "", off )

void blackhole ( uint32_t )
{
}

uint32_t whitehole ( void )
{
	return 0;
}

#pragma optimize( "", on ) 
