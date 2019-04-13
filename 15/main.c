/*Starting in the top left corner of a 2×2 grid, and only
 *being able to move to the right and down, there are exactly
 *6 routes to the bottom right corner.
 *How many such routes are there through a 20×20 grid? */

#define MAX 20

#include <stdio.h>

unsigned long long routescount(int x, int y, int xmax, int ymax)
{
	if (x ==  xmax || y == ymax)
		return 1;
	else
		return routescount(x + 1, y, xmax, ymax) + 
			routescount(x, y + 1, xmax, ymax);
}

int main()
{
	for (int i = 2; i <= MAX; ++i)
		printf("There are %llu routes to the bottom right corner in a %dx%d-grid.\n",
				routescount(0, 0, i, i), i, i);
	return 0;
}
