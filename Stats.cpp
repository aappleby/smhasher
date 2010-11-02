#include "Stats.h"

//-----------------------------------------------------------------------------

// If you want to compute these two statistics, uncomment the code and link with
// the GSL library.

/*
extern "C"
{
	double gsl_sf_gamma_inc_P(const double a, const double x);
	double gsl_sf_gamma_inc_Q(const double a, const double x);
};

// P-val for a set of binomial distributions

void pval_binomial ( int * buckets, int len, int n, double p, double & sdev, double & pval )
{
	double c = 0;

	double u = n*p;
	double s = sqrt(n*p*(1-p));

	for(int i = 0; i < len; i++)
	{
		double x = buckets[i];

		double n = (x-u)/s;

		c += n*n;
	}

	sdev = sqrt(c / len);

	pval = gsl_sf_gamma_inc_P( len/2, c/2 );
}

// P-val for a histogram - K keys distributed between N buckets
// Note the (len-1) due to the degree-of-freedom reduction

void pval_pearson ( int * buckets, int len, int keys, double & sdev, double & pval )
{
	double c = 0;

	double n = keys;
	double p = 1.0 / double(len);

	double u = n*p;
	double s = sqrt(n*p*(1-p));

	for(int i = 0; i < len; i++)
	{
		double x = buckets[i];

		double n = (x-u)/s;

		c += n*n;
	}

	sdev = sqrt(c / len);

	pval = gsl_sf_gamma_inc_P( (len-1)/2, c/2 );
}
*/

//----------------------------------------------------------------------------

double erf2 ( double x )
{
    const double a1 =  0.254829592;
    const double a2 = -0.284496736;
    const double a3 =  1.421413741;
    const double a4 = -1.453152027;
    const double a5 =  1.061405429;
    const double p  =  0.3275911;

    double sign = 1;
    if(x < 0) sign = -1;

    x = abs(x);

    double t = 1.0/(1.0 + p*x);
    double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

    return sign*y;
}

double normal_cdf ( double u, double s2, double x )
{
	x = (x - u) / sqrt(2*s2);

	double c = (1 + erf2(x)) / 2;

	return c;
}

double binom_cdf ( double n, double p, double k )
{
	double u = n*p;
	double s2 = n*p*(1-p);

	return normal_cdf(u,s2,k);
}

// return the probability that a random variable from distribution A is greater than a random variable from distribution B

double comparenorms ( double uA, double sA, double uB, double sB )
{
	double c = 1.0 - normal_cdf(uA-uB,sA*sA+sB*sB,0);

	return c;
}

// convert beta distribution to normal distribution approximation

void beta2norm ( double a, double b, double & u, double & s )
{
	u = a / (a+b);

	double t1 = a*b;
	double t2 = a+b;
	double t3 = t2*t2*(t2+1);

	s = sqrt( t1 / t3 );
}

#pragma warning(disable : 4189)

double comparecoins ( double hA, double tA, double hB, double tB )
{
	double uA,sA,uB,sB;

	beta2norm(hA+1,tA+1,uA,sA);
	beta2norm(hB+1,tB+1,uB,sB);

	// this is not the right way to handle the discontinuity at 0.5, but i don't want to deal with truncated normal distributions...

	if(uA < 0.5) uA = 1.0 - uA;
	if(uB < 0.5) uB = 1.0 - uB;

	return 1.0 - comparenorms(uA,sA,uB,sB);
}

// Binomial distribution using the normal approximation

double binom2 ( double n, double p, double k )
{
	double u = n*p;
	double s2 = n*p*(1-p);

	double a = k-u;

	const double pi = 3.14159265358979323846264338327950288419716939937510;

	a = a*a / (-2.0*s2);
	a = exp(a) / sqrt(s2*2.0*pi);

	return a;
}

double RandWork ( double bucketcount, double keycount )
{
	double avgload = keycount / bucketcount; 

	double total = 0;

	if(avgload <= 16)
	{
		// if the load is low enough we can compute the expected work directly

		double p = pow((bucketcount-1)/bucketcount,keycount);

		double work = 0;

		for(double i = 0; i < 50; i++)
		{
			work  += i;
			total += work * p;

			p *= (keycount-i) / ( (i+1) * (bucketcount-1) );
		}
	}
	else
	{
		// otherwise precision errors screw up the calculation, and so we fall back
		// to the normal approxmation to the binomial distribution

		double min = avgload / 5.0;
		double max = avgload * 5.0;

		for(double i = min; i <= max; i++)
		{
			double p = binom2(keycount,1.0 / bucketcount,i);

			total += double((i*i+i) / 2) * p;
		}
	}

	return total / avgload;
}

// Normalized standard deviation.

double nsdev ( int * buckets, int len, int keys )
{
	double n = len;
	double k = keys;
	double p = 1.0/n;

	double u = k*p;
	double s = sqrt(k*p*(1-p));

	double c = 0;

	for(int i = 0; i < len; i++)
	{
		double d = buckets[i];

		d = (d-u)/s;

		c += d*d;
	}

	double nsd = sqrt(c / n);

	return nsd;
}


double chooseK ( int n, int k )
{
    if(k > (n - k)) k = n - k;

	double c = 1;

	for(int i = 0; i < k; i++)
	{
		double t = double(n-i) / double(i+1);

		c *= t;
	}

    return c;
}

double chooseUpToK ( int n, int k )
{
	double c = 0;

	for(int i = 1; i <= k; i++)
	{
		c += chooseK(n,i);
	}

	return c;
}

//-----------------------------------------------------------------------------

uint32_t bitrev ( uint32_t v )
{
	v = ((v >> 1) & 0x55555555) | ((v & 0x55555555) << 1);
	v = ((v >> 2) & 0x33333333) | ((v & 0x33333333) << 2);
	v = ((v >> 4) & 0x0F0F0F0F) | ((v & 0x0F0F0F0F) << 4);
	v = ((v >> 8) & 0x00FF00FF) | ((v & 0x00FF00FF) << 8);
	v = ( v >> 16             ) | ( v               << 16);

	return v;
}

//-----------------------------------------------------------------------------

// Distribution "score"
// TODO - big writeup of what this score means

// Basically, we're computing a constant that says "The test distribution is as
// uniform, RMS-wise, as a random distribution restricted to (1-X)*100 percent of
// the bins. This makes for a nice uniform way to rate a distribution that isn't
// dependent on the number of bins or the number of keys

// (as long as # keys > # bins * 3 or so, otherwise random fluctuations show up
// as distribution weaknesses)

double calcScore ( std::vector<int> const & bins, int keys )
{
	double n = (int)bins.size();
	double k = keys;

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

	return 1 - (f / n);
}


//----------------------------------------------------------------------------

void plot ( double n )
{
	double n2 = n * 1;

	if(n2 < 0) n2 = 0;

	n2 *= 100;

	if(n2 > 64) n2 = 64;

	int n3 = (int)floor(n2 + 0.5);

	if(n3 == 0)
		printf(".");
	else
	{
		char x = '0' + char(n3);

		if(x > '9') x = 'X';

		printf("%c",x);
	}
}

//-----------------------------------------------------------------------------
