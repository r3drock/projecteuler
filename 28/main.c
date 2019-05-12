/* What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way? */

#include "stdio.h"

#define SIZE 1001

void buildSpiral(unsigned int spiral[SIZE][SIZE]);

unsigned long long calculateDiagonalSum(unsigned int spiral[SIZE][SIZE]);

void printSpiral(unsigned int spiral[SIZE][SIZE]);

int main()
{
	unsigned int spiral[SIZE][SIZE];
	buildSpiral(spiral);
	printf("the sum of the diagonals is: %llu\n", calculateDiagonalSum(spiral));
	return 0;
}

void buildSpiral(unsigned int spiral[SIZE][SIZE])
{
	enum {right, down, left, up};
	int state = right;


	unsigned int x = SIZE / 2;
	unsigned int y = SIZE / 2;

	unsigned int innerspiralsize = 3;
	unsigned int lefttowrite = 0;

	spiral[x++][y] = 1;

	unsigned int currentnumber = 2;

	while (x < SIZE && x >= 0 && y < SIZE && y >= 0){
		switch (state) {
			case right: 
				if (lefttowrite == 0) {
					spiral[x][y++] = currentnumber++;
					state = down;
					lefttowrite = innerspiralsize - 2;
					break;
				}
				while (--lefttowrite) {
					spiral[x++][y] = currentnumber++;
				}



				break;
			case down: 
				if (lefttowrite == 0) {
					spiral[x--][y] = currentnumber++;
					state = left;
					lefttowrite = innerspiralsize - 1;
					break;
				}
				while (--lefttowrite) {
					spiral[x][y++] = currentnumber++;
				}


				break;
			case left:
				if (lefttowrite == 0) {
					spiral[x][y--] = currentnumber++;
					state = up;
					lefttowrite = innerspiralsize - 1;
					break;
				}
				while (--lefttowrite) {
					spiral[x--][y] = currentnumber++;
				}

				break;
			case up:
				if (lefttowrite == 0) {
					spiral[x++][y] = currentnumber++;
					state = right;
					innerspiralsize += 2;
					lefttowrite = innerspiralsize - 2;
					break;
				}
				while (--lefttowrite) {
					spiral[x][y--] = currentnumber++;
				}
				break;
		}
	}
}

unsigned long long calculateDiagonalSum(unsigned int spiral[SIZE][SIZE])
{
	unsigned long long sum = 0;
	for (int i = 0; i < SIZE; ++i) {
		sum += spiral[i][i];
		sum += spiral[SIZE - 1 - i][i];
	}
	return sum - 1;
}

void printSpiral(unsigned int spiral[SIZE][SIZE])
{
	for (int y = 0; y < SIZE; ++y) {
		for (int x = 0; x < SIZE; ++x) {
			printf("%3d ", spiral[x][y]);
		}
		printf("\n");
	}
}
