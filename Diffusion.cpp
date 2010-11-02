#include "Diffusion.h"

#include "Types.h"

#include <memory.h>

//-----------------------------------------------------------------------------
// check invertibility of diffusion matrix

void TestDiffusionMatrix ( void )
{
	//int m[4] = { 3, 1, 1, 3 };

	int tab[65536];

	memset(tab,0,sizeof(tab));

	for(int i = 0; i < 65536; i++)
	{
		uint8_t a1 = (uint8_t)i;
		uint8_t a2 = (uint8_t)(i >> 8);

		//uint8_t b1 = uint8_t(a1 * m[0]) + uint8_t(a2*m[1]);
		//uint8_t b2 = uint8_t(a1 * m[2]) + uint8_t(a2*m[3]);

		uint8_t b1 = a1;
		uint8_t b2 = a2;

		b1 += b2;
		b2 += b1;

		int index = (int(b1) << 8) + b2;

		tab[index]++;
	}

	int missing = 0;

	for(int i = 0; i < 65536; i++)
	{
		if(tab[i] == 0) missing++;
	}

	printf("missing - %d\n",missing);
}

//-----------------------------------------------------------------------------

void add_row ( int m[16], int a, int b )
{
	for(int i = 0; i < 4; i++)
	{
		m[4*a+i] += m[4*b+i];
	}
}

void sub_row ( int m[16], int a, int b )
{
	for(int i = 0; i < 4; i++)
	{
		m[4*a+i] -= m[4*b+i];
	}
}

//-----------------------------------------------------------------------------
// search through diffusion matrices computable in N operations, find ones
// with a maximal number of odd terms

bool check ( const int m[16], std::vector<int> & dst, std::vector<int> & src )
{
	static int best = 0;

	int c = 0;
	int s = 0;

	if(abs(m[0]+m[4]+m[8]+m[12]) > 2) return false;
	if(abs(m[1]+m[5]+m[9]+m[13]) > 2) return false;
	if(abs(m[2]+m[6]+m[10]+m[14]) > 2) return false;
	if(abs(m[3]+m[7]+m[11]+m[15]) > 2) return false;

	for(int i = 0; i < 16; i++)
	{
		if(m[i] == 0) return false;

		int d = abs(m[i]);

		c += (d & 1);

		if(m[i] < 0) s++;
	}

	if((c == 13) && (s == 8))
	{
		std::string g[4];

		g[0] = "A";
		g[1] = "B";
		g[2] = "C";
		g[3] = "D";

		printf("----------\n");

		for(int i = 0; i < (int)dst.size(); i++)
		{
			int d = dst[i];
			int s = src[i];

			std::string tmp;

			tmp += g[d-1];

			tmp += (s < 0) ? "-" : "+";

			tmp += "(";
			tmp += g[abs(s)-1];
			tmp += ")";

			g[d-1] = tmp;
		}

		printf("A : %s\n",g[0].c_str());
		printf("B : %s\n",g[1].c_str());
		printf("C : %s\n",g[2].c_str());
		printf("D : %s\n",g[3].c_str());

		for(int i = 0; i < (int)dst.size(); i++)
		{
			int d = dst[i];
			int s = src[i];

			if(s < 0)
			{
				printf("h[%1d] -= h[%1d];\n",d,-s);
			}
			else
			{
				printf("h[%1d] += h[%1d];\n",d,s);
			}
		}
		printf("----------\n");
	}

	return c == 16;
}

bool difrecurse ( const int m[16], int depth, int maxdepth, int last, std::vector<int> & dst, std::vector<int> & src )
{
	if(depth == maxdepth)
	{
		return check(m,dst,src);
	}

	for(int i = 0; i < 4; i++)
	{
		dst.push_back(i+1);

		for(int j = 0; j < 4; j++)
		{
			if(i == j) continue;

			if(i == last) continue;
			if(j == last) continue;

			int n[16];

			memcpy(n,m,sizeof(n));

			src.push_back(j+1);
			add_row(n,i,j);
			difrecurse(n,depth+1,maxdepth,i,dst,src);
			sub_row(n,i,j);
			src.pop_back();

			src.push_back(-(j+1));
			sub_row(n,i,j);
			difrecurse(n,depth+1,maxdepth,i,dst,src);
			add_row(n,i,j);
			src.pop_back();
		}

		dst.pop_back();
	}

	return false;
}

void findDiffuse ( void )
{
	int m[16];

	memset(m,0,sizeof(m));

	m[4*0 + 0] = 1;
	m[4*1 + 1] = 1;
	m[4*2 + 2] = 1;
	m[4*3 + 3] = 1;

	std::vector<int> dst;
	std::vector<int> src;

	difrecurse(m,0,7,-1,dst,src);
	printf("\n");
}

