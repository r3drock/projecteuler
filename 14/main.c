/*Which starting number, under one million,
 * produces the longest collatz chain? */

#define LIMIT 1000000

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int collatz(unsigned long long n, unsigned int iterations)
{
	if (iterations == UINT_MAX) {
		fprintf(stderr,"Too many iterations.");
		exit(-1);
	}
	if (n == 1)
		return iterations;
	else if (n % 2 == 0)
		return collatz(n / 2, ++iterations);
	else
		return collatz(3 * n + 1, ++iterations);
}

int main()
{
	unsigned int max_len = 0;
	unsigned int max_start_number = 0;
	unsigned int temp;

	for (unsigned long long i = 1; i < LIMIT; ++i) {
		temp = collatz(i,1);
		if (temp > max_len) {
			max_len = temp;  
			max_start_number = i; 
		}
	}

	printf("The longest chain collatz(%d) is %d long.",
		   max_start_number, max_len);

	return 0;
}
