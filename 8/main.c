/* Find the thirteen adjacent digits in the 1000-digit number 
 * that have the greatest product. What is the value of this product?*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAGIC 13


int main()
{
	 unsigned long long digits[1000]; 

	 FILE * fr = fopen("number.txt", "rt");
	 if (fr == NULL) {
		 perror("Error in opening file.");
		 exit(-1);
	 }

	 {
		int i = -1;
	 	int temp = 1;
	 	while ((temp = fgetc(fr)) != EOF)
	 	    if (temp != 10)
	 	   	digits[++i] = (unsigned long long) (temp - 48);
	 	if (i >= 1000) {
	 	    fprintf(stderr,"read file to far.");
	 	    exit(-2);
	 	}
	 }

	 fclose(fr);

	 unsigned long long biggest_product = 1;
	 unsigned long long temp_product;

	for (int i = 0; i < MAGIC; ++i) 
		biggest_product *= digits[i];

	for (int i = MAGIC; i < (sizeof(digits)/sizeof(digits[0]) - MAGIC) + 1 ; ++i) {
		temp_product = 1;
		for (int j = 0; j < MAGIC; ++j) 
			temp_product *= digits[i+j];
		if (temp_product > biggest_product) 
			biggest_product = temp_product;
	}

	printf("The greatest product of thirteen adjacent digits in the number");

	for (int i = 0 ; i < sizeof(digits)/sizeof(digits[0]); ++i) {
		if( i % 50 == 0)
			printf("\n");
		printf("%llu",digits[i]);
	}

	printf("\nis: %llu\n", biggest_product);
	return 0;
}
