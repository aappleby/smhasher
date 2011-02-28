#pragma once

#include "Types.h"

void BulkSpeedTest ( pfHash hash );
void TinySpeedTest ( pfHash hash, int hashsize, int keysize, bool verbose, double & outCycles );

//-----------------------------------------------------------------------------
