/* If all the numbers from 1 to 1000 (one thousand) inclusive 
 * were written out in words, how many letters would be used?*/ 

#include <stdio.h>

int spellletter(int num)
{
	printf("%d",num);
	int digits[3] = {0.0,0};
	int sum = 0;

	if (num == 1000) 
		return 11;
	if (num > 1000)
		return -1;

	if (num % 100 != 0 && num > 100)
		sum += 3;

	for (int i = 2; i >= 0 ; --i) {
		digits[i] = num % 10;
		num /= 10;
	}

	switch (digits[0]) {
		case 0: 
			break;
		case 1: case 2: case 6: 
			sum += 10;
			break; 
		case 3: case 7: case 8: 
			sum += 12;
			break;
		case 4: case 5: case 9: 
			sum += 11;
			break;
	}
	switch (digits[1]) {
		case 0:
			break;
		case 1:
			if (digits[2] == 0 || digits[2] == 1 || digits[2] == 2 ||
				digits[2] == 3 || digits[2] == 5)
				sum += 3;
			else
				sum += 4;
			break;
		case 2: case 3: case 9: 
			sum += 6;
			break; 
		case 4: case 5: case 6: 
			sum += 5;
			break;
		case 7: case 8: 
			sum += 7;
			break;
	}
	switch (digits[2]) {
		case 0:
			break;
		case 1: case 2: case 6:
			sum += 3;
			break; 
		case 3: case 7: case 8:
			sum += 5;
			break;
		case 4: case 5: case 9:
			sum += 4;
			break;
	}
	printf("\t%d\n",sum);
	return sum;
}
/* Get lettercount in a number */
int get_letter_count(int num)
{
	printf("%d",num);
	int digits[3] = {0.0,0};
	int sum = 0;

	if (num == 1000)
		return 11;
	if (num >1000)
		return -1;

	if (num % 100 != 0 && num > 100)
		sum += 3;

	for (int i = 2; i >= 0 ; --i) {
		digits[i] = num % 10;
		num /= 10;
	}

	switch (digits[0]) {
		case 0: 
			break;
		case 1: case 2: case 6: 
			sum += 10;
			break; 
		case 3: case 7: case 8: 
			sum += 12;
			break;
		case 4: case 5: case 9: 
			sum += 11;
			break;
	}
	switch (digits[1]) {
		case 0:
			break;
		case 1:
			if (digits[2] == 0 || digits[2] == 1 || digits[2] == 2 ||
				digits[2] == 3 || digits[2] == 5)
				sum += 3;
			else
				sum += 4;
			break;
		case 2: case 3: case 9: 
			sum += 6;
			break; 
		case 4: case 5: case 6: 
			sum += 5;
			break;
		case 7: case 8: 
			sum += 7;
			break;
	}
	switch (digits[2]) {
		case 0:
			break;
		case 1: case 2: case 6:
			sum += 3;
			break; 
		case 3: case 7: case 8:
			sum += 5;
			break;
		case 4: case 5: case 9:
			sum += 4;
			break;
	}
	printf("\t%d\n",sum);
	return sum;
}

int main()
{
	int sum = 0;
	for (int i = 1; i <= 1000; ++i)
		sum += get_letter_count(i);

	printf("%d letters are used.\n", sum);

	return 0;
}
