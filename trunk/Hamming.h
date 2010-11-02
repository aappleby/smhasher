#pragma once
#include "Types.h"

void SparseDiffHamming32 ( uint32_t (*mix)(uint32_t), double accum[33] );
bool hamless ( int count, double * a, double * b );