# Introduction #

Once I've run a keyset through a hash function and used the hash values to create a hash table, how do I determine how "good" the table is?

A table with 1 full bucket and 1023 empty buckets is obviously bad, and a table where all buckets contain the same number of keys is probably too good to be random.

There are straightforward statistical tests (see Pearson's test) that can tell us how likely it was for a particular hash table to have been created by a perfectly random hash function, but these can be overly strict - we don't care if our table is _distinguishable_ from a random distribution, we only care if it is _less efficient_ than a random distribution.

If we define efficiency in terms of the average number of tests needed to determine whether or not a key is present in a hash table (which I'll call A()), then we can compute A(our distribution) / A(ideal distribution) and get a metric that starts at 1 and goes up from there. Unfortunately this metric will vary quite a bit with hash table size and key size, making it hard to compare results.

A better solution is to compare our distribution against "partially filled" distributions - ones which have their keys distributed perfectly randomly among X% of the buckets, with the remaining 100-X% completely empty. We compute the percentage X such that A(our distribution) = A(X% partially filled distribution), and use 100-X as our metric M.

The interpretation of M is roughly "The distribution we're testing is as efficient as a distribution that wastes M% of the hash table and uses the rest ideally".

After working through the algebra, it turns out we can compute M fairly easily -

```
double f = (k*k - 1) / (n*r*r - k);
return 1 - (f / n);
```

where 'k' is the number of keys in the hash table, 'n' is the number of buckets in the table, and 'r' is the root-mean-square value of the number of keys in each bucket.