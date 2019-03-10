/* What is the value of the first triangle number 
 * to have over five hundred divisors? */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned int check_for_solution(unsigned int * divisorcount, unsigned long long size)
{
	/* Iterate through triangular_numbers. */
	unsigned int current = 0;

	for (unsigned int step = 1; current < size; ++step) {
		if (divisorcount[current] >= 500)
			return current;
		else
			current += step;
	}
	return 0;
}

unsigned int run(unsigned long long size)
{
	unsigned int * divisorcount;
	if (size > UINT_MAX ) {
		printf("Solution must be bigger than %u. Aborting...",UINT_MAX);
		return 0;
	}
	divisorcount = (unsigned int *) calloc(size,sizeof(unsigned int));


	for (unsigned int i = 0; i < size; divisorcount[i++] = 1)  
		;
	
	/* Generate divisorcount array. */
	for (unsigned int divisor = 2; divisor < size; ++divisor)   
		for (unsigned int i = divisor; i < size; i += divisor) 
			++divisorcount[i];

	unsigned int result = check_for_solution(divisorcount, size);

	free(divisorcount);
	return result;
}

int main()
{
	unsigned long long size = 500;
	unsigned int result = 0;

	while(!(result = run(size))) {
		printf("size: %llu not large enough. trying again...\n", size);
		size *= 2;
	}
	printf("The first triangular number with more than 500 divisors is: %u\n",
		   result);
	return 0;
}
