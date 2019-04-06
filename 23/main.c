/*Find the sum of all the positive integers which cannot be written as the 
 * sum of two abundant numbers.*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LIMIT 28124

struct list {
	struct list *next;
	int val;
};

void find_ab_numbers(struct list *ab_numbers);
void freelist(struct list *divisors[LIMIT]);
int generate_divisors(struct list *divisors[LIMIT]);
void find_sum_numbers(struct list* ab_numbers,
					  unsigned int sum_of_two_ab_numbers[LIMIT]);

int main()
{
	struct list *ab_numbers;
	ab_numbers = (struct list *) malloc(sizeof(struct list));
	//int ab_numbers_array[LIMIT];
	unsigned long long sum = 0;
	unsigned int sum_of_two_ab_numbers[LIMIT];
	for (int i = 0; i < LIMIT; ++i) {
		sum_of_two_ab_numbers[i] = 0;
	}

	//find abundant numbers
	find_ab_numbers(ab_numbers);	
	
	/*Find numbers between 24 and 28123 which can be written as the sum
	 * of two abundant numbers.*/
	find_sum_numbers(ab_numbers, sum_of_two_ab_numbers);
	
	//Sum up all remaining numbers which cannot be written as the sum
	//of two abundant numbers.
	for (int i = 1; i < LIMIT; ++i) {
		if (sum_of_two_ab_numbers[i] == 0) {
			sum += i;
		}
	}

	printf("sum: %llu\n", sum);
	
	while(ab_numbers) {
		struct list *tmpp2 = ab_numbers;
		ab_numbers = ab_numbers->next;
		free(tmpp2);
	}
	return 0;
}

void find_sum_numbers(struct list* ab_numbers,
					  unsigned int sum_of_two_ab_numbers[LIMIT])
{
		struct list *tmpp = ab_numbers;
		while (tmpp) {
			struct list *tmpp2 = ab_numbers;
			while (tmpp2) {
				//assert(tmpp->val != 0 && tmpp2->val != 0);
				int index = tmpp->val + tmpp2->val;
				if (index >= LIMIT)
					break;
				sum_of_two_ab_numbers[index] = 1;
				tmpp2 = tmpp2->next;
			}
			tmpp = tmpp->next;
		}
}

void find_ab_numbers(struct list *ab_numbers)
{
	struct list *divisors[LIMIT];
	if (generate_divisors(divisors)) {
		fprintf(stderr, "not enough memory!");
		exit(-1);
	}

	ab_numbers->val = 12;
	for (int i = 13; i < LIMIT; ++i) {
		int divisorsum = 0;
		for(struct list *current = divisors[i]; 
			current != NULL;
			current = current->next) {
			divisorsum += current->val;
		}
		if (divisorsum > i ){
			ab_numbers->next = (struct list *) malloc(sizeof(struct list));
			ab_numbers = ab_numbers->next;
			ab_numbers->val = i;
		}
	}
	ab_numbers->next = NULL;
	freelist(divisors);
}

int generate_divisors(struct list *divisors[LIMIT])
{
	for (int i = 0; i < LIMIT; ++i) {
		divisors[i] = (struct list *) malloc(sizeof(struct list));
		if (divisors[i] == NULL)
			return -1;
		divisors[i]->val = 1;
		divisors[i]->next = NULL;
	}


	for (int n = 1; n <= LIMIT; ++n){
		struct list *tmpp = divisors[n];
		for (int possiblediv = 2; possiblediv <= n/2; ++possiblediv) {
			if (n % possiblediv == 0){
				tmpp->next = (struct list *) malloc(sizeof(struct list));
				if (tmpp->next == NULL)
					return -1;
				tmpp = tmpp->next;
				tmpp->next = NULL;
				tmpp->val = possiblediv;
			}
		}
	}
	return 0;
}

void freelist(struct list *divisors[LIMIT])
{
	for (int i = 0; i < LIMIT; ++i) {
		struct list *tmpp = divisors[i];
		while(tmpp) {
			struct list *tmpp2 = tmpp;
			tmpp = tmpp->next;
			free(tmpp2);
		}
	}
}
