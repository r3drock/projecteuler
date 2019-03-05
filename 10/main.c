/*What is the sum of all primes below two million?*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAGIC 2000000

void print(unsigned long * primes, unsigned long numtoprint) {
	for(unsigned long i = 0; i < numtoprint; ++i)
		if(primes[i])
			printf("%zd ",i);
}

int main()
{
	unsigned long long sum = 0; 
	unsigned long * primes;

	primes = (unsigned long *) calloc(MAGIC,sizeof(unsigned long));

	/* 0 stands for: Not a prime number.
	 * 1 stands for: Is a prime number. */

	for (unsigned long i = 0; i < MAGIC; primes[i++] = 1)  
		;
	
	/* Generate prime number array. */
	primes[0] = 0;
	primes[1] = 0;
	for (unsigned long i = 2; i < MAGIC; ++i)
		for (unsigned long j = 2; j * i <= MAGIC; ++j)
			primes[j * i] = 0;
	 
	/*Calculate sum */
	for (unsigned long long i = 0; i < MAGIC; ++i)  
		sum += primes[i] * i;

	printf("The sum of all primes below two million is: %llu\n",
		   sum);
	free(primes);
	return 0;
}
