/* How many different ways can £2 be made using any number of coins? */

#include <stdio.h>

int main()
{
	int count = 0;
	for (int po2 = 0; po2 <= 1;  ++po2) {
	for (int po1 = 0; po1 <= 2;  ++po1) {
	for (int p50 = 0; p50 <= 4;  ++p50) {
	for (int p20 = 0; p20 <= 10; ++p20) {
	for (int p10 = 0; p10 <= 20; ++p10) {
	for (int p5  = 0; p5  <= 40;  ++p5) {
	for (int p2  = 0; p2  <= 100; ++p2) {
	for (int p1  = 0; p1  <= 200; ++p1) {
		int sum = (po2*200) + (po1*100) + (p50*50) + (p20*20) +
				(p10*10) + (p5*5) + (p2*2) + p1;
		if (sum == 200)
			++count;
		else if (sum >= 201) {
			p1 = 201;
			if (sum >= 202)
				p2 = 101;
			if (sum >= 205)
				p5 = 41;
		}
	}}}}}}}}

	printf("%d\n", count);
	return 0;
}

