/* What is the index of the first term in the Fibonacci sequence to contain 1000 digits? */

#include <stdio.h>
#include <gmp.h>

int main()
{
	mpz_t previous;  
	mpz_t temp;  
	mpz_t current;
	mpz_t limit;

	mpz_init(previous);
	mpz_init(temp);
	mpz_init(current);
	mpz_init(limit);

	mpz_set_ui(previous, 1);
	mpz_set_ui(current, 1);

	mpz_ui_pow_ui(limit, 10, 1000 - 1);

	int index = 2;
	while (mpz_cmp(current, limit) < 0) {
		mpz_set(temp, current);
		mpz_add(current, previous, current);
		mpz_set(previous, temp);
		index++;
	}
	gmp_printf("The index of the first term in the Fibonacci sequence (%Zd) to  \
contain 1000 digits is: %d\n", current, index);  
	return 0;
}
