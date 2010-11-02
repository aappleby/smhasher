#pragma once

#include "Core.h"

#include <algorithm>
#include <math.h>
#include <assert.h>
#include <float.h>

double calcScore ( std::vector<int> const & bins, int balls );

void plot ( double n );

inline double ExpectedCollisions ( double balls, double bins )
{
	return balls - bins + bins * pow(1 - 1/bins,balls);
}

double comparenorms ( double u1, double s1, double u2, double s2 );
void beta2norm ( double a, double b, double & u, double & s );

double chooseK ( int b, int k );
double chooseUpToK ( int n, int k );

inline uint32_t f3mix ( uint32_t k )
{
	k ^= k >> 16;
	k *= 0x85ebca6b;
	k ^= k >> 13;
	k *= 0xc2b2ae35;
	k ^= k >> 16;

	return k;
}

//-----------------------------------------------------------------------------

template< typename hashtype >
int CountCollisions ( std::vector<hashtype> const & hashes )
{
	int collcount = 0;

	std::vector<hashtype> temp = hashes;
	std::sort(temp.begin(),temp.end());

	for(size_t i = 1; i < hashes.size(); i++)
	{
		if(temp[i] == temp[i-1]) collcount++;
	}

	return collcount;
}

//-----------------------------------------------------------------------------

/*
template < class keytype, typename hashtype >
int PrintCollisions ( hashfunc<hashtype> hash, std::vector<keytype> & keys )
{
	int collcount = 0;

	typedef std::map<hashtype,keytype> htab;
	htab tab;

	for(size_t i = 1; i < keys.size(); i++)
	{
		keytype & k1 = keys[i];

		hashtype h = hash(&k1,sizeof(k),0);

		htab::iterator it = tab.find(h);

		if(it != tab.end())
		{
			keytype & k2 = (*it).second;

			printf("A: ");
			printbits(&k1,sizeof(k1));
			printf("B: ");
			printbits(&k2,sizeof(k2));
		}
		else
		{
			htab.insert( htab::value_type(h,k);
		}
	}

	return collcount;
}
*/

//----------------------------------------------------------------------------

template < typename hashtype >
bool testhashlist( std::vector<hashtype> & hashes, bool testColl, bool testDist, bool drawDiagram )
{
	bool verbose = true;
	bool result = true;

	if(testColl)
	{
		size_t count = hashes.size();

		double expected = (double(count) * double(count-1)) / pow(2.0,double(sizeof(hashtype) * 8 + 1));

		if(verbose) printf("Testing collisions - Expected %8.2f, ",expected);

		double collcount = 0;

		collcount = CountCollisions(hashes);

		if(verbose)
		{
			printf("actual %8.2f (%5.2fx) \n",collcount, collcount / expected);
		}
		else
		{
			double collscore = collcount / expected;

			printf("Coll score %5.3f, ",collscore);
		}

		// 2x expected collisions = fail

		if(double(collcount) / double(expected) > 2.0)
		{
			result = false;
		}
	}

	//----------

	if(testDist)
	{
		if(verbose) printf("Testing distribution - ");

		if(drawDiagram) printf("\n");

		TestDistribution(hashes,drawDiagram);
	}

	return result;
}

//-----------------------------------------------------------------------------

template < class keytype, typename hashtype >
bool testkeylist ( hashfunc<hashtype> hash, std::vector<keytype> & keys, bool testColl, bool testDist, bool drawDiagram )
{
	int keycount = (int)keys.size();

	std::vector<hashtype> hashes;

	hashes.resize(keycount);

	//printf("Hashing keyset");

	for(int ikey = 0; ikey < keycount; ikey++)
	{
		keytype & k = keys[ikey];

		//if(ikey % (keycount / 10) == 0) printf(".");

		hashes[ikey] = hash(&k,sizeof(k),0);
	}

	//printf("\n");

	bool result = testhashlist(hashes,testColl,testDist,drawDiagram);

	return result;
}

//-----------------------------------------------------------------------------

template < typename hashtype >
bool testkeylist_string ( hashfunc<hashtype> hash, std::vector<std::string> & keys, bool testColl, bool testDist )
{
	int keycount = (int)keys.size();

	std::vector<hashtype> hashes;

	hashes.resize(keycount);

	//printf("Hashing keyset");

	for(int ikey = 0; ikey < keycount; ikey++)
	{
		std::string & k = keys[ikey];

		//if(ikey % (keycount / 10) == 0) printf(".");

		hashes[ikey] = hash(&k[0],(int)k.size(),0);
	}

	//printf("\n");

	bool result = testhashlist(hashes,testColl,testDist);

	return result;
}

//-----------------------------------------------------------------------------
// Bytepair test - generate 16-bit indices from all possible non-overlapping
// 8-bit sections of the hash value, check distribution on all of them.

// This is a very good test for catching weak intercorrelations between bits - 
// much harder to pass than the normal distribution test. However, it doesn't
// really model the normal usage of hash functions in hash table lookup, so
// I'm not sure it's that useful (and hash functions that fail this test but
// pass the normal distribution test still work well in practice)

template < typename hashtype >
double TestDistributionBytepairs ( std::vector<hashtype> & hashes, bool drawDiagram )
{
	const int nbytes = sizeof(hashtype);
	const int nbits = nbytes * 8;
	
	const int nbins = 65536;

	std::vector<int> bins(nbins,0);

	double worst = 0;

	for(int a = 0; a < nbits; a++)
	{
		if(drawDiagram) if((a % 8 == 0) && (a > 0)) printf("\n");

		if(drawDiagram) printf("[");

		for(int b = 0; b < nbits; b++)
		{
			if(drawDiagram) if((b % 8 == 0) && (b > 0)) printf(" ");

			bins.clear();
			bins.resize(nbins,0);

			for(size_t i = 0; i < hashes.size(); i++)
			{
				hashtype & hash = hashes[i];

				uint32_t pa = window(&hash,sizeof(hash),a,8);
				uint32_t pb = window(&hash,sizeof(hash),b,8);

				bins[pa | (pb << 8)]++;
			}

			double s = calcScore(bins,hashes.size());

			if(drawDiagram) plot(s);

			if(s > worst)
			{
				worst = s;
			}
		}

		if(drawDiagram) printf("]\n");
	}

	return worst;
}


//----------------------------------------------------------------------------
// Measure the distribution "score" for each possible N-bit span up to 16 bits
// and draw a nice graph of the output. 'X' in graph = 10% deviation from ideal.

template< typename hashtype >
double TestDistribution ( std::vector<hashtype> & hashes, bool drawDiagram )
{
	bool verbose = false;

	const int nbits = sizeof(hashtype) * 8;
	const int maxwidth = 20;

	std::vector<int> bins;

	double worst = 0;
	int worstStart = -1;
	int worstWidth = -1;

	for(int width = 1; width <= maxwidth; width++)
	{
		const int bincount = (1 << width);

		//If we don't have enough keys to get 2 per bin, skip the test

		//if(double(hashes.size()) / double(bincount) < 2.0) continue;

		if(drawDiagram) printf("%2d - [",width);

		for(int start = 0; start < nbits; start++)
		{
			bins.clear();
			bins.resize(bincount, 0);

			for(size_t j = 0; j < hashes.size(); j++)
			{
				hashtype & hash = hashes[j];

				uint32_t index = window(&hash,sizeof(hash),start,width);

				bins[index]++;
			}

			double n = calcScore(bins,(int)hashes.size());

			if(n > worst)
			{
				worst = n;
				worstStart = start;
				worstWidth = width;
			}

			if(drawDiagram) plot(n);
		}

		if(drawDiagram) printf("]\n");
	}

	if(verbose)
	{
		printf("Worst distribution is for (%d:%d) - %f\n",worstStart,(worstStart+worstWidth-1)%32,worst);
	}
	else
	{
		printf("Dist score %6.3f\n",(1.0 - worst) * 100);
	}

	return worst;
}

//-----------------------------------------------------------------------------
// Simplified test - only check 64k distributions, and only on byte boundaries

template < typename hashtype >
void TestDistributionFast ( std::vector<hashtype> & hashes, double & dworst, double & davg )
{
	const int nbits = sizeof(hashtype) * 8;
	const int nbins = 65536;
	
	std::vector<int> bins(nbins,0);

	dworst = -1.0e90;
	davg = 0;

	for(int start = 0; start < nbits; start += 8)
	{
		bins.clear();
		bins.resize(nbins,0);

		for(size_t j = 0; j < hashes.size(); j++)
		{
			hashtype & hash = hashes[j];

			uint32_t index = window(&hash,sizeof(hash),start,16);

			bins[index]++;
		}

		double n = calcScore(bins,(int)hashes.size());
		
		davg += n;

		if(n > dworst) dworst = n;
	}

	davg /= double(nbits/8);
}

//-----------------------------------------------------------------------------

/*
struct Stats 
{
	enum mode
	{
		AVALANCHE,
		HISTOGRAM,
	};

	Stats ( int mode, std::vector<int> const & bins, int balls )
	{
		switch(mode)
		{
		case AVALANCHE:
			calcAvalanche(bins,balls);
			break;

		case HISTOGRAM:
			calcHistogram(bins,balls);
			break;

		default:
			assert(false);
			break;
		}
	}

	//----------
	// Histogram mode

	void calcHistogram ( std::vector<int> const & bins, int balls )
	{
		m_nbins  = (int)bins.size();
		m_nballs = balls;

		m_mean   = 0;
		m_rms    = 0;
		m_sigma  = 0;
		m_max    = -DBL_MAX;
		m_min    = DBL_MAX;

		for(size_t i = 0; i < bins.size(); i++)
		{
			double x = bins[i];

			m_mean += x;
			m_rms += x*x;

			m_max = x > m_max ? x : m_max;
			m_min = x < m_min ? x : m_min;
		}

		m_mean /= m_nbins;
		m_rms /= m_nbins;
		m_rms = sqrt(m_rms);

		for(size_t i = 0; i < bins.size(); i++)
		{
			double d = bins[i] - m_mean;
			
			m_sigma += d*d;
		}

		m_sigma /= m_nbins;
		m_sigma = sqrt(m_sigma);
	}
	
	//----------
	// Normalized standard deviation

	double calcNSD ( std::vector<int> const & bins, int balls )
	{
		double n = (int)bins.size();
		double k = balls;
		double p = 1.0/n;

		double u = k*p;
		double s = sqrt(k*p*(1-p));

		double c = 0;

		for(size_t i = 0; i < bins.size(); i++)
		{
			double d = bins[i];

			d = (d-u)/s;

			c += d*d;
		}

		m_nsd = sqrt(c / m_nbins);
	}

	double calcScore ( std::vector<int> const & bins, int balls )
	{
		double n = (int)bins.size();
		double k = balls;

		// compute rms value

		double r = 0;

		for(size_t i = 0; i < bins.size(); i++)
		{
			double b = bins[i];

			r += b*b;
		}

		r = sqrt(r / n);

		// compute fill factor

		double f = (k*k - 1) / (n*r*r - k);

		// rescale to (0,1) with 0 = good, 1 = bad

		m_score = 1 - (f / n);
	}

	//----------
	// Avalanche statistics - convert each table entry to a bias value
	// and compute stats based on that.

	void calcAvalanche ( std::vector<int> const & bins, int balls )
	{
		m_nbins  = (int)bins.size();
		m_nballs = balls;

		m_mean   = 0;
		m_rms    = 0;
		m_sigma  = 0;
		m_max    = -DBL_MAX;
		m_min    = DBL_MAX;
		m_nbad   = 0;

		for(size_t i = 0; i < bins.size(); i++)
		{
			double x = (bins[i] / m_nballs) * 2 - 1;

			m_mean += x;
			m_rms += x*x;

			x = fabs(x);

			if(x > 0.7) m_nbad++;

			m_max = x > m_max ? x : m_max;
			m_min = x < m_min ? x : m_min;
		}

		m_mean /= m_nbins;
		m_rms /= m_nbins;
		m_rms = sqrt(m_rms);

		for(size_t i = 0; i < bins.size(); i++)
		{
			double x = (bins[i] / m_nballs) * 2 - 1;

			double d = x - m_mean;
			
			m_sigma += d*d;
		}

		m_sigma /= m_nbins;
		m_sigma = sqrt(m_sigma);
	}

	double m_nbins;
	double m_nballs;

	double m_mean;
	double m_rms;
	double m_sigma;

	double m_nsd;
	double m_score;

	double m_nbad;

	double m_max;
	double m_min;
};
*/

//-----------------------------------------------------------------------------
