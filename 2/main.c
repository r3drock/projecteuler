/* By considering the terms in the Fibonacci sequence whose values do not 
 * exceed four million, find the sum of the even value terms. */
#define LIMIT 4000000 

#include <stdio.h>

int main(){
	long unsigned previous = 1;  
	long unsigned current = 1;
    long unsigned sum = 0;	

	while (current <= LIMIT) {
		unsigned long temp = current; 
		current = previous + current;
		previous = temp; 
		sum += current * (current % 2 == 0);
	}
	printf("The sum of the even value terms in the fibonacci sequence whose \
values do not exceed 4 million is: %lu\n",sum);
	return 0;
}
