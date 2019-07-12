/* How many different ways can £2 be made using any number of coins? */

#include <stdio.h>

int fac(int i)
{
	int retval = 1;
	for (;i > 0; --i)
		retval *= i;
	return retval;
}

int main()
{
	int sum = 0;
	
	//2540160 == 9!*7
	for (int i = 3; i < 2540160; ++i) {
		int tmpsum = 0;
		for (int j = i; j > 0; j /=10) {
			tmpsum += fac(j % 10);
		}
		if (tmpsum == i)
			sum += tmpsum;
	}

	printf("%d\n", sum);
	return 0;
}

