/* Find the largest palindrome made from the product of two 3-digit numbers. */

#include <stdio.h>

int isPalindrome(int number, int base)
{
	int temp = number;
	int number_digits = 0;

	while (temp > 0){
		temp /= base;
		++number_digits;
	}

	int numbers[number_digits];
	temp = number;

	for (int i = 0; i < number_digits; ++i) {
		numbers[i] = temp % base;			
		temp/=base;
	}

	for (int i = 0; i < number_digits / 2; ++i)
		if (numbers[i] != numbers[number_digits - i - 1])
			return 0;
	return number;
}

int main()
{
	long sum = 0;

	for (int i = 1; i < 1000000; ++i)
		sum += isPalindrome(i,10) ? isPalindrome(i,2) : 0;
	
	printf("%ld\n", sum);
	return 0;
}
