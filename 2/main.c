/* By considering the terms in the Fibonacci sequence whose values do not 
 * exceed four million, find the sum of the even value terms. */
#define LIMIT 4000000 

#include <stdio.h>

int main(){
	int unsigned previous = 1;  
	int unsigned current = 2;
    int unsigned sum = 2;	

	while (current <= LIMIT) {
		current = previous + current;
		sum += current * (current % 2 == 0);
	}
	printf("The sum of the even value terms in the fibonacci sequence whose \
values do not exceed 4 million is: %zd\n",sum);
	return 0;
}
