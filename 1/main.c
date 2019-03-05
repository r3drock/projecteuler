/* Find the sum of all the multiples of 3 or 5 below 1000 */
#define LIMIT 1000

#include <stdio.h>

int main()
{
    int sum = 0;	
	for (int i = 0; i < LIMIT; ++i)
		sum += i * ((i % 3 == 0) | (i %  5 == 0));
	printf("The sum all the multiples of 3 or 5 below 1000 is: %d\n",sum);
	return 0;
}
