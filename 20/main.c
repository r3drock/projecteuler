/* What is the sum of the digits of the number 2^100!?*/

#include <stdio.h>
#include <gmp.h>

int main()
{
	unsigned long sum = 0;
	mpz_t val;
	mpz_t temp;

	mpz_init(val);
	mpz_init(temp);

	mpz_set_ui(val, 1);

	for (unsigned long i = 100; i > 0; i--)
		mpz_mul_ui(val, val, i);	

	gmp_printf("100!: %Zd\n",val);
	while (mpz_cmp_ui(val,0)) {
		sum += mpz_mod_ui(temp, val, 10);
		mpz_div_ui(val, val, 10);
	}
	
	printf("The sum of the digits of the number 100! is: %lu\n",sum);

	mpz_clear(temp);
	mpz_clear(val);
	return 0;
}
