/* What is the largest prime factor of the number 600851475143 ? */
#define NUMBER 600851475143

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(unsigned long * primes, unsigned long numtoprint) {
	for(unsigned long i = 0; i < numtoprint; ++i)
		if(primes[i])
			printf("%zd ",i);
}

int main(){
	unsigned long largest_pfactor_index = 2; 
	unsigned long number = NUMBER;
	unsigned long * primes;
	const double temp = powf((double) NUMBER,1.0f/3.0f);
	const unsigned long size = (const int) temp; 
	printf("size: %zd\n",size);

	primes = (unsigned long *) calloc(size,sizeof(unsigned long));

	/* 0 stands for: Not a prime number.
	 * 1 stands for: Is a prime number. */

	for (unsigned long i = 0; i < size; primes[i++] = 1)  
		;
	
	/* Generate prime number array. */
	primes[0] = 0;
	primes[1] = 0;
	for (unsigned long i = 2; i < size; ++i)
		for (unsigned long j = 2; j * i <= size; ++j)
			primes[j * i] = 0;
	//print(primes, size);
	
	for (unsigned long i = largest_pfactor_index; i < size; ++i){
		if(primes[largest_pfactor_index] && number % i == 0){
			number /= i;
			largest_pfactor_index = i;
			--i;
		}
	}
	

		printf("the largest prime factor of the number 10737418 is: %zd\n",
			   largest_pfactor_index);
	free(primes);
	return 0;
}
