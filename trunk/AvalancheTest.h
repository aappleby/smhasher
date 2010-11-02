#pragma once

#include "Types.h"

double maxBias ( std::vector<int> & counts, int reps );
double rmsBias ( std::vector<int> & counts, int reps );

bool AvalancheTest ( pfHash hash, const int keybits, const int hashbits, const int reps );
