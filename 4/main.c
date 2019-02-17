/* Find the largest palindrome made from the product of two 3-digit numbers. */

#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int number)
{
	int temp = number;
	int number_digits = 0;

	while (temp > 0){
		temp /= 10;
		++number_digits;
	}

	int numbers[number_digits];
	temp = number;

	for (int i = 0; i < number_digits; ++i) {
		numbers[i] = temp % 10;			
		temp/=10;
	}

	for (int i = 0; i < number_digits / 2; ++i)
		if (numbers[i] != numbers[number_digits - i - 1])
			return 0;
	return 1;
}

int main()
{
	int largest_palindrome = 0;
	int number1,number2;

	for (int i = 999; i >= 100; --i)
		for (int j = 999; j >= 100; --j)
			if (isPalindrome(i * j))
				if(largest_palindrome < (i * j)) {
					largest_palindrome = i * j;
					number1 = i;
					number2 = j;
				}
	
	printf("%d is the lagrgest Palindrome made from the product of the two \
3 digit numbers: %d and %d.\n",largest_palindrome,number1,number2);
	
	return 0;
}
