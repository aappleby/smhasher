#include "DictionaryTest.h"

#include <intrin.h>

#pragma warning(disable:4996) // fopen is unsafe


wordlist g_words;
int g_wordcount = 0;

const char ** g_pwords = NULL;
int * g_plengths = NULL;

double g_dictoverhead = 0;

//----------------------------------------------------------------------------

void LoadWords ( void )
{
	FILE * f = fopen("allwords.txt","r");

	char buffer[1024];

	while(fgets(buffer,1024,f))
	{
		char * cursor = buffer + strlen(buffer);

		while((*cursor == 0x0a) || (*cursor == 0))
		{
			*cursor = 0;
			cursor--;
		}

		g_words.push_back(buffer);
	}

	fclose(f);

	g_wordcount = (int)g_words.size();

	printf("Loaded %d words\n",g_wordcount);

	g_pwords = new const char*[g_wordcount];
	g_plengths = new int[g_wordcount];

	for(int i = 0; i < g_wordcount; i++)
	{
		g_pwords[i] = g_words[i].c_str();
		g_plengths[i] = (int)g_words[i].size();
	}
}

void DeleteWords ( void )
{
	delete [] g_pwords;
	delete [] g_plengths;

	g_words.clear();
}

//----------------------------------------------------------------------------
