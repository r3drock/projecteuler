/* Evaluate the sum of all the amicable numbers under 10000.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

struct list {
	struct list *next;
	int divisor;
};

int generate_divisors(struct list *divisors[SIZE])
{
	for (int i = 0; i < SIZE; ++i) {
		divisors[i] = (struct list *) malloc(sizeof(struct list));
		if (divisors[i] == NULL)
			return -1;
		divisors[i]->divisor = 1;
		divisors[i]->next = NULL;
	}


	for (int n = 1; n <= SIZE; ++n){
		struct list *tmpp = divisors[n];
		for (int possiblediv = 2; possiblediv <= n/2; ++possiblediv) {
			if (n % possiblediv == 0){
				tmpp->next = (struct list *) malloc(sizeof(struct list));
				if (tmpp->next == NULL)
					return -1;
				tmpp = tmpp->next;
				tmpp->next = NULL;
				tmpp->divisor = possiblediv;
			}
		}
	}
	return 0;
}

void freelist(struct list *divisors[SIZE])
{
	for (int i = 0; i < SIZE; ++i) {
		struct list *tmpp = divisors[i];
		while(tmpp) {
			struct list *tmpp2 = tmpp;
			tmpp = tmpp->next;
			free(tmpp2);
		}
	}
}

int d(struct list *divisors[SIZE], int n)
{
	int sum = 0;
	for (struct list *tmpp = divisors[n]; tmpp; tmpp = tmpp->next)
		sum += tmpp->divisor;
	return sum;
}

int get_anum_sum(struct list *divisors[SIZE])
{
	int sum = 0; 
	for (int a = 2; a < SIZE; ++a)
		for (int b = a; b < SIZE; ++b)
			if (a != b && d(divisors, a) == b && a == d(divisors, b)) {
			printf("d(%d) = %d, d(%d) = %d\n", a, d(divisors, a), b, d(divisors, b)); 

				sum += a + b;
			}
	return sum;
}

int main()
{
	struct list *divisors[SIZE];
	if (generate_divisors(divisors)) {
		printf("not enough memory!");
		return -1;
	}

	printf("The sum of all the amicable numbers under 10000 is:%d\n",
		get_anum_sum(divisors));

	freelist(divisors);
	return 0;
}
