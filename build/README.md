
## Build instructions

_Tested on Ubuntu 20.04._

Install dependencies:
```bash
sudo apt update && sudo apt install cmake
```

Build with `cmake`:
```bash
cd build
cmake ../src     # run cmake to make the makefile
make             # run make to build the executable
time ./SMHasher  # run the executable, timing how long it takes
```

## Sample output

An example run-time of `./SMHasher` is 25 minutes. 

Here is an example output:

```
smhasher/build$ time ./SMHasher
(No test hash given on command line, testing Murmur3_x86_32.)
-------------------------------------------------------------------------------
--- Testing Murmur3A (MurmurHash3 for x86, 32-bit)

[[[ Sanity Tests ]]]

Verification value 0xB0F57EE3 : Passed!
Running sanity check 1..........PASS
Running sanity check 2..........PASS

[[[ Speed Tests ]]]

Bulk speed test - 262144-byte keys
Alignment  0 -  0.954 bytes/cycle - 2730.19 MiB/sec @ 3 ghz
Alignment  1 -  0.954 bytes/cycle - 2730.28 MiB/sec @ 3 ghz
Alignment  2 -  0.954 bytes/cycle - 2730.25 MiB/sec @ 3 ghz
Alignment  3 -  0.954 bytes/cycle - 2730.26 MiB/sec @ 3 ghz
Alignment  4 -  0.954 bytes/cycle - 2730.25 MiB/sec @ 3 ghz
Alignment  5 -  0.949 bytes/cycle - 2715.86 MiB/sec @ 3 ghz
Alignment  6 -  0.925 bytes/cycle - 2645.99 MiB/sec @ 3 ghz
Alignment  7 -  0.907 bytes/cycle - 2595.79 MiB/sec @ 3 ghz

Small key speed test -    1-byte keys -    31.69 cycles/hash
Small key speed test -    2-byte keys -    31.36 cycles/hash
Small key speed test -    3-byte keys -    30.26 cycles/hash
Small key speed test -    4-byte keys -    30.64 cycles/hash
Small key speed test -    5-byte keys -    31.95 cycles/hash
Small key speed test -    6-byte keys -    33.11 cycles/hash
Small key speed test -    7-byte keys -    32.25 cycles/hash
Small key speed test -    8-byte keys -    29.48 cycles/hash
Small key speed test -    9-byte keys -    34.72 cycles/hash
Small key speed test -   10-byte keys -    32.31 cycles/hash
Small key speed test -   11-byte keys -    33.02 cycles/hash
Small key speed test -   12-byte keys -    30.85 cycles/hash
Small key speed test -   13-byte keys -    33.28 cycles/hash
Small key speed test -   14-byte keys -    32.34 cycles/hash
Small key speed test -   15-byte keys -    31.81 cycles/hash
Small key speed test -   16-byte keys -    31.64 cycles/hash
Small key speed test -   17-byte keys -    33.23 cycles/hash
Small key speed test -   18-byte keys -    32.92 cycles/hash
Small key speed test -   19-byte keys -    32.85 cycles/hash
Small key speed test -   20-byte keys -    35.25 cycles/hash
Small key speed test -   21-byte keys -    35.94 cycles/hash
Small key speed test -   22-byte keys -    35.53 cycles/hash
Small key speed test -   23-byte keys -    48.35 cycles/hash
Small key speed test -   24-byte keys -    41.27 cycles/hash
Small key speed test -   25-byte keys -    41.77 cycles/hash
Small key speed test -   26-byte keys -    37.33 cycles/hash
Small key speed test -   27-byte keys -    36.49 cycles/hash
Small key speed test -   28-byte keys -    38.08 cycles/hash
Small key speed test -   29-byte keys -    38.37 cycles/hash
Small key speed test -   30-byte keys -    38.22 cycles/hash
Small key speed test -   31-byte keys -    37.64 cycles/hash

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
Testing  40-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.669333%
Testing  48-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.544667%
Testing  56-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.663333%
Testing  64-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.680000%
Testing  72-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.588000%
Testing  80-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.630667%
Testing  88-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.636667%
Testing  96-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.654667%
Testing 104-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.670667%
Testing 112-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.698667%
Testing 120-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.662667%
Testing 128-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.598000%
Testing 136-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.681333%
Testing 144-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.698000%
Testing 152-bit keys ->  32-bit hashes,   300000 reps.......... worst bias is 0.656000%

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
Testing collisions   - Expected    49.57, actual    20.00 ( 0.40x)
Testing distribution - Worst bias is the  16-bit window at bit  23 - 0.201%

Keyset 'TwoBytes' - up-to-8-byte keys, 5471025 total keys
Testing collisions   - Expected  3484.56, actual  3089.00 ( 0.89x)
Testing distribution - Worst bias is the  20-bit window at bit  16 - 0.061%

Keyset 'TwoBytes' - up-to-12-byte keys, 18616785 total keys
Testing collisions   - Expected 40347.77, actual 39454.00 ( 0.98x)
Testing distribution - Worst bias is the  20-bit window at bit   1 - 0.015%

Keyset 'TwoBytes' - up-to-16-byte keys, 44251425 total keys
Testing collisions   - Expected 227963.15, actual 225188.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit  23 - 0.005%

Keyset 'TwoBytes' - up-to-20-byte keys, 86536545 total keys
Testing collisions   - Expected 871784.70, actual 864247.00 ( 0.99x)
Testing distribution - Worst bias is the  20-bit window at bit  25 - 0.003%


[[[ Keyset 'Sparse' Tests ]]]

Keyset 'Sparse' - 32-bit keys with up to 6 bits set - 1149017 keys
Testing collisions   - Expected   153.70, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit   8 - 0.055%

Keyset 'Sparse' - 40-bit keys with up to 6 bits set - 4598479 keys
Testing collisions   - Expected  2461.72, actual  2318.00 ( 0.94x)
Testing distribution - Worst bias is the  19-bit window at bit  14 - 0.060%

Keyset 'Sparse' - 48-bit keys with up to 5 bits set - 1925357 keys
Testing collisions   - Expected   431.55, actual   392.00 ( 0.91x)
Testing distribution - Worst bias is the  17-bit window at bit   3 - 0.050%

Keyset 'Sparse' - 56-bit keys with up to 5 bits set - 4216423 keys
Testing collisions   - Expected  2069.66, actual  2033.00 ( 0.98x)
Testing distribution - Worst bias is the  19-bit window at bit  20 - 0.032%

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
Testing distribution - Worst bias is the  20-bit window at bit  17 - 0.017%

Keyset 'Text' - keys of form "FooBar[XXXX]" - 14776336 keys
Testing collisions   - Expected 25418.13, actual 25450.00 ( 1.00x)
Testing distribution - Worst bias is the  20-bit window at bit   1 - 0.026%

Keyset 'Text' - keys of form "[XXXX]FooBar" - 14776336 keys
Testing collisions   - Expected 25418.13, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit   5 - 0.004%


[[[ Keyset 'Zeroes' Tests ]]]

Keyset 'Zeroes' - 65536 keys
Testing collisions   - Expected     0.50, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  13-bit window at bit   6 - 0.288%


[[[ Keyset 'Seed' Tests ]]]

Keyset 'Seed' - 1000000 keys
Testing collisions   - Expected   116.42, actual     0.00 ( 0.00x)
Testing distribution - Worst bias is the  17-bit window at bit  26 - 0.069%



Input vcode 0x7c689bd5, Output vcode 0xcd694af9, Result vcode 0x00000001
Verification value is 0x00000001 - Testing took 1544.196935 seconds
-------------------------------------------------------------------------------

real    25m47.426s
user    25m36.798s
sys 0m7.414s
```