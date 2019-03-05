/* Find the difference between the sum of the squares 
 * of the first one hundred natural numbers and the square of the sum. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	const long long n = 100;
	long long sum = 0;
	long long sqare_of_sum = 0;
	long long sum_of_sqares = 0;

	for (long long i = 1; i <= n; i++)
		sum += i;
	sqare_of_sum = sum * sum;

	for (long long i = 1; i <= n; i++)
		sum_of_sqares += i * i;

	long long result = sum_of_sqares-sqare_of_sum;
	result = (result < 0) ? result * -1 : result;

	printf("The difference between the sum of the squares: %lld\n\
of the first one hundred natural numbers and\n\
the square of the sum: %lld is: %lld\n",sum_of_sqares,
sqare_of_sum, result);
	
	return 0;
}
