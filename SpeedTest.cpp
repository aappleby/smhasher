#include "SpeedTest.h"

#include "Random.h"

#include <stdio.h>   // for printf
#include <memory.h>  // for memset

//-----------------------------------------------------------------------------
// 256k blocks seem to give the best results.

void BulkSpeedTest ( pfHash hash, uint32_t seed )
{
  Rand r(seed);
  
  const int trials = 9999;
  const int blocksize = 256 * 1024;

  printf("Bulk speed test - %d-byte keys\n",blocksize);

  uint8_t * block = new uint8_t[blocksize + 16];

  r.rand_p(block,blocksize+16);

  uint32_t temp[16];

  for(int align = 0; align < 8; align++)
  {
    double bestbpc = 0;

    for(int itrial = 0; itrial < trials; itrial++)
    {
      int64_t begin,end;

      begin = rdtsc();

      hash(block + align,blocksize,itrial,temp);

      end = rdtsc();

      blackhole(temp[0]);

      double cycles = double(end-begin);
      if(cycles > 0)
      {
        double bpc = double(blocksize) / cycles;
        if(bpc > bestbpc) bestbpc = bpc;
      }
    }

    double bestbps = (bestbpc * 3000000000.0 / 1048576.0);
    printf("Alignment %2d - %6.3f bytes/cycle - %7.2f MiB/sec @ 3 ghz\n",align,bestbpc,bestbps);
  }

  delete [] block;
}

//-----------------------------------------------------------------------------

void TinySpeedTest ( pfHash hash, int hashsize, int keysize, uint32_t seed, bool verbose, double & outCycles )
{
  const int trials = 100000;

  if(verbose) printf("Small key speed test - %4d-byte keys - ",keysize);
  
  Rand r(seed);

  uint8_t * h = new uint8_t[hashsize];
  uint8_t * k = new uint8_t[keysize];
  
  memset(h,0,hashsize);
  memset(k,0,keysize);

  double bestcycles = 1e9;

  for(int itrial = 0; itrial < trials; itrial++)
  {
    volatile int64_t begin,end;

    rand_p(k,keysize);

    MixVCode(h,4);
    
    begin = rdtsc();
    
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);

    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);

    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);

    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);
    hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);   hash(k,keysize,itrial,h);

    end = rdtsc();

    MixVCode(h,4);
    //printf("0x%08x\n",g_verify);

    double cycles = double(end-begin) / 64;
    if((cycles > 0) && (cycles < bestcycles)) bestcycles = cycles;
  }

  double bestbpc = double(keysize) / bestcycles;
  if(verbose) printf("%8.2f cycles/hash, %8.4f bytes/cycle\n",bestcycles,bestbpc);

  outCycles = bestcycles;
}

//-----------------------------------------------------------------------------
