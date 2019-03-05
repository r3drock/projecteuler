/*What is the greatest product of four adjacent numbers in the same direction
 *(up, down, left, right, or diagonally) in the 20×20 grid?*/

#include <stdio.h>
#include <stdlib.h>

#define XSIZE 20
#define YSIZE 20
void assert_number(char c)
{
	if (c < '0' || c > '9') {
		fprintf(stderr,"Wrong file format given.");
		exit(-1);
	}
}
void readin(long long grid[YSIZE][XSIZE], char filename[])
{
	FILE * fr = fopen(filename, "rt");
	if (fr == NULL) {
	    fprintf(stderr,"Error opening file.");
	    exit(-1);
	}

	for (unsigned int y = 0; y < YSIZE; ++y) {
		for (unsigned int x = 0; x < XSIZE; ++x) {
			if (!feof(fr)) {
				int errnum = fscanf(fr, "%lld",&grid[y][x]);
				if (errnum <= 0) {
					fprintf(stderr,"File must only consist of Numbers seperated \
by spaces and newlines.\n");
					exit(-1);
				}
			} else {
				fprintf(stderr,"End of File Reached to early.");
				exit(-1);
			}
		}
	}
}
void print_2d_array(long long array[YSIZE][XSIZE])
{
	for (unsigned int y = 0; y < YSIZE; ++y) {
		for (unsigned int x = 0; x < XSIZE; ++x) {
			if (array[y][x]<10) 
				printf(" %lld ",array[y][x]);
			else
				printf("%lld ",array[y][x]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	long long grid[YSIZE][XSIZE];  

	long long product = 0;	

	if (argc < 2) {
		fprintf(stderr,"Usage %s <filename>", argv[0]);	
		return EXIT_FAILURE;
	}		

	readin(grid, argv[1]);
	print_2d_array(grid);

	//up down
	for (int y = 0; y < (YSIZE - 3); ++y) {
		for (int x = 0; x < XSIZE; ++x) {
			long long temp = grid[y][x] * grid[y+1][x] * 
							 grid[y+2][x] * grid[y+3][x]; 
			if (temp > product) {
				product = temp;
				printf("x: %d y: %d u[%llu,%llu,%llu,%llu]\n%llu\n", x, y, grid[y][x],grid[y+1][x], 
					   grid[y+2][x], grid[y+3][x], temp);
			}
		}
	}

	//left right
	for (int y = 0; y < YSIZE; ++y) {
		for (int x = 0; x < XSIZE - 3; ++x) {
			long long temp = grid[y][x] * grid[y][x+1] * 
							 grid[y][x+2] * grid[y][x+3]; 
			if (temp > product) {
				product = temp;
				printf("x: %d y: %d l[%llu,%llu,%llu,%llu]\n%llu\n", x, y,grid[y][x],grid[y][x+1], 
					   grid[y][x+2], grid[y][x+3], temp);
			}
		}
	}

	//diagonally left to right
	for (int y = 0; y < YSIZE - 3; ++y) {
		for (int x = 0; x < XSIZE - 3; ++x) {
			long long temp = grid[y][x] * grid[y+1][x+1] * 
							 grid[y+2][x+2] * grid[y+3][x+3]; 
			if (temp > product) {
				product = temp;
				printf("x: %d y: %d [%llu,%llu,%llu,%llu]\n%llu\n", x, y, grid[y][x],grid[y+1][x+1], 
					   grid[y+2][x+2], grid[y+3][x+3], temp);
			}
		}
	}

	//diagonally right to left
	for (int y = YSIZE - 1; y >= 3; --y) {
		for (int x = 0; x < XSIZE - 3; ++x) {
			long long temp = grid[y][x] * grid[y-1][x+1] * 
							 grid[y-2][x+2] * grid[y-3][x+3]; 
			if (temp > product) {
				product = temp;
				printf("x: %d y: %d x[%llu,%llu,%llu,%llu]\n%llu\n", x, y, grid[y][x],grid[y-1][x+1], 
					   grid[y-2][x+2], grid[y-3][x+3], temp);
			}
		}
	}

	printf("The greatest product of four adjacent numbers in the same direction\n\
is: %llu", product); 

	return 0;
}
