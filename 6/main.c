/* Find the difference between the sum of the squares 
 * of the first one hundred natural numbers and the square of the sum. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	const unsigned long long n = 100;
	unsigned long long sum = 0;
	unsigned long long sqare_of_sum = 0;
	unsigned long long sum_of_sqares = 0;

	for (unsigned long long i = 1; i <= n; sum += i++)
		;
	sqare_of_sum = sum * sum;

	for (unsigned long long i = 1; i <= n; ++i)
		sum_of_sqares += i * i;


	printf("The difference between the sum of the squares of the\n\
first one hundred natural numbers and\n\
the square of the sum is: %llu\n",sum_of_sqares-sqare_of_sum);
	
	return 0;
}
