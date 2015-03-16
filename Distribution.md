# Introduction #

How do you determine how "good" a hash function is?

Well, there are two essential properties a hash function should have -

- It should ensure that two different keys are no more likely than random chance to produce the same hash value

- No matter what type of keys are used, a hash table built using the hash function should have its keys distributed randomly between the table cells.

The fist criteria isn't that hard to measure if the problem is trimmed down to "keys differing in less than N bits" - that makes the problem space pretty easy to search, and we have a straightforward definition of how likely collisions due to random chance are (hooray birthay paradox).

The second critera is quite fuzzy though - I can't possibly check all possible sets of all possible keys, and even if I could there's no clear line between "distributed randomly" and "distributed randomly _enough_".

One way to attack the problem would just be to say whether or not a distribution passes a statistical test called Pearson's test - if it passes, then the distribution is indistinguishable from random. This is way too strict a criteria though - we're not making cryptographic hash functions, and a distribution that is detectably non-random can still perform identically when used in a hash table.

My original solution to the second problem was to calculate a metric based on "expected work" which I'll call 'EW' - given a particular hash table distribution, how much work on average would it be to look up a key from the table and how does that compare with a theoretically ideal distribution? By dividing a distribution's EW by the ideal EW, we get a relative work metric 'RW' that equals 1 for an ideal distribution and goes up from there.

This worked pretty well, but had some serious problems -

- RW depends strongly on hash table size and key count, RW values for different configurations aren't directly comparable.

- RW has a constant lower bound but its upper bound can be enormous for the degenerate case of all keys hashing to the same table cell, and that bound also varies with table size & key count.

- RW is not nearly strict enough. Distributions with obvious statistical flaws can produce acceptable RWs.


What I really need is a metric that doesn't depend on table size or key count, that produces values in the range 0 (horrible) to 1 (optimal), that has a meaningful interpretation for values in the middle of the range, that has a strong statistical basis, and that is easy to compute.

After a bunch of experimentation and algebra, here's what I came up with -

Suppose I have a set of 'N' bins, into which I've randomly distributed 'K' keys. If my distribution really is random, then each each bin 'Bi' should contain around K/N keys (but not exactly K/N for all bins - that would hardly be random).

The expected work value need to find an arbitrary key in my bins is closely related to the root-mean-square average of the keys per bin - if each bin has ~10 or more keys in it, they two values are roughly proportional.

So, let's make a metric as follows -

For some value F in [1,N], I can construct a hypothetical set of bins which has all K keys distributed ideally randomly between the first F bins, and zero keys in bins F+1 through N. It should be pretty obvious that for F = 1 this is the worst possible distribution (all keys in one bin) and for F = N this is the best possible (all keys randomly distributed between N bins). For intermediate values of F, the distribution is still statistically well-defined and I can compute standard properties (mean, variance, rms) for it. Also, even though it makes the most sense for F to be an integer, there's nothing in the math constraining it to be so - I can define a continuous, monotonic function MR(F,N,K) that calculates the RMS (or mean, or variance) of my distribution for all integers F in [1,N] and for all real values between them.

More importantly, MR(F) is invertible - I can construct a function MF(R,N,K) that takes a an arbitrary RMS value and gives me the F value that'll construct one of my hypothetical distributions with that RMS.

With that bit of algebra solved, I can relate my test distribution to one of my F distributions quite directly, and use the resulting F as my metric - compute the RMS of the test distribution, run it through MF(R,N,K), and divide by N to get a value in the range (1/N,1).

Surprisingly, though MF takes N and K as an argument, the final metric is mostly independent of both. I can take my test distribution, multiply all the key counts by 2 and duplicate all the bins 3 times and still get the same metric out - the metric is a dimensionless numer that tells me "Your distribution is the same, RMS-wise, as a random distribution with its keys constrained to X percent of the bins" where X = 100 **(MF(RMS,N,K) / N).**

The only caveat is that (K/N) needs to be bigger than 5 or so, otherwise errors in some of the statistical approximations overwhelm the metric - since I'm the one writing the test suite and I get to decide how many keys to generate, this isn't really a problem.

The metric works great - it's easy to compute and easy to interpret, I don't have to tweak scaling factors to get the data into graphable form, and combined with some of my other tests it catches flaws in hash functions in an easy-to-spot way (for example, FNV would be a much better hash function if the output value was rotated right by 8 bits).