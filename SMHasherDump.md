This test was produced by [SMHasher](SMHasher.md) running on an Intel Core 2 Quad Q9650 running at 3.0 ghz. The code is single-threaded and was restricted to running on a single core, which produces more repeatable results.

```
-------------------------------------------------------------------------------
--- Testing MurmurHash3 for x86, 32-bit

[[[ Sanity Tests ]]]

"The quick brown fox jumps over the lazy dog" => { 0x51c757e7, }
"The quick brown fox jumps over the lazy cog" => { 0xa7b7110c, }

Testing bit twiddling..........PASS
Testing alignment handling on small keys..........PASS
Testing zero-appending..........PASS

[[[ Speed Tests ]]]

Bulk speed test - 262144-byte keys
Alignment  0 -  1.089 bytes/cycle - 3115.26 MiB/sec @ 3 ghz
Alignment  1 -  0.901 bytes/cycle - 2576.87 MiB/sec @ 3 ghz
Alignment  2 -  0.901 bytes/cycle - 2576.87 MiB/sec @ 3 ghz
Alignment  3 -  0.901 bytes/cycle - 2576.71 MiB/sec @ 3 ghz
Alignment  4 -  1.090 bytes/cycle - 3117.71 MiB/sec @ 3 ghz
Alignment  5 -  0.901 bytes/cycle - 2576.79 MiB/sec @ 3 ghz
Alignment  6 -  0.901 bytes/cycle - 2576.71 MiB/sec @ 3 ghz
Alignment  7 -  0.901 bytes/cycle - 2576.79 MiB/sec @ 3 ghz

Small key speed test -    4-byte keys -    27.42 cycles/hash,   0.1459 bytes/cycle
Small key speed test -    8-byte keys -    30.80 cycles/hash,   0.2598 bytes/cycle
Small key speed test -   16-byte keys -    37.83 cycles/hash,   0.4230 bytes/cycle
Small key speed test -   32-byte keys -    53.16 cycles/hash,   0.6020 bytes/cycle
Small key speed test -   64-byte keys -    82.69 cycles/hash,   0.7740 bytes/cycle
Small key speed test -  128-byte keys -   141.61 cycles/hash,   0.9039 bytes/cycle

[[[ Differential Tests ]]]

Testing 8303632 up-to-5-bit differentials in 64-bit keys -> 32 bit hashes.
1000 reps, 8303632000 total tests, expecting 1.93 random collisions..........
0 total collisions, of which 0 single collisions were ignored

Testing 11017632 up-to-4-bit differentials in 128-bit keys -> 32 bit hashes.
1000 reps, 11017632000 total tests, expecting 2.57 random collisions..........
4 total collisions, of which 4 single collisions were ignored

Testing 2796416 up-to-3-bit differentials in 256-bit keys -> 32 bit hashes.
1000 reps, 2796416000 total tests, expecting 0.65 random collisions..........
2 total collisions, of which 2 single collisions were ignored


[[[ Avalanche Tests ]]]

Testing  64-bit keys ->  32-bit hashes,  2000000 reps.......... worst bias is 0.290400%

[[[ Keyset 'Cyclic' Tests ]]]

Keyset 'Cyclic' - 8 cycles of 4 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11776.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit  22 - 0.037%

Keyset 'Cyclic' - 8 cycles of 5 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11729.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit  13 - 0.026%

Keyset 'Cyclic' - 8 cycles of 6 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11747.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit   6 - 0.030%

Keyset 'Cyclic' - 8 cycles of 7 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11581.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit   6 - 0.036%

Keyset 'Cyclic' - 8 cycles of 8 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11579.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit  19 - 0.028%


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 32-bit keys with up to 6 bits set - 1149017 keys
Testing collisions   - Expected   153.70, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit  10 - 0.098%

Keyset 'Sparse' - 40-bit keys with up to 6 bits set - 4598479 keys
Testing collisions   - Expected  2461.72, actual  2155.00 ( 0.88x)
Testing distribution - Worst bias is the  19-bit window at bit  26 - 0.020%

Keyset 'Sparse' - 48-bit keys with up to 5 bits set - 1925357 keys
Testing collisions   - Expected   431.55, actual   420.00 ( 0.97x)
Testing distribution - Worst bias is the  17-bit window at bit   2 - 0.063%

Keyset 'Sparse' - 56-bit keys with up to 5 bits set - 4216423 keys
Testing collisions   - Expected  2069.66, actual  2101.00 ( 1.02x)
Testing distribution - Worst bias is the  19-bit window at bit  22 - 0.072%

Keyset 'Sparse' - 64-bit keys with up to 5 bits set - 8303633 keys
Testing collisions   - Expected  8026.87, actual  8022.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  19 - 0.045%

Keyset 'Sparse' - 96-bit keys with up to 4 bits set - 3469497 keys
Testing collisions   - Expected  1401.34, actual  1312.00 ( 0.94x)
Testing distribution - Worst bias is the  19-bit window at bit  29 - 0.041%

Keyset 'Sparse' - 256-bit keys with up to 3 bits set - 2796417 keys
Testing collisions   - Expected   910.36, actual   923.00 ( 1.01x)
Testing distribution - Worst bias is the  19-bit window at bit   2 - 0.076%

Keyset 'Sparse' - 2048-bit keys with up to 2 bits set - 2098177 keys
Testing collisions   - Expected   512.50, actual   543.00 ( 1.06x)
Testing distribution - Worst bias is the  18-bit window at bit  26 - 0.063%


[[[ Keyset 'Permutation' Tests ]]]

Keyset 'Permutation' - 10 blocks - 3628800 keys
Testing collisions   - Expected  1532.98, actual  1506.00 ( 0.98x)
Testing distribution - Worst bias is the  19-bit window at bit  26 - 0.049%


[[[ Keyset 'Window' Tests ]]]

Keyset 'Windowed' -  64-bit key,  20-bit window - 44 tests, 1048576 keys per test
Window at   0 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at   1 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at   2 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at   3 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at   4 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at   5 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at   6 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at   7 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at   8 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at   9 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  10 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  11 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  12 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  13 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  14 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  15 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  16 - Testing collisions   - Expected   128.00, actual    64.00 ( 0.50x)
Window at  17 - Testing collisions   - Expected   128.00, actual   160.00 ( 1.25x)
Window at  18 - Testing collisions   - Expected   128.00, actual   208.00 ( 1.63x)
Window at  19 - Testing collisions   - Expected   128.00, actual   144.00 ( 1.13x)
Window at  20 - Testing collisions   - Expected   128.00, actual   136.00 ( 1.06x)
Window at  21 - Testing collisions   - Expected   128.00, actual   148.00 ( 1.16x)
Window at  22 - Testing collisions   - Expected   128.00, actual   134.00 ( 1.05x)
Window at  23 - Testing collisions   - Expected   128.00, actual   116.00 ( 0.91x)
Window at  24 - Testing collisions   - Expected   128.00, actual   112.00 ( 0.88x)
Window at  25 - Testing collisions   - Expected   128.00, actual    96.00 ( 0.75x)
Window at  26 - Testing collisions   - Expected   128.00, actual   124.00 ( 0.97x)
Window at  27 - Testing collisions   - Expected   128.00, actual   112.00 ( 0.88x)
Window at  28 - Testing collisions   - Expected   128.00, actual   128.00 ( 1.00x)
Window at  29 - Testing collisions   - Expected   128.00, actual   166.00 ( 1.30x)
Window at  30 - Testing collisions   - Expected   128.00, actual   134.00 ( 1.05x)
Window at  31 - Testing collisions   - Expected   128.00, actual    18.00 ( 0.14x)
Window at  32 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  33 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  34 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  35 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  36 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  37 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  38 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  39 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  40 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  41 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  42 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  43 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  44 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)

[[[ Keyset 'Text' Tests ]]]

Keyset 'Text' - keys of form "Foo[XXXX]Bar" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 25281.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit   0 - 0.018%

Keyset 'Text' - keys of form "FooBar[XXXX]" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 24717.00 ( 0.97x)
Testing distribution - Worst bias is the  18-bit window at bit  17 - 0.014%

Keyset 'Text' - keys of form "[XXXX]FooBar" - 14776336 keys
Testing collisions   - Expected 25418.13, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit   4 - 0.006%


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 65536 keys
Testing collisions   - Expected     0.50, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  13-bit window at bit  12 - 0.595%


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' - 1000000 keys
Testing collisions   - Expected   116.42, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit   9 - 0.097%


-------------------------------------------------------------------------------
--- Testing MurmurHash3 for x86, 64-bit

[[[ Sanity Tests ]]]

"The quick brown fox jumps over the lazy dog" => { 0x398f9f6f, 0xbdaf3418, }
"The quick brown fox jumps over the lazy cog" => { 0x0636e30e, 0x005b9049, }

Testing bit twiddling..........PASS
Testing alignment handling on small keys..........PASS
Testing zero-appending..........PASS

[[[ Speed Tests ]]]

Bulk speed test - 262144-byte keys
Alignment  0 -  1.016 bytes/cycle - 2906.13 MiB/sec @ 3 ghz
Alignment  1 -  0.878 bytes/cycle - 2511.10 MiB/sec @ 3 ghz
Alignment  2 -  0.878 bytes/cycle - 2510.65 MiB/sec @ 3 ghz
Alignment  3 -  0.878 bytes/cycle - 2511.10 MiB/sec @ 3 ghz
Alignment  4 -  1.016 bytes/cycle - 2907.86 MiB/sec @ 3 ghz
Alignment  5 -  0.858 bytes/cycle - 2454.01 MiB/sec @ 3 ghz
Alignment  6 -  0.856 bytes/cycle - 2449.61 MiB/sec @ 3 ghz
Alignment  7 -  0.857 bytes/cycle - 2451.92 MiB/sec @ 3 ghz

Small key speed test -    4-byte keys -    49.78 cycles/hash,   0.0804 bytes/cycle
Small key speed test -    8-byte keys -    44.72 cycles/hash,   0.1789 bytes/cycle
Small key speed test -   16-byte keys -    50.48 cycles/hash,   0.3169 bytes/cycle
Small key speed test -   32-byte keys -    65.95 cycles/hash,   0.4852 bytes/cycle
Small key speed test -   64-byte keys -    97.17 cycles/hash,   0.6586 bytes/cycle
Small key speed test -  128-byte keys -   160.03 cycles/hash,   0.7998 bytes/cycle

[[[ Differential Tests ]]]

Testing 8303632 up-to-5-bit differentials in 64-bit keys -> 64 bit hashes.
1000 reps, 8303632000 total tests, expecting 0.00 random collisions..........
0 total collisions, of which 0 single collisions were ignored

Testing 11017632 up-to-4-bit differentials in 128-bit keys -> 64 bit hashes.
1000 reps, 11017632000 total tests, expecting 0.00 random collisions..........
0 total collisions, of which 0 single collisions were ignored

Testing 2796416 up-to-3-bit differentials in 256-bit keys -> 64 bit hashes.
1000 reps, 2796416000 total tests, expecting 0.00 random collisions..........
0 total collisions, of which 0 single collisions were ignored


[[[ Avalanche Tests ]]]

Testing 128-bit keys ->  64-bit hashes,  2000000 reps.......... worst bias is 0.275400%

[[[ Keyset 'Cyclic' Tests ]]]

Keyset 'Cyclic' - 8 cycles of 8 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit   5 - 0.026%

Keyset 'Cyclic' - 8 cycles of 9 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit   5 - 0.022%

Keyset 'Cyclic' - 8 cycles of 10 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  50 - 0.032%

Keyset 'Cyclic' - 8 cycles of 11 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  31 - 0.034%

Keyset 'Cyclic' - 8 cycles of 12 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  47 - 0.039%


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 32-bit keys with up to 6 bits set - 1149017 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit  47 - 0.138%

Keyset 'Sparse' - 40-bit keys with up to 6 bits set - 4598479 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  16 - 0.067%

Keyset 'Sparse' - 48-bit keys with up to 5 bits set - 1925357 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit  45 - 0.104%

Keyset 'Sparse' - 56-bit keys with up to 5 bits set - 4216423 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  33 - 0.049%

Keyset 'Sparse' - 64-bit keys with up to 5 bits set - 8303633 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  31 - 0.047%

Keyset 'Sparse' - 96-bit keys with up to 4 bits set - 3469497 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  25 - 0.041%

Keyset 'Sparse' - 256-bit keys with up to 3 bits set - 2796417 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  13 - 0.067%

Keyset 'Sparse' - 2048-bit keys with up to 2 bits set - 2098177 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit  15 - 0.108%


[[[ Keyset 'Permutation' Tests ]]]

Keyset 'Permutation' - 10 blocks - 3628800 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  43 - 0.082%


[[[ Keyset 'Window' Tests ]]]

Keyset 'Windowed' - 128-bit key,  20-bit window - 108 tests, 1048576 keys per test
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

[[[ Keyset 'Text' Tests ]]]

Keyset 'Text' - keys of form "Foo[XXXX]Bar" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  55 - 0.026%

Keyset 'Text' - keys of form "FooBar[XXXX]" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  56 - 0.017%

Keyset 'Text' - keys of form "[XXXX]FooBar" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  55 - 0.027%


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 65536 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  13-bit window at bit  37 - 0.390%


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' - 1000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  16-bit window at bit  52 - 0.101%


-------------------------------------------------------------------------------
--- Testing MurmurHash3 for x86, 128-bit

[[[ Sanity Tests ]]]

"The quick brown fox jumps over the lazy dog" => { 0x28c6693d, 0xa85103d9, 0xdcea80a0, 0x0bbf02c9, }
"The quick brown fox jumps over the lazy cog" => { 0xc9f8f5cb, 0x263225a8, 0xf4ddd8b5, 0xf1d9391d, }

Testing bit twiddling..........PASS
Testing alignment handling on small keys..........PASS
Testing zero-appending..........PASS

[[[ Speed Tests ]]]

Bulk speed test - 262144-byte keys
Alignment  0 -  1.085 bytes/cycle - 3104.70 MiB/sec @ 3 ghz
Alignment  1 -  0.880 bytes/cycle - 2518.92 MiB/sec @ 3 ghz
Alignment  2 -  0.880 bytes/cycle - 2518.61 MiB/sec @ 3 ghz
Alignment  3 -  0.880 bytes/cycle - 2518.76 MiB/sec @ 3 ghz
Alignment  4 -  1.085 bytes/cycle - 3105.05 MiB/sec @ 3 ghz
Alignment  5 -  0.926 bytes/cycle - 2650.72 MiB/sec @ 3 ghz
Alignment  6 -  0.927 bytes/cycle - 2650.80 MiB/sec @ 3 ghz
Alignment  7 -  0.926 bytes/cycle - 2650.64 MiB/sec @ 3 ghz

Small key speed test -    4-byte keys -    74.53 cycles/hash,   0.0537 bytes/cycle
Small key speed test -    8-byte keys -    75.80 cycles/hash,   0.1055 bytes/cycle
Small key speed test -   16-byte keys -    65.81 cycles/hash,   0.2431 bytes/cycle
Small key speed test -   32-byte keys -    80.16 cycles/hash,   0.3992 bytes/cycle
Small key speed test -   64-byte keys -   107.58 cycles/hash,   0.5949 bytes/cycle
Small key speed test -  128-byte keys -   168.75 cycles/hash,   0.7585 bytes/cycle

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

Testing 256-bit keys -> 128-bit hashes,  2000000 reps.......... worst bias is 0.311300%

[[[ Keyset 'Cyclic' Tests ]]]

Keyset 'Cyclic' - 8 cycles of 16 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit 123 - 0.048%

Keyset 'Cyclic' - 8 cycles of 17 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit 105 - 0.042%

Keyset 'Cyclic' - 8 cycles of 18 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  85 - 0.032%

Keyset 'Cyclic' - 8 cycles of 19 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit 124 - 0.031%

Keyset 'Cyclic' - 8 cycles of 20 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  67 - 0.032%


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 32-bit keys with up to 6 bits set - 1149017 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit 108 - 0.106%

Keyset 'Sparse' - 40-bit keys with up to 6 bits set - 4598479 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit   1 - 0.054%

Keyset 'Sparse' - 48-bit keys with up to 5 bits set - 1925357 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit 126 - 0.094%

Keyset 'Sparse' - 56-bit keys with up to 5 bits set - 4216423 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit 112 - 0.065%

Keyset 'Sparse' - 64-bit keys with up to 5 bits set - 8303633 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit   2 - 0.044%

Keyset 'Sparse' - 96-bit keys with up to 4 bits set - 3469497 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  83 - 0.079%

Keyset 'Sparse' - 256-bit keys with up to 3 bits set - 2796417 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  50 - 0.118%

Keyset 'Sparse' - 2048-bit keys with up to 2 bits set - 2098177 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit  76 - 0.092%


[[[ Keyset 'Permutation' Tests ]]]

Keyset 'Permutation' - 10 blocks - 3628800 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  96 - 0.075%


[[[ Keyset 'Window' Tests ]]]

Keyset 'Windowed' - 256-bit key,  20-bit window - 236 tests, 1048576 keys per test
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

[[[ Keyset 'Text' Tests ]]]

Keyset 'Text' - keys of form "Foo[XXXX]Bar" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  39 - 0.023%

Keyset 'Text' - keys of form "FooBar[XXXX]" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  17 - 0.026%

Keyset 'Text' - keys of form "[XXXX]FooBar" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit 127 - 0.021%


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 65536 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  13-bit window at bit   9 - 0.631%


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' - 1000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit   0 - 0.110%


-------------------------------------------------------------------------------
--- Testing MurmurHash3 for x64, 32-bit

[[[ Sanity Tests ]]]

"The quick brown fox jumps over the lazy dog" => { 0xc736374a, }
"The quick brown fox jumps over the lazy cog" => { 0xb4604106, }

Testing bit twiddling..........PASS
Testing alignment handling on small keys..........PASS
Testing zero-appending..........PASS

[[[ Speed Tests ]]]

Bulk speed test - 262144-byte keys
Alignment  0 -  1.761 bytes/cycle - 5038.29 MiB/sec @ 3 ghz
Alignment  1 -  1.278 bytes/cycle - 3656.09 MiB/sec @ 3 ghz
Alignment  2 -  1.278 bytes/cycle - 3657.06 MiB/sec @ 3 ghz
Alignment  3 -  1.278 bytes/cycle - 3656.57 MiB/sec @ 3 ghz
Alignment  4 -  1.278 bytes/cycle - 3656.25 MiB/sec @ 3 ghz
Alignment  5 -  1.278 bytes/cycle - 3656.25 MiB/sec @ 3 ghz
Alignment  6 -  1.278 bytes/cycle - 3656.73 MiB/sec @ 3 ghz
Alignment  7 -  1.278 bytes/cycle - 3656.90 MiB/sec @ 3 ghz

Small key speed test -    4-byte keys -    66.94 cycles/hash,   0.0598 bytes/cycle
Small key speed test -    8-byte keys -    72.42 cycles/hash,   0.1105 bytes/cycle
Small key speed test -   16-byte keys -    55.13 cycles/hash,   0.2902 bytes/cycle
Small key speed test -   32-byte keys -    61.73 cycles/hash,   0.5183 bytes/cycle
Small key speed test -   64-byte keys -    81.28 cycles/hash,   0.7874 bytes/cycle
Small key speed test -  128-byte keys -   119.67 cycles/hash,   1.0696 bytes/cycle

[[[ Differential Tests ]]]

Testing 8303632 up-to-5-bit differentials in 64-bit keys -> 32 bit hashes.
1000 reps, 8303632000 total tests, expecting 1.93 random collisions..........
5 total collisions, of which 5 single collisions were ignored

Testing 11017632 up-to-4-bit differentials in 128-bit keys -> 32 bit hashes.
1000 reps, 11017632000 total tests, expecting 2.57 random collisions..........
3 total collisions, of which 3 single collisions were ignored

Testing 2796416 up-to-3-bit differentials in 256-bit keys -> 32 bit hashes.
1000 reps, 2796416000 total tests, expecting 0.65 random collisions..........
0 total collisions, of which 0 single collisions were ignored


[[[ Avalanche Tests ]]]

Testing  64-bit keys ->  32-bit hashes,  2000000 reps.......... worst bias is 0.316200%

[[[ Keyset 'Cyclic' Tests ]]]

Keyset 'Cyclic' - 8 cycles of 4 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11810.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit  19 - 0.026%

Keyset 'Cyclic' - 8 cycles of 5 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11817.00 ( 1.02x)
Testing distribution - Worst bias is the  20-bit window at bit   9 - 0.022%

Keyset 'Cyclic' - 8 cycles of 6 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11635.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  21 - 0.037%

Keyset 'Cyclic' - 8 cycles of 7 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11582.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit   3 - 0.043%

Keyset 'Cyclic' - 8 cycles of 8 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11592.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  13 - 0.026%


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 32-bit keys with up to 6 bits set - 1149017 keys
Testing collisions   - Expected   153.70, actual   162.00 ( 1.05x)
Testing distribution - Worst bias is the  17-bit window at bit   0 - 0.153%

Keyset 'Sparse' - 40-bit keys with up to 6 bits set - 4598479 keys
Testing collisions   - Expected  2461.72, actual  2487.00 ( 1.01x)
Testing distribution - Worst bias is the  19-bit window at bit  13 - 0.034%

Keyset 'Sparse' - 48-bit keys with up to 5 bits set - 1925357 keys
Testing collisions   - Expected   431.55, actual   426.00 ( 0.99x)
Testing distribution - Worst bias is the  18-bit window at bit   7 - 0.116%

Keyset 'Sparse' - 56-bit keys with up to 5 bits set - 4216423 keys
Testing collisions   - Expected  2069.66, actual  2017.00 ( 0.97x)
Testing distribution - Worst bias is the  19-bit window at bit   5 - 0.055%

Keyset 'Sparse' - 64-bit keys with up to 5 bits set - 8303633 keys
Testing collisions   - Expected  8026.87, actual  7954.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit   8 - 0.043%

Keyset 'Sparse' - 96-bit keys with up to 4 bits set - 3469497 keys
Testing collisions   - Expected  1401.34, actual  1388.00 ( 0.99x)
Testing distribution - Worst bias is the  19-bit window at bit  27 - 0.055%

Keyset 'Sparse' - 256-bit keys with up to 3 bits set - 2796417 keys
Testing collisions   - Expected   910.36, actual   964.00 ( 1.06x)
Testing distribution - Worst bias is the  19-bit window at bit  22 - 0.115%

Keyset 'Sparse' - 2048-bit keys with up to 2 bits set - 2098177 keys
Testing collisions   - Expected   512.50, actual   489.00 ( 0.95x)
Testing distribution - Worst bias is the  18-bit window at bit  14 - 0.079%


[[[ Keyset 'Permutation' Tests ]]]

Keyset 'Permutation' - 10 blocks - 3628800 keys
Testing collisions   - Expected  1532.98, actual  1614.00 ( 1.05x)
Testing distribution - Worst bias is the  19-bit window at bit   2 - 0.069%


[[[ Keyset 'Window' Tests ]]]

Keyset 'Windowed' -  64-bit key,  20-bit window - 44 tests, 1048576 keys per test
Window at   0 - Testing collisions   - Expected   128.00, actual   112.00 ( 0.88x)
Window at   1 - Testing collisions   - Expected   128.00, actual   127.00 ( 0.99x)
Window at   2 - Testing collisions   - Expected   128.00, actual   121.00 ( 0.95x)
Window at   3 - Testing collisions   - Expected   128.00, actual   111.00 ( 0.87x)
Window at   4 - Testing collisions   - Expected   128.00, actual   107.00 ( 0.84x)
Window at   5 - Testing collisions   - Expected   128.00, actual   121.00 ( 0.95x)
Window at   6 - Testing collisions   - Expected   128.00, actual   111.00 ( 0.87x)
Window at   7 - Testing collisions   - Expected   128.00, actual   128.00 ( 1.00x)
Window at   8 - Testing collisions   - Expected   128.00, actual   127.00 ( 0.99x)
Window at   9 - Testing collisions   - Expected   128.00, actual   128.00 ( 1.00x)
Window at  10 - Testing collisions   - Expected   128.00, actual   151.00 ( 1.18x)
Window at  11 - Testing collisions   - Expected   128.00, actual   131.00 ( 1.02x)
Window at  12 - Testing collisions   - Expected   128.00, actual   141.00 ( 1.10x)
Window at  13 - Testing collisions   - Expected   128.00, actual   127.00 ( 0.99x)
Window at  14 - Testing collisions   - Expected   128.00, actual   115.00 ( 0.90x)
Window at  15 - Testing collisions   - Expected   128.00, actual   122.00 ( 0.95x)
Window at  16 - Testing collisions   - Expected   128.00, actual   130.00 ( 1.02x)
Window at  17 - Testing collisions   - Expected   128.00, actual   114.00 ( 0.89x)
Window at  18 - Testing collisions   - Expected   128.00, actual   127.00 ( 0.99x)
Window at  19 - Testing collisions   - Expected   128.00, actual   114.00 ( 0.89x)
Window at  20 - Testing collisions   - Expected   128.00, actual   133.00 ( 1.04x)
Window at  21 - Testing collisions   - Expected   128.00, actual   126.00 ( 0.98x)
Window at  22 - Testing collisions   - Expected   128.00, actual   126.00 ( 0.98x)
Window at  23 - Testing collisions   - Expected   128.00, actual   131.00 ( 1.02x)
Window at  24 - Testing collisions   - Expected   128.00, actual   135.00 ( 1.05x)
Window at  25 - Testing collisions   - Expected   128.00, actual   122.00 ( 0.95x)
Window at  26 - Testing collisions   - Expected   128.00, actual   130.00 ( 1.02x)
Window at  27 - Testing collisions   - Expected   128.00, actual   124.00 ( 0.97x)
Window at  28 - Testing collisions   - Expected   128.00, actual   120.00 ( 0.94x)
Window at  29 - Testing collisions   - Expected   128.00, actual   136.00 ( 1.06x)
Window at  30 - Testing collisions   - Expected   128.00, actual   133.00 ( 1.04x)
Window at  31 - Testing collisions   - Expected   128.00, actual   130.00 ( 1.02x)
Window at  32 - Testing collisions   - Expected   128.00, actual   124.00 ( 0.97x)
Window at  33 - Testing collisions   - Expected   128.00, actual   116.00 ( 0.91x)
Window at  34 - Testing collisions   - Expected   128.00, actual   116.00 ( 0.91x)
Window at  35 - Testing collisions   - Expected   128.00, actual   135.00 ( 1.05x)
Window at  36 - Testing collisions   - Expected   128.00, actual   153.00 ( 1.20x)
Window at  37 - Testing collisions   - Expected   128.00, actual   149.00 ( 1.16x)
Window at  38 - Testing collisions   - Expected   128.00, actual   121.00 ( 0.95x)
Window at  39 - Testing collisions   - Expected   128.00, actual   153.00 ( 1.20x)
Window at  40 - Testing collisions   - Expected   128.00, actual   133.00 ( 1.04x)
Window at  41 - Testing collisions   - Expected   128.00, actual   158.00 ( 1.23x)
Window at  42 - Testing collisions   - Expected   128.00, actual   131.00 ( 1.02x)
Window at  43 - Testing collisions   - Expected   128.00, actual   125.00 ( 0.98x)
Window at  44 - Testing collisions   - Expected   128.00, actual   125.00 ( 0.98x)

[[[ Keyset 'Text' Tests ]]]

Keyset 'Text' - keys of form "Foo[XXXX]Bar" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 25663.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit  27 - 0.021%

Keyset 'Text' - keys of form "FooBar[XXXX]" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 25561.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit  21 - 0.024%

Keyset 'Text' - keys of form "[XXXX]FooBar" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 25436.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  20 - 0.022%


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 65536 keys
Testing collisions   - Expected     0.50, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  13-bit window at bit   9 - 0.394%


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' - 1000000 keys
Testing collisions   - Expected   116.42, actual   109.00 ( 0.94x)
Testing distribution - Worst bias is the  17-bit window at bit  23 - 0.130%


-------------------------------------------------------------------------------
--- Testing MurmurHash3 for x64, 64-bit

[[[ Sanity Tests ]]]

"The quick brown fox jumps over the lazy dog" => { 0xc736374a, 0x0c949060, }
"The quick brown fox jumps over the lazy cog" => { 0xb4604106, 0x564efd38, }

Testing bit twiddling..........PASS
Testing alignment handling on small keys..........PASS
Testing zero-appending..........PASS

[[[ Speed Tests ]]]

Bulk speed test - 262144-byte keys
Alignment  0 -  1.755 bytes/cycle - 5020.08 MiB/sec @ 3 ghz
Alignment  1 -  1.278 bytes/cycle - 3655.77 MiB/sec @ 3 ghz
Alignment  2 -  1.278 bytes/cycle - 3655.77 MiB/sec @ 3 ghz
Alignment  3 -  1.277 bytes/cycle - 3652.57 MiB/sec @ 3 ghz
Alignment  4 -  1.277 bytes/cycle - 3652.41 MiB/sec @ 3 ghz
Alignment  5 -  1.277 bytes/cycle - 3652.25 MiB/sec @ 3 ghz
Alignment  6 -  1.278 bytes/cycle - 3656.09 MiB/sec @ 3 ghz
Alignment  7 -  1.278 bytes/cycle - 3656.41 MiB/sec @ 3 ghz

Small key speed test -    4-byte keys -    67.08 cycles/hash,   0.0596 bytes/cycle
Small key speed test -    8-byte keys -    72.56 cycles/hash,   0.1102 bytes/cycle
Small key speed test -   16-byte keys -    55.27 cycles/hash,   0.2895 bytes/cycle
Small key speed test -   32-byte keys -    62.02 cycles/hash,   0.5160 bytes/cycle
Small key speed test -   64-byte keys -    81.42 cycles/hash,   0.7860 bytes/cycle
Small key speed test -  128-byte keys -   119.67 cycles/hash,   1.0696 bytes/cycle

[[[ Differential Tests ]]]

Testing 8303632 up-to-5-bit differentials in 64-bit keys -> 64 bit hashes.
1000 reps, 8303632000 total tests, expecting 0.00 random collisions..........
0 total collisions, of which 0 single collisions were ignored

Testing 11017632 up-to-4-bit differentials in 128-bit keys -> 64 bit hashes.
1000 reps, 11017632000 total tests, expecting 0.00 random collisions..........
0 total collisions, of which 0 single collisions were ignored

Testing 2796416 up-to-3-bit differentials in 256-bit keys -> 64 bit hashes.
1000 reps, 2796416000 total tests, expecting 0.00 random collisions..........
0 total collisions, of which 0 single collisions were ignored


[[[ Avalanche Tests ]]]

Testing 128-bit keys ->  64-bit hashes,  2000000 reps.......... worst bias is 0.307200%

[[[ Keyset 'Cyclic' Tests ]]]

Keyset 'Cyclic' - 8 cycles of 8 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  32 - 0.027%

Keyset 'Cyclic' - 8 cycles of 9 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  51 - 0.045%

Keyset 'Cyclic' - 8 cycles of 10 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  25 - 0.043%

Keyset 'Cyclic' - 8 cycles of 11 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  12 - 0.041%

Keyset 'Cyclic' - 8 cycles of 12 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  28 - 0.040%


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 32-bit keys with up to 6 bits set - 1149017 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit   0 - 0.153%

Keyset 'Sparse' - 40-bit keys with up to 6 bits set - 4598479 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  56 - 0.052%

Keyset 'Sparse' - 48-bit keys with up to 5 bits set - 1925357 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit   7 - 0.116%

Keyset 'Sparse' - 56-bit keys with up to 5 bits set - 4216423 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  56 - 0.066%

Keyset 'Sparse' - 64-bit keys with up to 5 bits set - 8303633 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit   8 - 0.043%

Keyset 'Sparse' - 96-bit keys with up to 4 bits set - 3469497 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  57 - 0.081%

Keyset 'Sparse' - 256-bit keys with up to 3 bits set - 2796417 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  41 - 0.056%

Keyset 'Sparse' - 2048-bit keys with up to 2 bits set - 2098177 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit  14 - 0.079%


[[[ Keyset 'Permutation' Tests ]]]

Keyset 'Permutation' - 10 blocks - 3628800 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit   2 - 0.069%


[[[ Keyset 'Window' Tests ]]]

Keyset 'Windowed' - 128-bit key,  20-bit window - 108 tests, 1048576 keys per test
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

[[[ Keyset 'Text' Tests ]]]

Keyset 'Text' - keys of form "Foo[XXXX]Bar" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  17 - 0.030%

Keyset 'Text' - keys of form "FooBar[XXXX]" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  53 - 0.022%

Keyset 'Text' - keys of form "[XXXX]FooBar" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit   9 - 0.021%


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 65536 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  13-bit window at bit  29 - 0.469%


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' - 1000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit  47 - 0.117%


-------------------------------------------------------------------------------
--- Testing MurmurHash3 for x64, 128-bit

[[[ Sanity Tests ]]]

"The quick brown fox jumps over the lazy dog" => { 0xc736374a, 0x0c949060, 0x276c227b, 0x2fb48cc7, }
"The quick brown fox jumps over the lazy cog" => { 0xb4604106, 0x564efd38, 0xcb5bc785, 0x3c755f27, }

Testing bit twiddling..........PASS
Testing alignment handling on small keys..........PASS
Testing zero-appending..........PASS

[[[ Speed Tests ]]]

Bulk speed test - 262144-byte keys
Alignment  0 -  1.768 bytes/cycle - 5058.78 MiB/sec @ 3 ghz
Alignment  1 -  1.278 bytes/cycle - 3656.73 MiB/sec @ 3 ghz
Alignment  2 -  1.278 bytes/cycle - 3655.93 MiB/sec @ 3 ghz
Alignment  3 -  1.278 bytes/cycle - 3655.93 MiB/sec @ 3 ghz
Alignment  4 -  1.278 bytes/cycle - 3656.73 MiB/sec @ 3 ghz
Alignment  5 -  1.278 bytes/cycle - 3656.57 MiB/sec @ 3 ghz
Alignment  6 -  1.278 bytes/cycle - 3656.09 MiB/sec @ 3 ghz
Alignment  7 -  1.278 bytes/cycle - 3656.90 MiB/sec @ 3 ghz

Small key speed test -    4-byte keys -    62.72 cycles/hash,   0.0638 bytes/cycle
Small key speed test -    8-byte keys -    66.80 cycles/hash,   0.1198 bytes/cycle
Small key speed test -   16-byte keys -    49.50 cycles/hash,   0.3232 bytes/cycle
Small key speed test -   32-byte keys -    57.52 cycles/hash,   0.5564 bytes/cycle
Small key speed test -   64-byte keys -    76.64 cycles/hash,   0.8351 bytes/cycle
Small key speed test -  128-byte keys -   115.03 cycles/hash,   1.1127 bytes/cycle

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

Testing 256-bit keys -> 128-bit hashes,  2000000 reps.......... worst bias is 0.296900%

[[[ Keyset 'Cyclic' Tests ]]]

Keyset 'Cyclic' - 8 cycles of 16 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  62 - 0.029%

Keyset 'Cyclic' - 8 cycles of 17 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  78 - 0.042%

Keyset 'Cyclic' - 8 cycles of 18 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  14 - 0.039%

Keyset 'Cyclic' - 8 cycles of 19 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  30 - 0.038%

Keyset 'Cyclic' - 8 cycles of 20 bytes - 10000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  13 - 0.049%


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 32-bit keys with up to 6 bits set - 1149017 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit   0 - 0.153%

Keyset 'Sparse' - 40-bit keys with up to 6 bits set - 4598479 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit 104 - 0.071%

Keyset 'Sparse' - 48-bit keys with up to 5 bits set - 1925357 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit   7 - 0.116%

Keyset 'Sparse' - 56-bit keys with up to 5 bits set - 4216423 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  67 - 0.058%

Keyset 'Sparse' - 64-bit keys with up to 5 bits set - 8303633 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit   8 - 0.043%

Keyset 'Sparse' - 96-bit keys with up to 4 bits set - 3469497 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit  68 - 0.066%

Keyset 'Sparse' - 256-bit keys with up to 3 bits set - 2796417 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit  41 - 0.056%

Keyset 'Sparse' - 2048-bit keys with up to 2 bits set - 2098177 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  18-bit window at bit  57 - 0.105%


[[[ Keyset 'Permutation' Tests ]]]

Keyset 'Permutation' - 10 blocks - 3628800 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  19-bit window at bit   2 - 0.069%


[[[ Keyset 'Window' Tests ]]]

Keyset 'Windowed' - 256-bit key,  20-bit window - 236 tests, 1048576 keys per test
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

[[[ Keyset 'Text' Tests ]]]

Keyset 'Text' - keys of form "Foo[XXXX]Bar" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  17 - 0.030%

Keyset 'Text' - keys of form "FooBar[XXXX]" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit  65 - 0.026%

Keyset 'Text' - keys of form "[XXXX]FooBar" - 14776336 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  20-bit window at bit   9 - 0.021%


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 65536 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  13-bit window at bit  91 - 0.668%


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' - 1000000 keys
Testing collisions   - Expected     0.00, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit  93 - 0.122%


time 5830139
Press any key to continue . . .
```