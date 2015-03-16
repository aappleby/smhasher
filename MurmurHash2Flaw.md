Let's look at what happens in Murmur2's inner loop when processing 'bad' keys of the form "`uint32_t key[2] = {x,x};`" -

Here's the loop as written
```
while(len >= 4)
{
    uint32_t k = *(uint32_t*)data;

    // we'll call this the 'pre-mix' step

    k *= m;
    k ^= k >> r;
    k *= m;

    // and this the 'merge' step
    h *= m;
    h ^= k;

    data += 4;
    len -= 4;
}
```

Since the two uint32\_t's from the key are the same value 'x' the results of the pre-mix for both passes through the loop will be the same, so we can unroll this as

```
x *= m;
x ^= x >> r;
x *= m;

h *= m;
h ^= x;
h *= m;
h ^= x;
```

Now, what happens if m == 1?

```
x ^= x >> r;

h ^= x;
h ^= x;
```

X completely cancels out and does not affect the hash. All keys hash to the same value.

Luckily we're not using m == 1, right? Well, unfortunately we're not that lucky - there's still a lot of cancellation. If I evaluate

```
uint32_t test ( uint32_t x )
{
    const uint32_t m = 0x5bd1e995;
    const int r = 24;

    uint32_t h = 0;

    x *= m;
    x ^= x >> r;
    x *= m;

    h *= m
    h ^= x;
    h *= m
    h ^= x;

    return h;
}
```

for all possible values of x, I only get 172,013,942 unique results instead of the 2^32 expected. That means we're getting ~4.6 bits cancelled out on average. Not good.

Will this flaw cause your program to fail? Probably not - what this means in real-world terms is that if your keys contain repeated 4-byte values AND they differ only in those repeated values AND the repetitions fall on a 4-byte boundary, then your keys will collide with a probability of about 1 in 2<sup>27.4</sup> instead of 2<sup>32</sup>. Due to the birthday paradox, you should have a better than 50% chance of finding a collision in a group of 13115 bad keys instead of 65536.

Can this be patched up by choosing a different value of 'm'? Unfortunately not. Different values produce different amounts of cancellation, but there is always cancellation - the low bit of h will always end up 0 no matter which multiplier you use.

MurmurHash3 uses a much different mix setup that eliminates this problem and runs considerably faster than MurmurHash2, so if this flaw does prove to be a problem for your application you should be able to switch to MurmurHash3 without losing performance.