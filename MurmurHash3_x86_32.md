
```
-------------------------------------------------------------------------------
--- Testing Murmur3A (MurmurHash3 for x86, 32-bit)

[[[ Sanity Tests ]]]

Verification value 0x3252D141 : Passed!
Running sanity check 1..........PASS
Running sanity check 2..........PASS

[[[ Speed Tests ]]]

Bulk speed test - 262144-byte keys
Alignment  0 -  1.078 bytes/cycle - 3083.98 MiB/sec @ 3 ghz
Alignment  1 -  1.046 bytes/cycle - 2991.90 MiB/sec @ 3 ghz
Alignment  2 -  1.046 bytes/cycle - 2991.86 MiB/sec @ 3 ghz
Alignment  3 -  1.046 bytes/cycle - 2992.07 MiB/sec @ 3 ghz
Alignment  4 -  1.018 bytes/cycle - 2913.72 MiB/sec @ 3 ghz
Alignment  5 -  1.046 bytes/cycle - 2992.07 MiB/sec @ 3 ghz
Alignment  6 -  1.046 bytes/cycle - 2991.93 MiB/sec @ 3 ghz
Alignment  7 -  1.046 bytes/cycle - 2991.96 MiB/sec @ 3 ghz

Small key speed test -    1-byte keys -    16.97 cycles/hash,   0.0589 bytes/cycle
Small key speed test -    2-byte keys -    18.36 cycles/hash,   0.1089 bytes/cycle
Small key speed test -    3-byte keys -    19.06 cycles/hash,   0.1574 bytes/cycle
Small key speed test -    4-byte keys -    19.02 cycles/hash,   0.2104 bytes/cycle
Small key speed test -    5-byte keys -    20.48 cycles/hash,   0.2441 bytes/cycle
Small key speed test -    6-byte keys -    22.38 cycles/hash,   0.2682 bytes/cycle
Small key speed test -    7-byte keys -    22.81 cycles/hash,   0.3068 bytes/cycle
Small key speed test -    8-byte keys -    22.73 cycles/hash,   0.3519 bytes/cycle
Small key speed test -    9-byte keys -    24.42 cycles/hash,   0.3685 bytes/cycle
Small key speed test -   10-byte keys -    25.98 cycles/hash,   0.3848 bytes/cycle
Small key speed test -   11-byte keys -    26.17 cycles/hash,   0.4203 bytes/cycle
Small key speed test -   12-byte keys -    25.98 cycles/hash,   0.4618 bytes/cycle
Small key speed test -   13-byte keys -    27.91 cycles/hash,   0.4658 bytes/cycle
Small key speed test -   14-byte keys -    28.80 cycles/hash,   0.4862 bytes/cycle
Small key speed test -   15-byte keys -    29.06 cycles/hash,   0.5161 bytes/cycle
Small key speed test -   16-byte keys -    28.48 cycles/hash,   0.5617 bytes/cycle
Small key speed test -   17-byte keys -    30.48 cycles/hash,   0.5577 bytes/cycle
Small key speed test -   18-byte keys -    31.56 cycles/hash,   0.5703 bytes/cycle
Small key speed test -   19-byte keys -    31.97 cycles/hash,   0.5943 bytes/cycle
Small key speed test -   20-byte keys -    31.44 cycles/hash,   0.6362 bytes/cycle
Small key speed test -   21-byte keys -    33.39 cycles/hash,   0.6289 bytes/cycle
Small key speed test -   22-byte keys -    34.38 cycles/hash,   0.6400 bytes/cycle
Small key speed test -   23-byte keys -    35.67 cycles/hash,   0.6448 bytes/cycle
Small key speed test -   24-byte keys -    34.81 cycles/hash,   0.6894 bytes/cycle
Small key speed test -   25-byte keys -    37.19 cycles/hash,   0.6723 bytes/cycle
Small key speed test -   26-byte keys -    38.30 cycles/hash,   0.6789 bytes/cycle
Small key speed test -   27-byte keys -    38.98 cycles/hash,   0.6926 bytes/cycle
Small key speed test -   28-byte keys -    38.58 cycles/hash,   0.7258 bytes/cycle
Small key speed test -   29-byte keys -    40.77 cycles/hash,   0.7114 bytes/cycle
Small key speed test -   30-byte keys -    42.06 cycles/hash,   0.7132 bytes/cycle
Small key speed test -   31-byte keys -    42.11 cycles/hash,   0.7362 bytes/cycle

[[[ Differential Tests ]]]

Testing 8303632 up-to-5-bit differentials in 64-bit keys -> 32 bit hashes.
1000 reps, 8303632000 total tests, expecting 1.93 random collisions..........
1 total collisions, of which 1 single collisions were ignored

Testing 11017632 up-to-4-bit differentials in 128-bit keys -> 32 bit hashes.
1000 reps, 11017632000 total tests, expecting 2.57 random collisions..........
2 total collisions, of which 2 single collisions were ignored

Testing 2796416 up-to-3-bit differentials in 256-bit keys -> 32 bit hashes.
1000 reps, 2796416000 total tests, expecting 0.65 random collisions..........
1 total collisions, of which 1 single collisions were ignored


[[[ Avalanche Tests ]]]

Testing  32-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.646000%
Testing  40-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.670667%
Testing  48-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.585333%
Testing  56-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.726667%
Testing  64-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.680000%
Testing  72-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.641333%
Testing  80-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.646000%
Testing  88-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.715333%
Testing  96-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.654667%
Testing 104-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.688000%
Testing 112-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.664667%
Testing 120-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.796000%
Testing 128-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.598000%
Testing 136-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.784667%
Testing 144-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.648000%
Testing 152-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.695333%

[[[ Keyset 'Cyclic' Tests ]]]

Keyset 'Cyclic' - 8 cycles of 4 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11794.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit  17 - 0.039%

Keyset 'Cyclic' - 8 cycles of 5 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11784.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit  31 - 0.040%

Keyset 'Cyclic' - 8 cycles of 6 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11671.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  15 - 0.021%

Keyset 'Cyclic' - 8 cycles of 7 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11672.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  12 - 0.022%

Keyset 'Cyclic' - 8 cycles of 8 bytes - 10000000 keys
Testing collisions   - Expected 11641.53, actual 11509.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit  17 - 0.023%


[[[ Keyset 'TwoBytes' Tests ]]]

Keyset 'TwoBytes' - up-to-4-byte keys, 652545 total keys
Testing collisions   - Expected    49.57, actual    29.00 ( 0.59x)
Testing distribution - Worst bias is the  16-bit window at bit  23 - 0.177%

Keyset 'TwoBytes' - up-to-8-byte keys, 5471025 total keys
Testing collisions   - Expected  3484.56, actual  3132.00 ( 0.90x)
Testing distribution - Worst bias is the  18-bit window at bit  11 - 0.032%

Keyset 'TwoBytes' - up-to-12-byte keys, 18616785 total keys
Testing collisions   - Expected 40347.77, actual 39804.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit  23 - 0.009%

Keyset 'TwoBytes' - up-to-16-byte keys, 44251425 total keys
Testing collisions   - Expected 227963.15, actual 226118.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit  16 - 0.004%

Keyset 'TwoBytes' - up-to-20-byte keys, 86536545 total keys
Testing collisions   - Expected 871784.70, actual 865057.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit  25 - 0.003%


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 32-bit keys with up to 6 bits set - 1149017 keys
Testing collisions   - Expected   153.70, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit   8 - 0.055%

Keyset 'Sparse' - 40-bit keys with up to 6 bits set - 4598479 keys
Testing collisions   - Expected  2461.72, actual  2310.00 ( 0.94x)
Testing distribution - Worst bias is the  19-bit window at bit  14 - 0.075%

Keyset 'Sparse' - 48-bit keys with up to 5 bits set - 1925357 keys
Testing collisions   - Expected   431.55, actual   399.00 ( 0.92x)
Testing distribution - Worst bias is the  17-bit window at bit   4 - 0.060%

Keyset 'Sparse' - 56-bit keys with up to 5 bits set - 4216423 keys
Testing collisions   - Expected  2069.66, actual  1981.00 ( 0.96x)
Testing distribution - Worst bias is the  19-bit window at bit  14 - 0.050%

Keyset 'Sparse' - 64-bit keys with up to 5 bits set - 8303633 keys
Testing collisions   - Expected  8026.87, actual  7964.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit   8 - 0.047%

Keyset 'Sparse' - 96-bit keys with up to 4 bits set - 3469497 keys
Testing collisions   - Expected  1401.34, actual  1454.00 ( 1.04x)
Testing distribution - Worst bias is the  19-bit window at bit  26 - 0.062%

Keyset 'Sparse' - 256-bit keys with up to 3 bits set - 2796417 keys
Testing collisions   - Expected   910.36, actual   925.00 ( 1.02x)
Testing distribution - Worst bias is the  19-bit window at bit  27 - 0.059%

Keyset 'Sparse' - 2048-bit keys with up to 2 bits set - 2098177 keys
Testing collisions   - Expected   512.50, actual   505.00 ( 0.99x)
Testing distribution - Worst bias is the  18-bit window at bit  26 - 0.063%


[[[ Keyset 'Combination Lowbits' Tests ]]]

Keyset 'Combination' - up to 8 blocks from a set of 8 - 19173960 keys
Testing collisions   - Expected 42799.01, actual 43708.00 ( 1.02x)
Testing distribution - Worst bias is the  20-bit window at bit  18 - 0.010%


[[[ Keyset 'Combination Highbits' Tests ]]]

Keyset 'Combination' - up to 8 blocks from a set of 8 - 19173960 keys
Testing collisions   - Expected 42799.01, actual 42696.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit  28 - 0.013%


[[[ Keyset 'Combination 0x8000000' Tests ]]]

Keyset 'Combination' - up to 20 blocks from a set of 2 - 2097150 keys
Testing collisions   - Expected   512.00, actual   478.00 ( 0.93x)
Testing distribution - Worst bias is the  18-bit window at bit   0 - 0.085%


[[[ Keyset 'Combination 0x0000001' Tests ]]]

Keyset 'Combination' - up to 20 blocks from a set of 2 - 2097150 keys
Testing collisions   - Expected   512.00, actual   466.00 ( 0.91x)
Testing distribution - Worst bias is the  18-bit window at bit   8 - 0.060%


[[[ Keyset 'Combination Hi-Lo' Tests ]]]

Keyset 'Combination' - up to 6 blocks from a set of 15 - 12204240 keys
Testing collisions   - Expected 17339.30, actual 17632.00 ( 1.02x)
Testing distribution - Worst bias is the  20-bit window at bit  13 - 0.021%


[[[ Keyset 'Window' Tests ]]]

Keyset 'Windowed' -  64-bit key,  20-bit window - 64 tests, 1048576 keys per test
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
Window at  13 - Testing collisions   - Expected   128.00, actual    60.00 ( 0.47x)
Window at  14 - Testing collisions   - Expected   128.00, actual   118.00 ( 0.92x)
Window at  15 - Testing collisions   - Expected   128.00, actual    70.00 ( 0.55x)
Window at  16 - Testing collisions   - Expected   128.00, actual    94.00 ( 0.73x)
Window at  17 - Testing collisions   - Expected   128.00, actual   170.00 ( 1.33x)
Window at  18 - Testing collisions   - Expected   128.00, actual   146.00 ( 1.14x)
Window at  19 - Testing collisions   - Expected   128.00, actual   142.00 ( 1.11x)
Window at  20 - Testing collisions   - Expected   128.00, actual   168.00 ( 1.31x)
Window at  21 - Testing collisions   - Expected   128.00, actual   128.00 ( 1.00x)
Window at  22 - Testing collisions   - Expected   128.00, actual   112.00 ( 0.88x)
Window at  23 - Testing collisions   - Expected   128.00, actual   132.00 ( 1.03x)
Window at  24 - Testing collisions   - Expected   128.00, actual   126.00 ( 0.98x)
Window at  25 - Testing collisions   - Expected   128.00, actual   108.00 ( 0.84x)
Window at  26 - Testing collisions   - Expected   128.00, actual   104.00 ( 0.81x)
Window at  27 - Testing collisions   - Expected   128.00, actual    92.00 ( 0.72x)
Window at  28 - Testing collisions   - Expected   128.00, actual    52.00 ( 0.41x)
Window at  29 - Testing collisions   - Expected   128.00, actual    48.00 ( 0.38x)
Window at  30 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  31 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
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
Window at  45 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  46 - Testing collisions   - Expected   128.00, actual    96.00 ( 0.75x)
Window at  47 - Testing collisions   - Expected   128.00, actual    56.00 ( 0.44x)
Window at  48 - Testing collisions   - Expected   128.00, actual   108.00 ( 0.84x)
Window at  49 - Testing collisions   - Expected   128.00, actual   126.00 ( 0.98x)
Window at  50 - Testing collisions   - Expected   128.00, actual   128.00 ( 1.00x)
Window at  51 - Testing collisions   - Expected   128.00, actual   218.00 ( 1.70x)
Window at  52 - Testing collisions   - Expected   128.00, actual   116.00 ( 0.91x)
Window at  53 - Testing collisions   - Expected   128.00, actual    98.00 ( 0.77x)
Window at  54 - Testing collisions   - Expected   128.00, actual   108.00 ( 0.84x)
Window at  55 - Testing collisions   - Expected   128.00, actual    80.00 ( 0.63x)
Window at  56 - Testing collisions   - Expected   128.00, actual    86.00 ( 0.67x)
Window at  57 - Testing collisions   - Expected   128.00, actual    74.00 ( 0.58x)
Window at  58 - Testing collisions   - Expected   128.00, actual    72.00 ( 0.56x)
Window at  59 - Testing collisions   - Expected   128.00, actual   102.00 ( 0.80x)
Window at  60 - Testing collisions   - Expected   128.00, actual   144.00 ( 1.13x)
Window at  61 - Testing collisions   - Expected   128.00, actual   116.00 ( 0.91x)
Window at  62 - Testing collisions   - Expected   128.00, actual    68.00 ( 0.53x)
Window at  63 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)
Window at  64 - Testing collisions   - Expected   128.00, actual     0.00 ( 0.00x)

[[[ Keyset 'Text' Tests ]]]

Keyset 'Text' - keys of form "Foo[XXXX]Bar" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 26208.00 ( 1.03x)
Testing distribution - Worst bias is the  20-bit window at bit  23 - 0.016%

Keyset 'Text' - keys of form "FooBar[XXXX]" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 25568.00 ( 1.01x)
Testing distribution - Worst bias is the  20-bit window at bit   3 - 0.031%

Keyset 'Text' - keys of form "[XXXX]FooBar" - 14776336 keys
Testing collisions   - Expected 25418.13, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit  20 - 0.005%


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 65536 keys
Testing collisions   - Expected     0.50, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  13-bit window at bit   6 - 0.288%


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' - 1000000 keys
Testing collisions   - Expected   116.42, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit  29 - 0.099%



Input vcode 0x0a20908c, Output vcode 0x81d485d8, Result vcode 0x00000001
Verification value is 0x37259805 - Testing took 1953.472000 seconds
-------------------------------------------------------------------------------
```