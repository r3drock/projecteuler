/* What is the sum of all products whose multiplicand/multiplier/product
 *  * identity can be written as a 1 through 9 pandigital.*/

#include <stdio.h>

#define BASE 10

void generateProducts(int n, int i, int* products)
int isPandigital(int n, int* products);
int power(int i, int j);
int largest();
int concat(int n, const int* products);

int main()
{

	return 0;
}

int largest(){
	int n = 5;
	int i = 9;
	int number = 0;
	int largest = 0;

	int products[6];

	while (number < 1000000000) {
		generateProducts(n, i, products);
		number = concat(n, products);
		if (isPandigital(

		





	}


}

void generateProducts(int n, int i, int* products)
{
	for (int j = 0; j < n; ++j)
	products[j] = i * (j+1);
}

int numdigits(int number)
{
	int digitscount = 0;
	for (;number > 0; number /= 10)
		digitscount++;
	return digitscount;
}

int concat(int n, const int* products)
{
	int concatenated = 0;
	for (int j = 0 ; j < n; ++j) {
		concatenated += products[j];
		concatenated *= power(10, numdigits(products[j]));
	}
	return concatenated;
}

int power(int i, int j)
{
	int retval = 1;
	for (; j > 0; --j) 
		retval *= i;
	return retval;
}

int isPandigital(int n, int* products)
{
	char hasit[BASE] = {0,0,0,0,0,0,0,0,0,0}; 

	for (int j = 0; j < n; ++j) {
		while (products[n] > 0) {
			hasit[products[j] % BASE] += 1;
			products[j] /= BASE;
		}
	}
	if (hasit[0])
		return 0;
	for(int i = 1; i < BASE; ++i)
		if (hasit[i] != 1)
			return 0;
	return 1;
}
