/* Find the thirteen adjacent digits in the 1000-digit number 
 * that have the greatest product. What is the value of this product?*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN 15

int actualLen = 15;

struct list {
	int line[LEN];
	struct list *next;
};

int max (int a, int b)
{
	return (a > b) ? a : b; 
}

void printPyramid(struct list *current)
{
	for (int i = 1; i <= actualLen; ++i) {
		for (int j = 0; j < i; ++j) {
			printf("%d ",(current->line)[j]);
		}
		printf("\n");
		current = current->next;
	}
}

void readpyramid(struct list *current)
{
	int errNum;
	int c;
	int ln = 0;

	for (int i = 1; ((c = getchar()) != EOF) && i <= LEN; ++i, ++ln) {
		ungetc(c,stdin);
		if (i != 1) {
			current->next = malloc(sizeof(struct list));
			current = current->next;
		}
		for (int j = 0; j < i ; ++j) {
			errNum = scanf("%d",&(current->line)[j]);
			if (errNum <= 0) {
				fprintf(stderr,"format error");
				exit(-1);
			}
		}
		while ((c = getchar()) != '\n')
			;
	}
	actualLen = ln;
}

int main()
{
	struct list start; 
	readpyramid(&start);
	/*printPyramid(&start);*/
	
	int maxsum[actualLen][actualLen];
	struct list *current = &start; 
	maxsum[0][0] = current->line[0];
	current = current->next;

	for (int i = 1; i < actualLen; ++i) {
		if ( i != 1) {
			current = current->next;
		}
		for (int j = 0; j <= i; ++j) {
			if (j == 0) {
				maxsum[i][j] = maxsum[i- 1][j] + current->line[j];
				continue;
			}
			if (j == i) {
				maxsum[i][j] = maxsum[i-1][j-1] + current->line[j];
				continue;
			}
			maxsum[i][j] = max(maxsum[i-1][j-1],maxsum[i-1][j]) +
				current->line[j];
		}
	}
	/*printf("distancesums %d \n",maxsum[0][0]);*/
	/*for (int i = 0; i < actualLen; ++i) {*/
		/*for (int j = 0; j <= i; ++j) {*/
			/*printf("%d ",maxsum[i][j]);*/
		/*}*/
		/*printf("\n");*/
	/*}*/
	int singlemaxsum = -1;
	for (int i = 0; i < actualLen; ++i)
		singlemaxsum = max(singlemaxsum, maxsum[actualLen-1][i]); 
		
	printf("The maximum path sum is %d.\n",singlemaxsum);
		
	return EXIT_SUCCESS;
}
