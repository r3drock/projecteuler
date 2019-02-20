/* Find a pythogorean triplet with the sum 1000. */ 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAGIC 1000

void alternative();
int main()
{
	for (int a = 1; a < MAGIC; ++a)
		for (int b = a; b < MAGIC; ++b) {
			int c = (int) sqrt((a * a) + (b * b));
			if (c >= MAGIC) {
				b = 2000;
			}
			if ((a * a) + (b * b) == (c * c))
				if (a + b + c == MAGIC)
					printf("(%d,%d,%d)\n",a,b,c);
		}
	return 0;
}
void alternative() 
{
	const int size = MAGIC * MAGIC;
	short * sqrt_table;

	//Use a lookup table to speed up sqrt 
	//and to throw away combinations which
	//would yield no integer as result
	//They must be integer because c is an integer
	sqrt_table = (short *) calloc(size,sizeof(short));

	for (int i = 0; i < size; sqrt_table[i++] = 0) 
		;
	for (int i = 0; i < MAGIC; ++i)
		sqrt_table[i * i] = i;

	for (int a = 1; a < MAGIC; ++a)
		for (int b = a; b < MAGIC; ++b) {
			int tmp = (a*a)+(b*b); //a^2 + b^2 
			if (tmp >= size)
				tmp = 0;
			int c = (int) sqrt_table[tmp];
			if (c >= MAGIC) {
				b = 2000;
			}
			if (c > 0 && (a * a) + (b * b) == (c * c))
				if (a + b + c == MAGIC)
					printf("(%d,%d,%d)\n",a,b,c);
		}

	free(sqrt_table);
}
