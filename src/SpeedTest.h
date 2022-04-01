#pragma once

#include "Types.h"

void BulkSpeedTest ( pfHash hash, uint32_t seed , int size = 0);
void TinySpeedTest ( pfHash hash, int hashsize, int keysize, uint32_t seed, bool verbose, double & outCycles );

//-----------------------------------------------------------------------------
