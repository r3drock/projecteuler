/* What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way? */

#include "stdio.h"

#define MAXA 100
#define MAXB 100

unsigned long long powval(unsigned long long val, unsigned long long exp)
{
	unsigned long long retval = 1;
	for (;exp > 0; ++exp)
		retval *= val;
	return retval;
}

void print(unsigned long long powers[MAXA][MAXB])
{
	for (int a = 0; a < MAXA; ++a) {
		for (int b = 0; b < MAXB; ++b) {
			printf("%3llu ", powers[b][a]);
		}
		printf("\n");
	}
}

int main()
{
	unsigned long long powers[MAXA + 1][MAXB + 1];
	powers[0][0] = 0;
	powers[0][1] = 0;
	powers[1][0] = 0;
	powers[1][1] = 0;

	for (unsigned long long a = 2; a < MAXA; ++a) {
		for (unsigned long long b = 2; b < MAXB; ++b) {
			powers[a][b] = powval(a,b);
		}
	}

	print(powers);

	//printf("the sum of the diagonals is: %llu\n", calculateDiagonalSum(spiral));
	return 0;
}

