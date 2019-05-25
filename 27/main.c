/*     Find the product of the coefficients, a and b, for the quadratic
 *     expression that produces the maximum number of primes for consecutive
 *     values of n, starting with n = 0.*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ALIM 1000
#define BLIM 1000
#define MAXPRIME 1000*2000+1001

void print( long * primes,  long numtoprint) 
{
	for( long i = 0; i < numtoprint; ++i)
		if(primes[i])
			printf("%zd ",i);
}

long * buildPrimes()
{
	long * primes;

	primes = (long *) calloc(MAXPRIME,sizeof(long));

	/* 0 stands for: Not a prime number.
	 * 1 stands for: Is a prime number. */

	for ( long i = 0; i < MAXPRIME; primes[i++] = 1)  
		;

	/* Generate prime number array. */
	primes[0] = 0;
	primes[1] = 0;
	for ( long i = 2; i < MAXPRIME; ++i)
		for ( long j = 2; j * i <= MAXPRIME; ++j)
			primes[j * i] = 0;

	return primes;
}

long checkConsecutivePrimeNumbers(long * primes,
		long a, long b)
{
	long n = 0;
	if (((n * n) + (a * n) + b) < 0)
		return 0;

	while ((((n * n) + (a * n) + b) > 0 ) && (primes[(n * n) + (a * n) + b]))
		++n;
	return n;
}

int main()
{
	long * primes = buildPrimes();
	long longestConsecutivePrimeNumbers = 0;
	long besta = 0;
	long bestb = 0;

	for (long a = -999; a < 1000; ++a) {
		for (long b = -999; b < 1000; ++b) {
			long temp = checkConsecutivePrimeNumbers(primes, a, b);
			if (temp > longestConsecutivePrimeNumbers) {
				longestConsecutivePrimeNumbers = temp;
				besta = a;
				bestb = b;
			}
		}
	}

	printf("The product of the coefficients a: %ld, b: %ld is: %lld\nIt were %ld consecutive primes.\n",
			besta, bestb, besta * (long long) bestb, longestConsecutivePrimeNumbers);
	free(primes);
	return 0;
}
