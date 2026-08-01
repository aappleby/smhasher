/*
 *  Copyright (c) 2016 Positive Technologies, https://www.ptsecurity.com,
 *  Fast Positive Hash.
 *
 *  Portions Copyright (c) 2010-2016 Leonid Yuriev <leo@yuriev.ru>,
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
 *  1. Created for 64-bit little-endian platforms, in predominantly for x86_64,
 *     but without penalties could runs on any 64-bit CPU.
 *  2. In most cases up to 15% faster than City64, xxHash, mum-hash, metro-hash
 *     and all others which are not use specific hardware tricks.
 *  3. Not suitable for cryptography.
 *
 * ACKNOWLEDGEMENT:
 * The t1ha was originally developed by Leonid Yuriev (Леонид Юрьев)
 * for The 1Hippeus project - zerocopy messaging in the spirit of Sparta!
 */

#include "t1ha.h"
#include <string.h>

#if !defined(__GNUC__) || (__GNUC__ < 4)
#error Sorry, t1ha requires modern GCC compiler (gcc 4.4 or compatible).
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

#define likely(cond) __builtin_expect(!!(cond), 1)
#define unlikely(cond) __builtin_expect(!!(cond), 0)

static __inline uint64_t fetch64(const void *v) {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  return *(const uint64_t *)v;
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  return __builtin_bswap64(*(const uint64_t *)v);
#else
#error Unsupported byte order.
#endif
}

static __inline uint64_t fetch32(const void *v) {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  return *(const uint32_t *)v;
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  return __builtin_bswap32(*(const uint32_t *)v);
#else
#error Unsupported byte order.
#endif
}

static __inline uint64_t fetch16(const void *v) {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  return *(const uint16_t *)v;
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
  return __builtin_bswap16(*(const uint16_t *)v);
#else
#error Unsupported byte order.
#endif
}

static __inline uint64_t fetch_tail(const void *v, size_t tail) {
  const uint8_t *_ = (const uint8_t *)v;
  switch (tail % sizeof(uint64_t)) {
  case 1:
    return _[0];
  case 2:
    return fetch16(_);
  case 3:
    return fetch16(_) | (_[2] << 16);
  case 4:
    return fetch32(_);
  case 5:
    return fetch32(_) | ((uint64_t)_[4] << 32);
  case 6:
    return fetch32(_) | (fetch16(_ + 4) << 32);
  case 7:
    return fetch32(_) | (fetch16(_ + 4) << 32) | ((uint64_t)_[6] << 48);
  case 0:
    return fetch64(_);
  default:
    __builtin_unreachable();
  }
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
static __inline uint64_t rot(uint64_t v, unsigned s) {
  return (v >> s) | (v << (sizeof(v) * 8 - s));
}

/* xor-mul-xor mixer */
static __inline uint64_t mix(uint64_t v, uint64_t p) {
  v *= p;
  return v ^ rot(v, s0);
}

#ifdef __SIZEOF_INT128__

/* xor high and low parts of full 128-bit product */
static __inline uint64_t mux(uint64_t v, uint64_t p) {
  __uint128_t r = (__uint128_t)v * (__uint128_t)p;
  /* modern GCC could nicely optimize this */
  return r ^ (r >> 64);
}

#else

static __inline uint64_t mul_32x32_64(uint32_t a, uint32_t b) {
  return a * (uint64_t)b;
}

static __inline unsigned add_with_carry(uint64_t *sum, uint64_t addend) {
  *sum += addend;
  return *sum < addend;
}

static uint64_t mux(uint64_t v, uint64_t p) {
  /* performs 64x64 to 128 bit multiplication */
  uint64_t ll = mul_32x32_64(v, p);
  uint64_t lh = mul_32x32_64(v >> 32, p);
  uint64_t hl = mul_32x32_64(p >> 32, v);
  uint64_t hh =
      mul_32x32_64(v >> 32, p >> 32) + (lh >> 32) + (hl >> 32) +
      /* Few simplification are possible here for 32-bit architectures,
       * but thus we would lost compatibility with the original 64-bit
       * version.  Think is very bad idea, because then 32-bit t1ha will
       * still (relatively) very slowly and well yet not compatible. */
      add_with_carry(&ll, lh << 32) + add_with_carry(&ll, hl << 32);
  return hh ^ ll;
}

#endif /* __SIZEOF_INT128__ */

uint64_t t1ha(const void *data, size_t len, uint64_t seed) {
  uint64_t left = len;
  uint64_t a = seed;
  uint64_t b = len;

  const int need_align =
      ((uintptr_t)data) % sizeof(uint64_t) != 0 && !UNALIGNED_OK;
  const uint64_t *v = (const uint64_t *)data;
  uint64_t align[4];

  if (left > sizeof(uint64_t) * 4) {
    uint64_t c = rot(len, s1) + seed;
    uint64_t d = len ^ rot(seed, s1);

    do {
      if (unlikely(need_align)) {
        v = (const uint64_t *)memcpy(
            &align, data, (sizeof(align) > left) ? left : sizeof(align));
        data = (const uint64_t *)data + 4;
      }

      uint64_t w0 = fetch64(v + 0);
      uint64_t w1 = fetch64(v + 1);
      uint64_t w2 = fetch64(v + 2);
      uint64_t w3 = fetch64(v + 3);

      uint64_t d02 = w0 ^ rot(w2 + d, s1);
      uint64_t c13 = w1 ^ rot(w3 + c, s1);
      c += a ^ rot(w0, s0);
      d -= b ^ rot(w1, s2);
      a ^= p1 * (d02 + w3);
      b ^= p0 * (c13 + w2);

      v += 4;
      left -= sizeof(uint64_t) * 4;
    } while (left >= sizeof(uint64_t) * 4);

    a ^= p6 * (rot(c, s1) + d);
    b ^= p5 * (c + rot(d, s1));
  }

  if (unlikely(need_align)) {
    v = (const uint64_t *)data;
    if (left > 1)
      v = (const uint64_t *)memcpy(&align, v, left);
  }

  switch (left) {
  case sizeof(uint64_t) * 3 + 1 ... sizeof(uint64_t) * 4:
    b += mux(fetch64(v++), p4);
  case sizeof(uint64_t) * 2 + 1 ... sizeof(uint64_t) * 3:
    a += mux(fetch64(v++), p3);
  case sizeof(uint64_t) + 1 ... sizeof(uint64_t) * 2:
    b += mux(fetch64(v++), p2);
  case 1 ... sizeof(uint64_t):
    a += mux(fetch_tail(v, left), p1);
  case 0:
    return mux(rot(a + b, s1), p4) + mix(a ^ b, p0);
  default:
    __builtin_unreachable();
  }
}
