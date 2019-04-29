/* What is the 10 001st prime number?*/

#define PRIMEINDEX 10001

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(unsigned int * primes, unsigned int numtoprint) 
{
	for(unsigned int i = 0; i < numtoprint; ++i)
		if(primes[i])
			printf("%u ",i);
}

unsigned int run(unsigned int size) 
{
	unsigned int result;
	unsigned int * primes = (unsigned int *) calloc(size,sizeof(unsigned int));

	/* 0 stands for: Not a prime number.
	 * 1 stands for: Is a prime number. */

	for (unsigned int i = 0; i < size; primes[i++] = 1)  
		;
	
	/* Generate prime number array. */
	primes[0] = 0;
	primes[1] = 0;
	for (unsigned int i = 2; i < size; ++i)
		for (unsigned int j = 2; j * i <= size; ++j)
			primes[j * i] = 0;


	unsigned int j = 0;
	for (unsigned int i = 0; i < size; ++i)
		if (primes[i])
			if(++j == PRIMEINDEX)	
				result = i;

	free(primes);
	return result;
}
int main()
{
	unsigned int size = 100;
	unsigned int result = 0;

	while (!(result = run(size))) {
		printf("size not large enough. trying again...\n");
		size *= 2;
	}
	printf("The %dst prime number is: %d\n",
		   PRIMEINDEX, result);

	return 0;
}
