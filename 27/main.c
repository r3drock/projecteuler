/*     Find the product of the coefficients, a and b, for the quadratic
 *     expression that produces the maximum number of primes for consecutive
 *     values of n, starting with n = 0.*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ALIM 1000
#define BLIM 1000
#define MAXPRIME 1000*2000+1001

void print(unsigned long * primes, unsigned long numtoprint) 
{
	for(unsigned long i = 0; i < numtoprint; ++i)
		if(primes[i])
			printf("%zd ",i);
}

unsigned long * buildPrimes()
{
	unsigned long * primes;

	primes = (unsigned long *) calloc(MAXPRIME,sizeof(unsigned long));

	/* 0 stands for: Not a prime number.
	 * 1 stands for: Is a prime number. */

	for (unsigned long i = 0; i < MAXPRIME; primes[i++] = 1)  
		;
	
	/* Generate prime number array. */
	primes[0] = 0;
	primes[1] = 0;
	for (unsigned long i = 2; i < MAXPRIME; ++i)
		for (unsigned long j = 2; j * i <= MAXPRIME; ++j)
			primes[j * i] = 0;
}

unsigned long checkConsecutivePrimeNumbers(unsigned long * primes,
		unsigned long a, unsigned long b)
{
	unsigned long n = 0;
	if (((n * n) + (a * n) + b) < 0)
		return 0;
	while (primes[(n * n) + (a * n) + b])
		++n;
	return n;
}

int main()
{
	unsigned long * primes = buildPrimes();
	unsigned long long product = 0;
	unsigned long longestConsecutivePrimeNumbers = 0;
	unsigned long besta = 0;
	unsigned long bestb = 0;

	for (unsigned long a = -999; a < 1000; ++a) {
		for (unsigned long b = -999; b < 1000; ++b) {
			unsigned long temp = checkConsecutivePrimeNumbers(primes, a, b);
			if (temp > longestConsecutivePrimeNumbers) {
				longestConsecutivePrimeNumbers = temp;
				besta = a;
				bestb = b;
			}
		}
	}

	printf("The product of the coefficients is: %llu\n", besta * bestb);
	free(primes);
	return 0;
}
