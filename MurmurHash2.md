# Introduction #

MurmurHash2 is a previous version of MurmurHash, and was published in 2008. It was considerably speedier than MurmurHash1, but was discovered to have a [flaw](MurmurHash2Flaw.md) that, while not affecting most applications, was still worth fixing.

MurmurHash2's mix function is

```
k *= m;
k ^= k >> r;
k *= m;

h *= m;
h ^= k;
```

where 'k' is a block of the key, 'm' and 'r' are constants, and 'h' is the 32-bit hash state.


# Details #

Add your content here.  Format your content with:
  * Text in **bold** or _italic_
  * Headings, paragraphs, and lists
  * Automatic links to other wiki pages