#include "SimAnneal.h"

#include "Types.h"
#include "Random.h"

//-----------------------------------------------------------------------------
// Pseudo-simulated-annealing

double SimAnneal ( void * block, int len, pfFitness fit, pfDump dump, int nFlip, int reps )
{
	double baseScore = fit(block,len);
	double tempScore = 0;
	double bestScore = 0;

	uint8_t * baseBlock = new uint8_t[len];
	uint8_t * tempBlock = new uint8_t[len];
	uint8_t * bestBlock = new uint8_t[len];

	memcpy(baseBlock,block,len);
	memcpy(tempBlock,block,len);
	memcpy(bestBlock,block,len);

	while(nFlip)
	{
		printf("fit - %f, bits - %2d, dump - ",baseScore,nFlip);

		dump(baseBlock,len);

		bestScore = baseScore;

		if(nFlip == 1)
		{
			for(int i = 0; i < len*8; i++)
			{
				printf(".");

				memcpy(tempBlock,baseBlock,len);
				flipbit(tempBlock,len,i);

				tempScore = fit(tempBlock,len);

				if(tempScore > bestScore)
				{
					bestScore = tempScore;
					memcpy(bestBlock,tempBlock,len);
					break;
				}
			}
		}
		else
		{
			for(int i = 0; i < reps; i++)
			{
				//if(i % (reps/10) == 0) printf(".");
				printf(".");

				memcpy(tempBlock,baseBlock,len);

				for(int i = 0; i < nFlip; i++)
				{
					flipbit( tempBlock, len, rand_u32() % (len*8) );
				}

				tempScore = fit(tempBlock,len);

				if(tempScore > bestScore)
				{
					bestScore = tempScore;
					memcpy(bestBlock,tempBlock,len);
					break;
				}
			}
		}

		printf("\n");

		// If we found a better solution, expand space starting from that solution
		// Otherwise, shrink space around previous best

		if(bestScore > baseScore)
		{
			memcpy(baseBlock,bestBlock,len);
			baseScore = bestScore;

			nFlip++;
		}
		else
		{
			nFlip--;
		}
	}

	memcpy(block,baseBlock,len);
	return baseScore;
}


