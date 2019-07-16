/* For which value of p ≤ 1000, is the number of pythagorean triplets with
 * perimeter p maximised? */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAGIC 1000

int main()
{
	int p[MAGIC + 1];
	for (int i = 0; i < MAGIC + 1; ++i)
		p[i] = 0;

	for (int a = 1; a <= MAGIC; ++a) {
		for (int b = a; b <= MAGIC; ++b) {
			int c = (int) sqrt((a * a) + (b * b));
			if (c >= MAGIC) {
				b = MAGIC * 2;
			}
			if ((a * a) + (b * b) == (c * c)) {
				p[a + b + c]++;
			}
		}
	}

	int ps = 0;
	int maxsolutions = 0;
	for (int i = 1; i <= MAGIC; ++i) {
		if (p[i] > maxsolutions) {
			maxsolutions = p[i];
			ps = i;
		}
	}

	fprintf(stderr, "%d\n", ps);
	return 0;
}
