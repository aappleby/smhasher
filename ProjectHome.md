# [SMHasher](SMHasher.md) & MurmurHash #

This webpage is the new home for the MurmurHash family of hash functions along with the SMHasher test suite used to verify them. SMHasher is released under the MIT license. All MurmurHash versions are public domain software, and the author disclaims all copyright to their code.

[SMHasher](SMHasher.md) is a test suite designed to test the distribution, collision, and performance properties of non-cryptographic hash functions - it aims to be the "[DieHarder](http://www.phy.duke.edu/~rgb/General/dieharder.php)" of hash testing, and does a pretty good job of finding flaws with a number of popular hashes.

The [SMHasher](SMHasher.md) suite also includes MurmurHash3, which is the latest version in the series of MurmurHash functions - the new version is faster, more robust, and its variants can produce 32- and 128-bit hash values efficiently on both x86 and x64 platforms.


## Updates ##

### 5/10/2012 ###

A couple minor updates -

> - The main implementations of Murmur are written to be as clear as possible at the expense of some cross-platform compatibility. Shane Day offered to put together an implementation of Murmur3\_x86\_32 that should compile on virtually any platform and which passes the Murmur3 verification test, and I've now merged his code into the repo.

> - Speaking of verification tests, folks have asked me to post the output of hashing "The quick brown fox..." or some equivalent string so they can test their implementations of Murmur. There's actually a more robust test already in KeysetTest.cpp - the VerificationTest() function produces a 32-bit result for a given hash that, if the output matches what's in main.cpp, should indicate for certain whether an implementation is correct or not. The code is straightforward and unambiguous - translating it into other languages should be easy. If you're really paranoid, you should also implement something equivalent to SanityTest() for your platform - if a hash function passes both VerificationTest() and SanityTest() it should be reliable.

> - I'm clearing out bugs in the bug list, most of which have been there since I created this project. There are a few minor tweaks to SMHasher that'll get checked in shortly.


### 2/29/2012 ###

I'd like to move the SMHasher repo to something Git-based - this could either be the built-in Git hosting on code.google.com, or an external site like Github.com. SMHasher isn't a particularly popular project, but if you're reading this and you have a preference one way or the other please let me know.

### 6/3/2011 ###

A few users have asked if I'll be changing Murmur3 again, or if it's really really locked down now.

So - yes - MurmurHash3 as of [revision 136](https://code.google.com/p/smhasher/source/detail?r=136) is the final final version. Any future changes will be to improve performance only, any constant or algorithm changes will be reserved for MurmurHash4 if they're needed.


### 5/20/2011 ###

Murmur3\_x86\_32 had a typo - the rotation constant in the tail mix was 16 where it should've been 15 to match the body. This is fixed in the latest changelist - hash quality should be unaffected, but the verification value has changed.

### 4/11/2011 ###

Another batch of cross-platform fixes have gone in; code should hopefully compile correctly under clang-based frontends.

Murmur1/2/3.cpp/h will now compile standalone - copy/pasting them into your application should work without modifications. They also have explicit "this code is public domain" statements at the top of the files.

A few typos were found in murmur3 and have been fixed (one rotl value was wrong, a few "h ^= len" operations were missing) - verification values for self-test have been updated.


### 4/2/2011 ###

MurmurHash3, all versions, is final.

I spent the last couple of days revamping the 128-bit versions, and I'm quite pleased with the results - performance is now good on both Core 2 and Core i5/i7 platforms, and GCC seems to optimize things much better. I also trimmed instructions where possible, and the x64 version's latency is down to ~30 cycles for small (~16-byte) keys.

More importantly (to me, at least) is that all versions now use the same basic mix operations and share the same overall structure, so extending them to larger/smaller hash sizes or for streaming and incremental operation should be straightforward. I find the resulting consistency to be quite nice.

Full test run results are here - these were generated on a Core i5 M 560 notebook from code compiled by Visual Studio 2008 in x64 mode. I'll see about generating some pretty graphs later.

  * [MurmurHash3\_x86\_32](MurmurHash3_x86_32.md) - ~3 gigs/second, ~29 cycles per a 16-byte key
  * [MurmurHash3\_x86\_128](MurmurHash3_x86_128.md) - ~4 gigs/second, ~54 cycles per a 16-byte key
  * [MurmurHash3\_x64\_128](MurmurHash3_x64_128.md) - ~7.5 gigs/second, ~30 cycles per 16-byte key
  * [lookup3](lookup3.md) results for comparison - ~1.5 gigs/second, ~42 cycles per 16-byte key

(Note that performance numbers are scaled to be relative to a 3 gigahertz processor)

Other interesting changes -

All versions now have a strong finalization step. It turned out to be faster to trim unnecessary operations off the tail block and use the strong finalizer than to leave them and weaken the finalizer, so that's what I did.

The dynamic mixing constants are gone. With the extra rotate added to the mix step they're no longer needed (the rotate does enough pattern-breaking), and they made implementing streaming versions of the hashes more difficult as they made the hash stateful.

### 4/1/2011 ###

Darn it, I added a new test and it found a tiny flaw in Murmur3a even though I declared it final a few weeks ago.

The new test is called TwoBytes, it generates all keys up to length N with two non-zero bytes. For N=4, Murmur3a generated just over twice as many collisions as would be expected. This was due to there really being no mixing between the last `h1 ^= k1` operation and the `h1 ^= len` operation, and if the key was really tiny the difference in 'len' would cancel out the difference in 'k1'.

By itself that's not an issue to be worried about, but it does suggest that it might be possible to generate colliding keys of length N and N-1, where the difference in the intermediate hash values was cancelled out by the difference in lengths.

I've reordered the operations a bit and tweaked the mixing constants to try and prevent this from happening again, and once again Murmur3a passes all tests in the test suite. Performance went down a few percent on some platforms (Core 2 x86), up a few percent on others (Core i5/i7 x64).

For some reason Core i5 x86 performance of Murmur3a on the bulk speed test is still much lower (30%-ish) than Core 2 x86, even with the same compiler & optimizations. Murmur3f on Core i5 x64 is much faster than on Core 2 x64 though, hitting around 2.4 bytes per cycle.


### 3/20/2011 ###

The codebase now compiles and runs using CMake under Visual Studio 20xx, Cygwin + GCC 4.3.4, MinGW, OSX, Ubuntu, and should hopefully do the same under other GCC variants. SMHasher also does a self-test on startup that verifies that all installed hash functions produce the same results as they do on the original (Visual Studio 2008) platform, so everything should be working correctly.

For safety's sake, I'll also be adding a verification value that'll show up at the end of the test run - if the verification values match on both platforms, then every result of every test should match as well.

Thanks to McKay Davis for providing his list of cross-platform fixes.

### 2/27/2011 ###

Murmur3\_x86\_32 is finalized. It has received a few minor tweaks - one extra rotate in the mix step, some reordering to improve pipelining on x86 platforms, and one operation was removed from the finalization step.

The extra rotate was needed to fix an issue where a contrived keyset consisting of 32-bit bit blocks with only the high bits set would collide more often than expected - hardly a real-world case, but I'm erring on the side of caution. The final version is a very conservative design, all things considered - it does enough interesting things to its input that there seems to be no obvious way to induce degenerate behavior.

I'm confident enough in this variant of Murmur3 now that I'm offering a small reward to anyone who can find a keyset that breaks it - if you can programmatically generate a keyset that does _not_ use any of Murmur3's internal constants(1) and that still causes a statistically improbable number of hash collisions, you will receive a $50 gift certificate to Amazon and your code will become a new SMHasher test case.

(1) - because otherwise you could write code that runs Murmur3 backwards, in effect, and generate as many collisions as you want


Other notes for the latest code -

- Murmur3\_x86\_64, Murmur3\_x64\_32, and Murmur3\_x64\_64 have been removed. If you're doing hash table lookup, use Murmur3\_x86\_32 - it works well on either platform and has much lower latency than x64\_128. If you're generating unique IDs for blobs of data, you should be using at least a 128-bit hash.

- The sanity testing code is much more thorough

- The sparse block tests now include an "all combinations of N blocks from a set of M" test, which is able to put a dent in Bob Jenkins' lookup3 (which had been unscathed until now)





### 1/13/2011 ###
I'm now employed by Google, and will likely be spending a good chunk of my spare time improving [SMHasher](SMHasher.md). The next tasks I'll be tackling will be to make the codebase compile and run cross-platform via CMake, and changing the tests to accept an arbitrarily-sized chunk of data as the "seed" parameter.

### 11/4/2010 ###
[SMHasher](SMHasher.md) & MurmurHash3 are now in beta, and the source code for them can be checked out via subversion using the 'Source' tab above. I've copied the log for a test run of all MurmurHash3 variants to [SMHasherDump](SMHasherDump.md)

MurmurHash3 is the successor to MurmurHash2 - it fixes a flaw that was found in MurmurHash2 and improves performance considerably - for 64-bit platforms, the improvement is quite dramatic. It contains variants that efficiently generate 32/64/128-bit hash values for both x86 and x64 platforms.

SMHasher contains all the test code that I've used to verify MurmurHash3, and it's been generic-ified enough that it should be able to analyze any N-bit hash function given a reference implementation and a small adapter stub.

Stuff that doesn't work yet -

  * The code will probably only compile under Visual Studio without some serious work
  * There's no real command line interface to speak of