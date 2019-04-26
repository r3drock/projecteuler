/* List all possible lexicographic permutations of the 10 digits. */ 

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void rec(char number1[SIZE + 1], char number2[SIZE + 1], int i, int j);
void print(char number1[SIZE + 1], char number2[SIZE + 1]);

int main()
{
	char number1[SIZE + 1] = "0123456789";
	char number2[SIZE + 1] = "0123456798";
	rec(number1, number2, 2, 1);
}

void rec(char number1[SIZE + 1], char number2[SIZE + 1], int i, int j)
{
	//swap
	char temp = number1[SIZE - i];
	number1[SIZE - i] = number1[SIZE - j];
	number1[SIZE - j] = temp;
	temp = number2[SIZE - i];
	number2[SIZE - i] = number2[SIZE - j];
	number2[SIZE - j] = temp;

	print(number1, number2);

	//recursion
	for (int is = i + 1; is <= SIZE; ++is) {
		for (int js = is - 1; js >= 1; --js) {
			char *number1copy = malloc(SIZE + 1);
			char *number2copy = malloc(SIZE + 1);
			for (int n = 0; n < SIZE + 1; ++n) {
				number1copy[n] = number1[n];
				number2copy[n] = number2[n];
			}
			rec(number1copy, number2copy, is, js);
			free(number1copy);
			free(number2copy);
		}
	}
}
void print(char number1[SIZE + 1], char number2[SIZE + 1])
{
	printf("%s\n%s\n", number1, number2);
}
