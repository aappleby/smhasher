#pragma once

#include "Types.h"
#include "Bitvec.h"
#include "Random.h"

//-----------------------------------------------------------------------------

int SolveQuadratic ( double a, double b, double c, double & r1, double & r2 );

void AccumDiffCounts ( void * a, void * b, double * counts, int len, double inc );

unsigned int multinv ( unsigned int x );

//-----------------------------------------------------------------------------
