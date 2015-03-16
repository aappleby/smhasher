MurmurHash1 was an early experiment to see if I could create a hash function faster than Bob Jenkin's Lookup3. I succeeded, but the lack of a good test suite to determine if it produced acceptable quality hash values was what motivated SMHasher.

MurmurHash1's mix function is

```
h += k;
h *= m;
h ^= h >> r;
```

where 'k' is a block of the key, 'm' and 'r' are constants, and 'h' is the 32-bit hash state. This works better than you'd expect given the almost trivial simplicity, but it wasn't dramatically better than previous hash functions and so I kept experimenting.