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

#pragma once
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint64_t t1ha(const void *data, size_t len, uint64_t seed);

#ifdef __cplusplus
}
#endif
