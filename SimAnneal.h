#pragma once

typedef double (*pfFitness) ( void * block, int len );
typedef void   (*pfDump)    ( void * block, int len );

double SimAnneal ( void * block, int len, pfFitness fit, pfDump dump, int nFlip, int reps );