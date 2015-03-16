There are three versions of MurmurHash -

MurmurHash1 was my first attempt, and was measurably faster than Bob Jenkins' lookup3 but not particularly robust.

MurmurHash2 was much, much faster and more robust. It has found its way into a lot of production codebases - it's used in code by Google, Microsoft, Yahoo, and many others.

MurmurHash3 is the current version. It was developed after a few people noticed some minor [flaws](MurmurHash2Flaw.md) in MurmurHash2. MurmurHash3 is a bit faster than MurmurHash2, and should be darn near bulletproof. It also has a super-speedy 128-bit variant for x64 processors, which is useful when trying to generate unique identifiers for large chunks of data.