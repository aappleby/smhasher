/*
 *  Copyright (c) 2016 Positive Technologies, https://www.ptsecurity.com,
 *  Fast Positive Hash.
 *
 *  Portions Copyright (c) 2010-2013 Leonid Yuriev <leo@yuriev.ru>,
 *  The 1Hippeus project (t1h).
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgement in the product documentation would be
 *     appreciated but is not required.
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  3. This notice may not be removed or altered from any source distribution.
 */

/*
 * t1ha = { Fast Positive Hash, aka "Позитивный Хэш" }
 * by [Positive Technologies](https://www.ptsecurity.ru)
 *
 * Briefly, it is a 64-bit Hash Function:
 *  1) For 64-bit platforms, in predominantly for x86_64.
 *  2) 5-10% faster than City64 from Google:
 *      - with approximately the same quality,
 *      - but has bit more regular structure and less code size.
 *  3) Not suitable for cryptography.
 *
 * ACKNOWLEDGEMENT:
 * The t1ha was originally developed by Leonid Yuriev for The 1Hippeus project.
 * 1Hippeus - zerocopy messaging in the spirit of Sparta!
 */

#include "t1ha.h"
#include <string.h>

#if !defined(__GNUC__) || !__GNUC_PREREQ(4, 2)
#error Sorry, t1ha requires modern GCC compiler (gcc 4.2 or compatible).
#endif

#if !defined(__BYTE_ORDER__) || !defined(__ORDER_LITTLE_ENDIAN__) ||           \
    !defined(__ORDER_BIG_ENDIAN__)
#error __BYTE_ORDER__ should be defined.
#endif

#if !defined(UNALIGNED_OK)
#if defined(__i386) || defined(__x86_64) || defined(_M_IX86)
#define UNALIGNED_OK 1
#else
#define UNALIGNED_OK 0
#endif
#endif

static __inline uint64_t fetch(const uint64_t *v) {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  return *v;
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  return __builtin_bswap64(*v);
#else
#error Unsupported byte order.
#endif
}

/* 'magic' primes */
static const uint64_t p0 = 17048867929148541611ull;
static const uint64_t p1 = 9386433910765580089ull;
static const uint64_t p2 = 15343884574428479051ull;
static const uint64_t p3 = 13662985319504319857ull;
static const uint64_t p4 = 11242949449147999147ull;
static const uint64_t p5 = 13862205317416547141ull;
static const uint64_t p6 = 14653293970879851569ull;

/* rotations */
static const unsigned s0 = 41;
static const unsigned s1 = 17;
static const unsigned s2 = 31;

/* cyclic rotation */
static __inline uint64_t rot(uint64_t v, unsigned s = s1) {
  return (v >> s) | (v << (sizeof(v) * 8 - s));
}

/* xor-mul-xor mixer */
static __inline uint64_t mix(uint64_t a, uint64_t b, uint64_t p = p0) {
  uint64_t m = (a ^ b) * p;
  return m ^ rot(m, s0);
}

uint64_t t1ha(const void *data, size_t len, uint64_t seed) {
  uint64_t left = len;
  uint64_t a = seed;
  uint64_t b = len;
  uint64_t c = rot(len) + seed;
  uint64_t d = len ^ rot(seed);

  const bool need_align =
      ((uintptr_t)data) % sizeof(uint64_t) != 0 && !UNALIGNED_OK;
  const uint64_t *v = (const uint64_t *)data;
  uint64_t align[4];

  for (;;) {
    if (need_align) {
      memcpy(&align, data, (sizeof(align) > left) ? left : sizeof(align));
      data = (const uint64_t *)data + 4;
      v = align;
    }

    switch (left) {
    case sizeof(uint64_t) * 3 + 1 ... sizeof(uint64_t) * 4 - 1:
      d ^= p4 * rot(a += fetch(v++));
    case sizeof(uint64_t) * 2 + 1 ... sizeof(uint64_t) * 3:
      c ^= p3 * rot(b += fetch(v++));
    case sizeof(uint64_t) + 1 ... sizeof(uint64_t) * 2:
      left &= sizeof(uint64_t) - 1;
      b = mix(b, c += fetch(v++), p2);
    case 1 ... sizeof(uint64_t):
      a = mix(a, rot(d += (fetch(v) << (8 * (sizeof(uint64_t) - left))), s2),
              p1);
    case 0:
      return mix(rot(a + d) + b, mix(a + c, b));
    }

    do {
      uint64_t w0 = fetch(v + 0);
      uint64_t w1 = fetch(v + 1);
      uint64_t w2 = fetch(v + 2);
      uint64_t w3 = fetch(v + 3);

      uint64_t d02 = w0 ^ rot(w2 + d);
      uint64_t c13 = w1 ^ rot(w3 + c);
      c += a ^ rot(w0, s0);
      d -= b ^ rot(w1, s2);
      a ^= p5 * (d02 + w3);
      b ^= p6 * (c13 + w2);

      v += 4;
      left -= sizeof(uint64_t) * 4;
    } while (!need_align && left >= sizeof(uint64_t) * 4);
  }
}
