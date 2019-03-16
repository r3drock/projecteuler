/* What is the sum of the digits of the number 2^1000?*/

#include <stdio.h>
#include <gmp.h>
#include <limits.h>

int main()
{
	unsigned long sum = 0;
	mpz_t val;
	mpz_t temp;

	mpz_init(val);
	mpz_init(temp);

	mpz_ui_pow_ui(val, 2, 1000);	

	while (mpz_cmp_ui(val,0)) {
		sum += mpz_mod_ui(temp, val, 10);
		mpz_div_ui(val, val, 10);
	}
	
	printf("The sum of the digits of the number 2^1000 is: %lu\n",sum);

	mpz_clear(temp);
	mpz_clear(val);
	return 0;
}
