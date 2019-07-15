/* What is the sum of all products whose multiplicand/multiplier/product
 * identity can be written as a 1 through 9 pandigital.*/

#include <stdio.h>

#define BASE 10

int isPandigital(int multiplicand, int multiplier, int product);

int main()
{
	for(int multiplicand = 1; multiplicand < 100; ++multiplicand)
		for(int multiplier = multiplicand; multiplier < 10000; ++multiplier)
			if (isPandigital(multiplicand, multiplier,
								multiplicand * multiplier)) {
				printf("%d\n", multiplicand * multiplier);
			}
	return 0;
}

int isPandigital(int multiplicand, int multiplier, int product)
{
	char hasit[BASE] = {0,0,0,0,0,0,0,0,0,0}; 

	while (multiplicand > 0) {
		hasit[multiplicand % BASE] += 1;
		multiplicand /= BASE;
	}
	while (multiplier > 0) {
		hasit[multiplier % BASE] += 1;
		multiplier /= BASE;
	}
	int tmpproduct = product;
	while (product > 0) {
		hasit[product % BASE] += 1;
		product /= BASE;
	}

	if (hasit[0])
		return 0;
	for(int i = 1; i < BASE; ++i)
		if (hasit[i] != 1)
			return 0;
	return tmpproduct;
}

