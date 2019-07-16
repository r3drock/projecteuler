/* What is the largest n-digit pandigital prime that exists? */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int isPrime(unsigned int number) 
{
	int limit = (int) sqrt(number);

	for (int i = 2; i < limit; ++i)
		if (number % i == 0)
			return 0;
	return 1;
}

long isPandigital(long num, int n)
{
	char hasit[10];
	for (int i = 0; i < 10; ++i)
		hasit[i] = 0;

	while (num > 0) {
		hasit[num % 10] += 1;
		num /= 10;
	}
	if (hasit[0])
		return 0;
	for(long i = 1; i <= n; ++i)
		if (hasit[i] != 1)
			return 0;
	return 1;
}

int numdigits(int number)
{
	int digitscount = 0;
	for (;number > 0; number /= 10)
		digitscount++;
	return digitscount;
}

int main()
{
	int num_threads = omp_get_num_procs();
	omp_set_num_threads(num_threads);
	int large[num_threads];
	for (int i = 0; i < num_threads; i++)
		large[i] = 0;

	#pragma omp parallel for 
	for (unsigned int i = 0; i <= 987654321; ++i) {
		if (isPandigital(i, numdigits(i)) && isPrime(i)) {
			large[omp_get_thread_num()] = i;
		}
	}
	int largest = 0;
	for (int i = 0; i < num_threads; i++)
		if (large[i] > largest)
			largest = large[i];
	printf("%d\n", largest);
	return 0;
}

