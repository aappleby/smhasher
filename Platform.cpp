#include "Platform.h"

#if defined(_MSC_VER)

void SetAffinity ( int /*cpu*/ )
{
}

#else

#include <windows.h>

void SetAffinity ( int cpu )
{
	SetProcessAffinityMask(GetCurrentProcess(),cpu);
}

#endif