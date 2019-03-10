/* What is the value of the first triangle number 
 * to have over five hundred divisors? */

#define NUMCOUNT 100

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print(char numberstring[NUMCOUNT][15])
{
	for (int i = 0; i < NUMCOUNT; ++i)
		printf("%s\n",numberstring[i]);
}

void loadnumbers(unsigned long long numbers[])
{
	char c;
	char numberstring[NUMCOUNT][15];
	int i = 0;
	int j = 0; 
	while ((c = getchar()) != EOF) {
		if (j == NUMCOUNT) {
			fprintf(stderr, "File is to long. It has to be 100 lines long.");	
			exit(-1);
		}

		if (c == '\n') {
			i = 0;
			++j;
		}
		else if (i == 14) {
			numberstring[j][i++] = '\0';
		}
		else if (i < 14 && c <= '9' && c >= '0') {
			numberstring[j][i++] = c;
		}
	}
			
	if (j < NUMCOUNT) {
		fprintf(stderr, "File is to short. It has to be 100 lines long.");	
		exit(-1);
	}
	//print(numberstring);
	for (i = 0; i < NUMCOUNT; ++i)
		numbers[i] = atoll(numberstring[i]);
}

int main()
{
	unsigned long long numbers[NUMCOUNT];
	unsigned long long sum = 0;

	loadnumbers(numbers);

	for (int i = 0; i < NUMCOUNT; ++i)
		sum += numbers[i];
	

	printf("The first 10 digits of the sum are: ");

    char *s = malloc((10 + 1) * sizeof(char));
	snprintf(s, 11, "%llu", sum);

    if (s != NULL) {
		printf("%s\n",s);
		free(s);
	}

	return 0;
}
