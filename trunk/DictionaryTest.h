#pragma once

#include "Types.h"
#include "Stats.h" // for testkeylist_string 

#include <map>

void LoadWords ( void );
void DeleteWords ( void );

typedef std::vector<std::string> wordlist;

extern wordlist g_words;
extern int g_wordcount;
extern const char ** g_pwords;
extern int * g_plengths;

//-----------------------------------------------------------------------------


template< typename hashtype >
double DictHashTest ( hashfunc<hashtype> hash )
{
	__int64 begin,end;

	const int reps = 999;

	double best = 1.0e90;

	for(int i = 0; i < reps; i++)
	{
		begin = __rdtsc();

		for(int i = 0; i < g_wordcount; i++)
		{
			const char * buffer = g_pwords[i];
			const int len = g_plengths[i];

			hash(buffer,len,0);
		}

		end = __rdtsc();
	
		double clocks = double(end-begin) / double(g_wordcount);

		if(clocks < best) best = clocks;
	}

	return best;
}

//-----------------------------------------------------------------------------

template< typename hashtype >
void DumpCollisions ( hashfunc<hashtype> hash )
{
	printf("\nDumping collisions for seed 0 - \n\n");

	typedef std::map<hashtype,std::vector<std::string>> hashmap;
	hashmap hashes;

	for(int i = 0; i < g_wordcount; i++)
	{
		hashtype h = hash(g_pwords[i],g_plengths[i],0);

		hashes[h].push_back(g_pwords[i]);
	}

	int collcount = 0;

	for(hashmap::iterator it = hashes.begin(); it != hashes.end(); it++)
	{
		hashtype hash = (*it).first;

		std::vector<std::string> & strings = (*it).second;

		if(strings.size() > 1)
		{
			collcount += (int)strings.size() - 1;

			printf("0x%08x - ",hash);

			for(int i = 0; i < (int)strings.size(); i++)
			{
				printf("%20s,",strings[i].c_str());
			}

			printf("\n");
		}
	}

	printf("%d collisions\n",collcount);
}

//----------------------------------------------------------------------------

template< typename hashtype >
void DictionaryTest ( hashfunc<hashtype> hash )
{
	printf("Dictionary-based tests -\n");
	printf("\n");

	LoadWords();

	double clocks = DictHashTest<hashtype>(hash);

	printf("All words hashed in min %f clocks/word\n",clocks);
	printf("\n");

	printf("Testing dictionary stats\n");
	testkeylist_string<hashtype>(hash,g_words,true,true);
	printf("\n");

	DumpCollisions(hash);

	DeleteWords();
}

//-----------------------------------------------------------------------------
