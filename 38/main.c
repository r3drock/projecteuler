/* What is the largest 1 to 9 pandigital 9-digit number that can be formed as
 * the concatenated product of an integer with (1,2, ... , n) where n > 1? */

#include <stdio.h>
#include <stdlib.h>

#define BASE 10

void generateProducts(long n, long i, long* products);
long power(long i, long j);
long largest();
long concat(long n, const long* products);
long numdigits(long number);
long isPandigital(long n);

int main()
{
	printf("%ld\n", largest());
	return 0;
}

long largest(){
	long n = 5;
	long i = 9;
	long number = 0;
	long largest = 0;
	long products[6];

	while (number < 1000000000 && n > 1) {
		generateProducts(n, i, products);
		number = concat(n, products);
		if ( number < 0) {
			fprintf(stderr, "FEHLER%ld\n", number);
			exit(1);
		}
		if (number >= 1000000000) {
			--n; 
			number = 0;
			continue;
		}

		if (numdigits(number) == 9) {
			if (isPandigital(number)) {
				if (number > largest) {
					largest = number;
				}
			}
		}
		++i;
	}
	return largest;
}

void generateProducts(long n, long i, long* products)
{
	for (long j = 0; j < n; ++j)
	products[j] = i * (j+1);
}

long numdigits(long number)
{
	long digitscount = 0;
	for (;number > 0; number /= 10)
		digitscount++;
	return digitscount;
}

long concat(long n, const long* products)
{
	long concatenated = products[0];
	for (long j = 1 ; j < n; ++j) {
		concatenated *= power(10, numdigits(products[j]));
		concatenated += products[j];
	}
	return concatenated;
}

long power(long i, long j)
{
	long retval = 1;
	for (; j > 0; --j) 
		retval *= i;
	return retval;
}

long isPandigital(long n)
{
	char hasit[BASE] = {0,0,0,0,0,0,0,0,0,0}; 

		while (n > 0) {
			hasit[n % BASE] += 1;
			n /= BASE;
		}
	if (hasit[0])
		return 0;
	for(long i = 1; i < BASE; ++i)
		if (hasit[i] != 1)
			return 0;
	return 1;
}
