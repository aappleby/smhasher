
```
-------------------------------------------------------------------------------
--- Testing Murmur3C (MurmurHash3 for x86, 128-bit)

[[[ Sanity Tests ]]]

Verification value 0x13C7ED69 : Passed!
Running sanity check 1..........PASS
Running sanity check 2..........PASS

[[[ Speed Tests ]]]

Bulk speed test - 262144-byte keys
Alignment  0 -  1.432 bytes/cycle - 4096.26 MiB/sec @ 3 ghz
Alignment  1 -  1.411 bytes/cycle - 4037.47 MiB/sec @ 3 ghz
Alignment  2 -  1.411 bytes/cycle - 4037.66 MiB/sec @ 3 ghz
Alignment  3 -  1.411 bytes/cycle - 4037.27 MiB/sec @ 3 ghz
Alignment  4 -  1.435 bytes/cycle - 4106.64 MiB/sec @ 3 ghz
Alignment  5 -  1.406 bytes/cycle - 4022.20 MiB/sec @ 3 ghz
Alignment  6 -  1.406 bytes/cycle - 4022.31 MiB/sec @ 3 ghz
Alignment  7 -  1.406 bytes/cycle - 4022.05 MiB/sec @ 3 ghz

Small key speed test -    1-byte keys -    40.94 cycles/hash,   0.0244 bytes/cycle
Small key speed test -    2-byte keys -    44.61 cycles/hash,   0.0448 bytes/cycle
Small key speed test -    3-byte keys -    45.67 cycles/hash,   0.0657 bytes/cycle
Small key speed test -    4-byte keys -    47.95 cycles/hash,   0.0834 bytes/cycle
Small key speed test -    5-byte keys -    49.30 cycles/hash,   0.1014 bytes/cycle
Small key speed test -    6-byte keys -    50.67 cycles/hash,   0.1184 bytes/cycle
Small key speed test -    7-byte keys -    51.25 cycles/hash,   0.1366 bytes/cycle
Small key speed test -    8-byte keys -    51.30 cycles/hash,   0.1560 bytes/cycle
Small key speed test -    9-byte keys -    52.69 cycles/hash,   0.1708 bytes/cycle
Small key speed test -   10-byte keys -    54.33 cycles/hash,   0.1841 bytes/cycle
Small key speed test -   11-byte keys -    56.66 cycles/hash,   0.1942 bytes/cycle
Small key speed test -   12-byte keys -    53.97 cycles/hash,   0.2224 bytes/cycle
Small key speed test -   13-byte keys -    57.38 cycles/hash,   0.2266 bytes/cycle
Small key speed test -   14-byte keys -    57.55 cycles/hash,   0.2433 bytes/cycle
Small key speed test -   15-byte keys -    57.98 cycles/hash,   0.2587 bytes/cycle
Small key speed test -   16-byte keys -    53.36 cycles/hash,   0.2999 bytes/cycle
Small key speed test -   17-byte keys -    56.39 cycles/hash,   0.3015 bytes/cycle
Small key speed test -   18-byte keys -    58.58 cycles/hash,   0.3073 bytes/cycle
Small key speed test -   19-byte keys -    58.00 cycles/hash,   0.3276 bytes/cycle
Small key speed test -   20-byte keys -    59.25 cycles/hash,   0.3376 bytes/cycle
Small key speed test -   21-byte keys -    61.70 cycles/hash,   0.3403 bytes/cycle
Small key speed test -   22-byte keys -    60.48 cycles/hash,   0.3637 bytes/cycle
Small key speed test -   23-byte keys -    62.67 cycles/hash,   0.3670 bytes/cycle
Small key speed test -   24-byte keys -    62.45 cycles/hash,   0.3843 bytes/cycle
Small key speed test -   25-byte keys -    64.73 cycles/hash,   0.3862 bytes/cycle
Small key speed test -   26-byte keys -    65.72 cycles/hash,   0.3956 bytes/cycle
Small key speed test -   27-byte keys -    66.03 cycles/hash,   0.4089 bytes/cycle
Small key speed test -   28-byte keys -    66.61 cycles/hash,   0.4204 bytes/cycle
Small key speed test -   29-byte keys -    70.72 cycles/hash,   0.4101 bytes/cycle
Small key speed test -   30-byte keys -    71.44 cycles/hash,   0.4199 bytes/cycle
Small key speed test -   31-byte keys -    71.03 cycles/hash,   0.4364 bytes/cycle

[[[ Differential Tests ]]]

Testing 8303632 up-to-5-bit differentials in 64-bit keys -> 128 bit hashes.
1000 reps, 8303632000 total tests, expecting 0.00 random collisions..........
0 total collisions, of which 0 single collisions were ignored

Testing 11017632 up-to-4-bit differentials in 128-bit keys -> 128 bit hashes.
1000 reps, 11017632000 total tests, expecting 0.00 random collisions..........
0 total collisions, of which 0 single collisions were ignored

Testing 2796416 up-to-3-bit differentials in 256-bit keys -> 128 bit hashes.
1000 reps, 2796416000 total tests, expecting 0.00 random collisions..........
0 total collisions, of which 0 single collisions were ignored


[[[ Avalanche Tests ]]]

Testing  32-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.632000%
Testing  40-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.729333%
Testing  48-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.758000%
Testing  56-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.708000%
Testing  64-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.658000%
Testing  72-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.780000%
Testing  80-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.688667%
Testing  88-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.732667%
Testing  96-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.721333%
Testing 104-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.742000%
Testing 112-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.706000%
Testing 120-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.734667%
Testing 128-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.696667%
Testing 136-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.793333%
Testing 144-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.762667%
Testing 152-bit keys -> 128-bit hashes,   300000 reps.......... worst bias is 0.734000%

[[[ Keyset 'Cyclic' Tests ]]]

Keyset 'Cyclic' - 8 cycles of 16 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  32 - 0.038%

Keyset 'Cyclic' - 8 cycles of 17 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  72 - 0.040%

Keyset 'Cyclic' - 8 cycles of 18 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  59 - 0.028%

Keyset 'Cyclic' - 8 cycles of 19 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  73 - 0.038%

Keyset 'Cyclic' - 8 cycles of 20 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  66 - 0.030%


[[[ Keyset 'TwoBytes' Tests ]]]

Keyset 'TwoBytes' - up-to-4-byte keys, 652545 total keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  16-bit window at bit  82 - 0.130%

Keyset 'TwoBytes' - up-to-8-byte keys, 5471025 total keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  46 - 0.049%

Keyset 'TwoBytes' - up-to-12-byte keys, 18616785 total keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  22 - 0.033%

Keyset 'TwoBytes' - up-to-16-byte keys, 44251425 total keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  21 - 0.007%

Keyset 'TwoBytes' - up-to-20-byte keys, 86536545 total keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  22 - 0.004%


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 32-bit keys with up to 6 bits set - 1149017 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit  41 - 0.111%

Keyset 'Sparse' - 40-bit keys with up to 6 bits set - 4598479 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit   0 - 0.070%

Keyset 'Sparse' - 48-bit keys with up to 5 bits set - 1925357 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit 112 - 0.106%

Keyset 'Sparse' - 56-bit keys with up to 5 bits set - 4216423 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit   8 - 0.052%

Keyset 'Sparse' - 64-bit keys with up to 5 bits set - 8303633 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  64 - 0.042%

Keyset 'Sparse' - 96-bit keys with up to 4 bits set - 3469497 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  86 - 0.096%

Keyset 'Sparse' - 256-bit keys with up to 3 bits set - 2796417 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  25 - 0.073%

Keyset 'Sparse' - 2048-bit keys with up to 2 bits set - 2098177 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit  75 - 0.099%


[[[ Keyset 'Combination Lowbits' Tests ]]]

Keyset 'Combination' - up to 8 blocks from a set of 8 - 19173960 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit 120 - 0.024%


[[[ Keyset 'Combination Highbits' Tests ]]]

Keyset 'Combination' - up to 8 blocks from a set of 8 - 19173960 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  38 - 0.019%


[[[ Keyset 'Combination 0x8000000' Tests ]]]

Keyset 'Combination' - up to 20 blocks from a set of 2 - 2097150 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit  13 - 0.079%


[[[ Keyset 'Combination 0x0000001' Tests ]]]

Keyset 'Combination' - up to 20 blocks from a set of 2 - 2097150 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit   1 - 0.079%


[[[ Keyset 'Combination Hi-Lo' Tests ]]]

Keyset 'Combination' - up to 6 blocks from a set of 15 - 12204240 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  44 - 0.033%


[[[ Keyset 'Window' Tests ]]]

Keyset 'Windowed' - 256-bit key,  20-bit window - 256 tests, 1048576 keys per test
Window at   0 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at   1 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at   2 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at   3 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at   4 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at   5 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at   6 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at   7 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at   8 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at   9 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  10 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  11 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  12 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  13 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  14 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  15 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  16 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  17 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  18 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  19 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  20 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  21 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  22 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  23 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  24 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  25 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  26 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  27 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  28 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  29 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  30 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  31 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  32 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  33 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  34 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  35 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  36 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  37 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  38 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  39 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  40 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  41 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  42 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  43 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  44 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  45 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  46 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  47 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  48 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  49 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  50 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  51 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  52 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  53 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  54 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  55 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  56 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  57 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  58 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  59 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  60 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  61 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  62 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  63 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  64 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  65 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  66 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  67 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  68 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  69 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  70 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  71 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  72 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  73 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  74 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  75 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  76 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  77 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  78 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  79 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  80 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  81 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  82 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  83 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  84 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  85 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  86 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  87 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  88 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  89 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  90 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  91 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  92 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  93 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  94 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  95 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  96 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  97 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  98 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at  99 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 100 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 101 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 102 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 103 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 104 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 105 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 106 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 107 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 108 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 109 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 110 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 111 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 112 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 113 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 114 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 115 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 116 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 117 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 118 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 119 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 120 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 121 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 122 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 123 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 124 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 125 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 126 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 127 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 128 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 129 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 130 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 131 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 132 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 133 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 134 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 135 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 136 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 137 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 138 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 139 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 140 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 141 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 142 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 143 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 144 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 145 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 146 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 147 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 148 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 149 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 150 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 151 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 152 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 153 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 154 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 155 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 156 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 157 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 158 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 159 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 160 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 161 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 162 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 163 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 164 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 165 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 166 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 167 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 168 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 169 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 170 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 171 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 172 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 173 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 174 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 175 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 176 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 177 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 178 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 179 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 180 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 181 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 182 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 183 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 184 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 185 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 186 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 187 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 188 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 189 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 190 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 191 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 192 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 193 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 194 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 195 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 196 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 197 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 198 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 199 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 200 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 201 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 202 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 203 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 204 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 205 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 206 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 207 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 208 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 209 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 210 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 211 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 212 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 213 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 214 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 215 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 216 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 217 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 218 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 219 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 220 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 221 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 222 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 223 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 224 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 225 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 226 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 227 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 228 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 229 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 230 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 231 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 232 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 233 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 234 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 235 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 236 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 237 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 238 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 239 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 240 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 241 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 242 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 243 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 244 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 245 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 246 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 247 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 248 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 249 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 250 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 251 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 252 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 253 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 254 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 255 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Window at 256 - Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)

[[[ Keyset 'Text' Tests ]]]

Keyset 'Text' - keys of form "Foo[XXXX]Bar" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  40 - 0.034%

Keyset 'Text' - keys of form "FooBar[XXXX]" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  29 - 0.023%

Keyset 'Text' - keys of form "[XXXX]FooBar" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit 106 - 0.030%


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 65536 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  13-bit window at bit   0 - 0.550%


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' - 1000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit 118 - 0.125%



Input vcode 0x00000001, Output vcode 0x00000001, Result vcode 0x00000001
Verification value is 0x666acc28 - Testing took 3382.608000 seconds
-------------------------------------------------------------------------------
```