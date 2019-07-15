/* How many circular primes are there below one million? */

#include <stdio.h>
#include <stdlib.h>

#define MAXPRIME 1000000

int * buildPrimes()
{
	int * primes;

	primes = (int *) calloc(MAXPRIME,sizeof(int));

	/* 0 stands for: Not a prime number.
	 * 1 stands for: Is a prime number. */

	for ( int i = 0; i < MAXPRIME; primes[i++] = 1)  
		;

	/* Generate prime number array. */
	primes[0] = 0;
	primes[1] = 0;
	for ( int i = 2; i < MAXPRIME; ++i)
		for ( int j = 2; j * i <= MAXPRIME; ++j)
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

int rotate(int number)
{
	int i = number % 10;
	number /= 10;

	int j = 1;
	for(; !((j > number) && ((j/10) <= number)); j *= 10)
		;
	return j * i + number;
}

int isCircularPrime(int number, int * primes)
{
	if (primes[number] == 0)
		return 0;
	for(int i = numdigits(number) - 1; i > 0; --i)
		if (primes[(number = rotate(number))] == 0)
			return 0;
	return 1;			
}

int main()
{
	int * primes = buildPrimes();
	int count = 0;

	for (int i = 1; i < MAXPRIME; ++i)
		if (isCircularPrime(i, primes))
			++count;

	printf("%d\n", count);
	return 0;
}
