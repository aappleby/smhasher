#include "Types.h"
#include "Bitvec.h"

// Fast Walsh transform stuff. Used for determining how close an arbitrary
// boolean function is to the set of all possible linear functions.

// Given an arbitrary N-bit mixing function mix(x), we can generate a boolean
// function out of it by choosing a N-bit mask and computing
// parity(mix(x) & mask).

// If the mask has 1 bit set, this is equivalent to selecting a column of
// output bits from the mixing function to test.
