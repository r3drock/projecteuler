/* What is the smallest positive number that is 
 * evenly divisible by all of the numbers from 1 to 20?*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	unsigned long long number = 2520;

	while (!(number % 20 == 0 &&
		     number % 19 == 0 &&
		     number % 18 == 0 &&
		     number % 17 == 0 &&
		     number % 16 == 0 &&
		     number % 15 == 0 &&
		     number % 14 == 0 &&
		     number % 13 == 0 &&
		     number % 12 == 0 &&
		     number % 11 == 0))
		++number;

	printf("The smallest positive number that is evenly divisible\n\
by all of the numbers from 1 to 20 is: %llu\n",number);

	return 0;
}
