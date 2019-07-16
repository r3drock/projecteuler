/* What is the sum of the only eleven primes that are both truncatable
 * from left to right and right to left?  */

#include <stdio.h>
#include <stdlib.h>

int * buildPrimes(unsigned int maxprime)
{
	int * primes;

	primes = (int *) calloc(maxprime,sizeof(int));

	/* 0 stands for: Not a prime number.
	 *	 * 1 stands for: Is a prime number. */

	for ( int i = 0; i < maxprime; primes[i++] = 1)  
		;

	/* Generate prime number array. */
	primes[0] = 0;
	primes[1] = 0;
	for ( int i = 2; i < maxprime; ++i)
		for ( int j = 2; j * i <= maxprime; ++j)
			primes[j * i] = 0;

	return primes;
}

long isPandigital(long num, int n)
{
	char hasit[n];
	for (int i = 0; i < n; ++i)
		hasit[i] = 0;

	for (long j = 0; j < n; ++j) {
		while (num > 0) {
			hasit[num % 10] += 1;
			num /= 10;
		}
	}
	if (hasit[0])
		return 0;
	for(long i = 1; i <= n; ++i)
		if (hasit[i] != 1)
			return 0;
	return 1;
}

int main()
{
	int largest = 0;
	int maxprime = 1000000000;
	int * primes = buildPrimes(maxprime);

	for (unsigned int i = 1; i < 1000000000; ++i) {

		if (primes[i] && isPandigital(i)) {
			largest = i;
		}
	}

	printf("%d\n", largest);
	return 0;
}

