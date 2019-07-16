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

int numdigits(int number)
{
	int digitscount = 0;
	for (;number > 0; number /= 10)
		digitscount++;
	return digitscount;
}

int getLeft(int i)
{
	int j = 10;
	for(;!(((i / j) == 0) && ((i/(j/10)) > 0)); j *= 10)
		;
	int left = i / (j / 10);
	return left * (j / 10);
}

int isTruncatablePrime(int i, int * primes)
{
	int temp = i;
	while (i > 0) {
		if (primes[i] == 0)
			return 0;
		i /= 10;
	}
	i = temp;

	while (i > 0) {
		if (primes[i] == 0)
			return 0;
		int left = getLeft(i);
		i = i - left;
	}
	return 1;	
}

int main()
{
	int sum = 0;
	int count = 0;
	int maxprime = 256;
	int * primes = buildPrimes(maxprime);
	sum += isTruncatablePrime(233, primes);

	for (unsigned int i = 11; count < 11; ++i) {
		if (i >= maxprime) {
			free(primes);
			printf("calculate %d more primes\n", maxprime);
			maxprime *= 2;
			primes = buildPrimes(maxprime);
		}
		if (isTruncatablePrime(i, primes)) {
			printf("%d\n", i);
			sum += i;
			++count;
		}
	}

	printf("%d\n", sum);
	return 0;
}

