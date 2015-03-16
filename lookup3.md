
```
-------------------------------------------------------------------------------
--- Testing lookup3 (Bob Jenkins lookup3)

[[[ Sanity Tests ]]]

Verification value 0x3D83917A : Passed!
Running sanity check 1..........PASS
Running sanity check 2..........PASS

[[[ Speed Tests ]]]

Bulk speed test - 262144-byte keys
Alignment  0 -  0.530 bytes/cycle - 1515.17 MiB/sec @ 3 ghz
Alignment  1 -  0.528 bytes/cycle - 1511.70 MiB/sec @ 3 ghz
Alignment  2 -  0.528 bytes/cycle - 1511.59 MiB/sec @ 3 ghz
Alignment  3 -  0.528 bytes/cycle - 1511.57 MiB/sec @ 3 ghz
Alignment  4 -  0.530 bytes/cycle - 1515.17 MiB/sec @ 3 ghz
Alignment  5 -  0.528 bytes/cycle - 1511.72 MiB/sec @ 3 ghz
Alignment  6 -  0.528 bytes/cycle - 1511.72 MiB/sec @ 3 ghz
Alignment  7 -  0.528 bytes/cycle - 1511.72 MiB/sec @ 3 ghz

Small key speed test -    1-byte keys -    22.33 cycles/hash,   0.0448 bytes/cycle
Small key speed test -    2-byte keys -    23.13 cycles/hash,   0.0865 bytes/cycle
Small key speed test -    3-byte keys -    23.05 cycles/hash,   0.1302 bytes/cycle
Small key speed test -    4-byte keys -    23.05 cycles/hash,   0.1736 bytes/cycle
Small key speed test -    5-byte keys -    23.89 cycles/hash,   0.2093 bytes/cycle
Small key speed test -    6-byte keys -    23.84 cycles/hash,   0.2516 bytes/cycle
Small key speed test -    7-byte keys -    23.84 cycles/hash,   0.2936 bytes/cycle
Small key speed test -    8-byte keys -    23.84 cycles/hash,   0.3355 bytes/cycle
Small key speed test -    9-byte keys -    23.89 cycles/hash,   0.3767 bytes/cycle
Small key speed test -   10-byte keys -    23.84 cycles/hash,   0.4194 bytes/cycle
Small key speed test -   11-byte keys -    23.94 cycles/hash,   0.4595 bytes/cycle
Small key speed test -   12-byte keys -    23.84 cycles/hash,   0.5033 bytes/cycle
Small key speed test -   13-byte keys -    42.38 cycles/hash,   0.3068 bytes/cycle
Small key speed test -   14-byte keys -    41.97 cycles/hash,   0.3336 bytes/cycle
Small key speed test -   15-byte keys -    42.45 cycles/hash,   0.3533 bytes/cycle
Small key speed test -   16-byte keys -    42.50 cycles/hash,   0.3765 bytes/cycle
Small key speed test -   17-byte keys -    42.95 cycles/hash,   0.3958 bytes/cycle
Small key speed test -   18-byte keys -    43.05 cycles/hash,   0.4181 bytes/cycle
Small key speed test -   19-byte keys -    43.05 cycles/hash,   0.4414 bytes/cycle
Small key speed test -   20-byte keys -    42.19 cycles/hash,   0.4741 bytes/cycle
Small key speed test -   21-byte keys -    43.58 cycles/hash,   0.4819 bytes/cycle
Small key speed test -   22-byte keys -    43.48 cycles/hash,   0.5059 bytes/cycle
Small key speed test -   23-byte keys -    41.39 cycles/hash,   0.5557 bytes/cycle
Small key speed test -   24-byte keys -    43.31 cycles/hash,   0.5541 bytes/cycle
Small key speed test -   25-byte keys -    66.08 cycles/hash,   0.3783 bytes/cycle
Small key speed test -   26-byte keys -    64.95 cycles/hash,   0.4003 bytes/cycle
Small key speed test -   27-byte keys -    65.00 cycles/hash,   0.4154 bytes/cycle
Small key speed test -   28-byte keys -    65.50 cycles/hash,   0.4275 bytes/cycle
Small key speed test -   29-byte keys -    65.48 cycles/hash,   0.4429 bytes/cycle
Small key speed test -   30-byte keys -    65.23 cycles/hash,   0.4599 bytes/cycle
Small key speed test -   31-byte keys -    66.03 cycles/hash,   0.4695 bytes/cycle

[[[ Differential Tests ]]]

Testing 8303632 up-to-5-bit differentials in 64-bit keys -> 32 bit hashes.
1000 reps, 8303632000 total tests, expecting 1.93 random collisions..........
2 total collisions, of which 2 single collisions were ignored

Testing 11017632 up-to-4-bit differentials in 128-bit keys -> 32 bit hashes.
1000 reps, 11017632000 total tests, expecting 2.57 random collisions..........
2 total collisions, of which 2 single collisions were ignored

Testing 2796416 up-to-3-bit differentials in 256-bit keys -> 32 bit hashes.
1000 reps, 2796416000 total tests, expecting 0.65 random collisions..........
1 total collisions, of which 1 single collisions were ignored


[[[ Avalanche Tests ]]]

Testing  32-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 11.497333% !!!!!
Testing  40-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 11.476000% !!!!!
Testing  48-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.582667% !!!!!
Testing  56-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.913333% !!!!!
Testing  64-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.482667% !!!!!
Testing  72-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.839333% !!!!!
Testing  80-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.755333% !!!!!
Testing  88-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.521333% !!!!!
Testing  96-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.566667% !!!!!
Testing 104-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 1.495333% !!!!!
Testing 112-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 3.388667% !!!!!
Testing 120-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 3.658667% !!!!!
Testing 128-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.364000% !!!!!
Testing 136-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.241333% !!!!!
Testing 144-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.516667% !!!!!
Testing 152-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 6.372000% !!!!!
*********FAIL*********

[[[ Keyset 'Cyclic' Tests ]]]

Keyset 'Cyclic' - 8 cycles of 4 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11693.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  13 - 0.015%

Keyset 'Cyclic' - 8 cycles of 5 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11734.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit  19 - 0.022%

Keyset 'Cyclic' - 8 cycles of 6 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11719.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit  31 - 0.029%

Keyset 'Cyclic' - 8 cycles of 7 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11706.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit  18 - 0.030%

Keyset 'Cyclic' - 8 cycles of 8 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11602.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  31 - 0.042%


[[[ Keyset 'TwoBytes' Tests ]]]

Keyset 'TwoBytes' - up-to-4-byte keys, 652545 total keys
Testing collisions   - Expected    49.57, actual    52.00 ( 1.05x)
Testing distribution - Worst bias is the  16-bit window at bit   6 - 0.097%

Keyset 'TwoBytes' - up-to-8-byte keys, 5471025 total keys
Testing collisions   - Expected  3484.56, actual  3487.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit   6 - 0.034%

Keyset 'TwoBytes' - up-to-12-byte keys, 18616785 total keys
Testing collisions   - Expected 40347.77, actual 40269.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  29 - 0.012%

Keyset 'TwoBytes' - up-to-16-byte keys, 44251425 total keys
Testing collisions   - Expected 227963.15, actual 228161.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  14 - 0.006%

Keyset 'TwoBytes' - up-to-20-byte keys, 86536545 total keys
Testing collisions   - Expected 871784.70, actual 868228.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit   6 - 0.004%


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 32-bit keys with up to 6 bits set - 1149017 keys
Testing collisions   - Expected   153.70, actual   164.00 ( 1.07x)
Testing distribution - Worst bias is the  17-bit window at bit   9 - 0.108%

Keyset 'Sparse' - 40-bit keys with up to 6 bits set - 4598479 keys
Testing collisions   - Expected  2461.72, actual  2444.00 ( 0.99x)
Testing distribution - Worst bias is the  19-bit window at bit  23 - 0.042%

Keyset 'Sparse' - 48-bit keys with up to 5 bits set - 1925357 keys
Testing collisions   - Expected   431.55, actual   407.00 ( 0.94x)
Testing distribution - Worst bias is the  18-bit window at bit  13 - 0.099%

Keyset 'Sparse' - 56-bit keys with up to 5 bits set - 4216423 keys
Testing collisions   - Expected  2069.66, actual  2011.00 ( 0.97x)
Testing distribution - Worst bias is the  18-bit window at bit  17 - 0.030%

Keyset 'Sparse' - 64-bit keys with up to 5 bits set - 8303633 keys
Testing collisions   - Expected  8026.87, actual  7942.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit  15 - 0.029%

Keyset 'Sparse' - 96-bit keys with up to 4 bits set - 3469497 keys
Testing collisions   - Expected  1401.34, actual  1462.00 ( 1.04x)
Testing distribution - Worst bias is the  19-bit window at bit  10 - 0.072%

Keyset 'Sparse' - 256-bit keys with up to 3 bits set - 2796417 keys
Testing collisions   - Expected   910.36, actual   920.00 ( 1.01x)
Testing distribution - Worst bias is the  18-bit window at bit   8 - 0.035%

Keyset 'Sparse' - 2048-bit keys with up to 2 bits set - 2098177 keys
Testing collisions   - Expected   512.50, actual   525.00 ( 1.02x)
Testing distribution - Worst bias is the  18-bit window at bit  31 - 0.056%


[[[ Keyset 'Combination Lowbits' Tests ]]]

Keyset 'Combination' - up to 8 blocks from a set of 8 - 19173960 keys
Testing collisions   - Expected 42799.01, actual 308165.00 ( 7.20x) !!!!!
Testing distribution - Worst bias is the  20-bit window at bit  18 - 0.165%

*********FAIL*********

[[[ Keyset 'Combination Highbits' Tests ]]]

Keyset 'Combination' - up to 8 blocks from a set of 8 - 19173960 keys
Testing collisions   - Expected 42799.01, actual 42809.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  19 - 0.015%


[[[ Keyset 'Combination 0x8000000' Tests ]]]

Keyset 'Combination' - up to 20 blocks from a set of 2 - 2097150 keys
Testing collisions   - Expected   512.00, actual   541.00 ( 1.06x)
Testing distribution - Worst bias is the  18-bit window at bit  22 - 0.056%


[[[ Keyset 'Combination 0x0000001' Tests ]]]

Keyset 'Combination' - up to 20 blocks from a set of 2 - 2097150 keys
Testing collisions   - Expected   512.00, actual   535.00 ( 1.04x)
Testing distribution - Worst bias is the  18-bit window at bit  21 - 0.068%


[[[ Keyset 'Combination Hi-Lo' Tests ]]]

Keyset 'Combination' - up to 6 blocks from a set of 15 - 12204240 keys
Testing collisions   - Expected 17339.30, actual 32772.00 ( 1.89x)
Testing distribution - Worst bias is the  20-bit window at bit  27 - 0.047%


[[[ Keyset 'Window' Tests ]]]

Keyset 'Windowed' -  64-bit key,  20-bit window - 64 tests, 1048576 keys per test
Window at   0 - Testing collisions   - Expected   128.00, actual   114.00 ( 0.89x)
Window at   1 - Testing collisions   - Expected   128.00, actual   143.00 ( 1.12x)
Window at   2 - Testing collisions   - Expected   128.00, actual   147.00 ( 1.15x)
Window at   3 - Testing collisions   - Expected   128.00, actual   129.00 ( 1.01x)
Window at   4 - Testing collisions   - Expected   128.00, actual   110.00 ( 0.86x)
Window at   5 - Testing collisions   - Expected   128.00, actual   127.00 ( 0.99x)
Window at   6 - Testing collisions   - Expected   128.00, actual   137.00 ( 1.07x)
Window at   7 - Testing collisions   - Expected   128.00, actual   118.00 ( 0.92x)
Window at   8 - Testing collisions   - Expected   128.00, actual   119.00 ( 0.93x)
Window at   9 - Testing collisions   - Expected   128.00, actual   125.00 ( 0.98x)
Window at  10 - Testing collisions   - Expected   128.00, actual   152.00 ( 1.19x)
Window at  11 - Testing collisions   - Expected   128.00, actual   150.00 ( 1.17x)
Window at  12 - Testing collisions   - Expected   128.00, actual   145.00 ( 1.13x)
Window at  13 - Testing collisions   - Expected   128.00, actual   117.00 ( 0.91x)
Window at  14 - Testing collisions   - Expected   128.00, actual   108.00 ( 0.84x)
Window at  15 - Testing collisions   - Expected   128.00, actual   126.00 ( 0.98x)
Window at  16 - Testing collisions   - Expected   128.00, actual   131.00 ( 1.02x)
Window at  17 - Testing collisions   - Expected   128.00, actual   120.00 ( 0.94x)
Window at  18 - Testing collisions   - Expected   128.00, actual   132.00 ( 1.03x)
Window at  19 - Testing collisions   - Expected   128.00, actual   132.00 ( 1.03x)
Window at  20 - Testing collisions   - Expected   128.00, actual   144.00 ( 1.13x)
Window at  21 - Testing collisions   - Expected   128.00, actual   142.00 ( 1.11x)
Window at  22 - Testing collisions   - Expected   128.00, actual   120.00 ( 0.94x)
Window at  23 - Testing collisions   - Expected   128.00, actual   131.00 ( 1.02x)
Window at  24 - Testing collisions   - Expected   128.00, actual   127.00 ( 0.99x)
Window at  25 - Testing collisions   - Expected   128.00, actual   131.00 ( 1.02x)
Window at  26 - Testing collisions   - Expected   128.00, actual   120.00 ( 0.94x)
Window at  27 - Testing collisions   - Expected   128.00, actual   128.00 ( 1.00x)
Window at  28 - Testing collisions   - Expected   128.00, actual   130.00 ( 1.02x)
Window at  29 - Testing collisions   - Expected   128.00, actual   108.00 ( 0.84x)
Window at  30 - Testing collisions   - Expected   128.00, actual   113.00 ( 0.88x)
Window at  31 - Testing collisions   - Expected   128.00, actual   143.00 ( 1.12x)
Window at  32 - Testing collisions   - Expected   128.00, actual   146.00 ( 1.14x)
Window at  33 - Testing collisions   - Expected   128.00, actual   134.00 ( 1.05x)
Window at  34 - Testing collisions   - Expected   128.00, actual   139.00 ( 1.09x)
Window at  35 - Testing collisions   - Expected   128.00, actual   104.00 ( 0.81x)
Window at  36 - Testing collisions   - Expected   128.00, actual   122.00 ( 0.95x)
Window at  37 - Testing collisions   - Expected   128.00, actual   106.00 ( 0.83x)
Window at  38 - Testing collisions   - Expected   128.00, actual   114.00 ( 0.89x)
Window at  39 - Testing collisions   - Expected   128.00, actual   132.00 ( 1.03x)
Window at  40 - Testing collisions   - Expected   128.00, actual   116.00 ( 0.91x)
Window at  41 - Testing collisions   - Expected   128.00, actual   123.00 ( 0.96x)
Window at  42 - Testing collisions   - Expected   128.00, actual   133.00 ( 1.04x)
Window at  43 - Testing collisions   - Expected   128.00, actual   147.00 ( 1.15x)
Window at  44 - Testing collisions   - Expected   128.00, actual   136.00 ( 1.06x)
Window at  45 - Testing collisions   - Expected   128.00, actual   124.00 ( 0.97x)
Window at  46 - Testing collisions   - Expected   128.00, actual   134.00 ( 1.05x)
Window at  47 - Testing collisions   - Expected   128.00, actual   118.00 ( 0.92x)
Window at  48 - Testing collisions   - Expected   128.00, actual   129.00 ( 1.01x)
Window at  49 - Testing collisions   - Expected   128.00, actual   139.00 ( 1.09x)
Window at  50 - Testing collisions   - Expected   128.00, actual   146.00 ( 1.14x)
Window at  51 - Testing collisions   - Expected   128.00, actual   135.00 ( 1.05x)
Window at  52 - Testing collisions   - Expected   128.00, actual   121.00 ( 0.95x)
Window at  53 - Testing collisions   - Expected   128.00, actual   139.00 ( 1.09x)
Window at  54 - Testing collisions   - Expected   128.00, actual   115.00 ( 0.90x)
Window at  55 - Testing collisions   - Expected   128.00, actual   120.00 ( 0.94x)
Window at  56 - Testing collisions   - Expected   128.00, actual   119.00 ( 0.93x)
Window at  57 - Testing collisions   - Expected   128.00, actual   128.00 ( 1.00x)
Window at  58 - Testing collisions   - Expected   128.00, actual   112.00 ( 0.88x)
Window at  59 - Testing collisions   - Expected   128.00, actual   110.00 ( 0.86x)
Window at  60 - Testing collisions   - Expected   128.00, actual   120.00 ( 0.94x)
Window at  61 - Testing collisions   - Expected   128.00, actual   112.00 ( 0.88x)
Window at  62 - Testing collisions   - Expected   128.00, actual   121.00 ( 0.95x)
Window at  63 - Testing collisions   - Expected   128.00, actual   122.00 ( 0.95x)
Window at  64 - Testing collisions   - Expected   128.00, actual   114.00 ( 0.89x)

[[[ Keyset 'Text' Tests ]]]

Keyset 'Text' - keys of form "Foo[XXXX]Bar" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 25421.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  30 - 0.017%

Keyset 'Text' - keys of form "FooBar[XXXX]" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 25388.00 ( 1.00x)
Testing distribution - Worst bias is the  19-bit window at bit   3 - 0.020%

Keyset 'Text' - keys of form "[XXXX]FooBar" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 25328.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  13 - 0.016%


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 65536 keys
Testing collisions   - Expected     0.50, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  13-bit window at bit   8 - 0.357%


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' - 1000000 keys
Testing collisions   - Expected   116.42, actual   133.00 ( 1.14x)
Testing distribution - Worst bias is the  17-bit window at bit   0 - 0.140%



Input vcode 0xf349a73c, Output vcode 0xb4f34640, Result vcode 0x00000001
Verification value is 0xfef17799 - Testing took 2103.862000 seconds
-------------------------------------------------------------------------------
```