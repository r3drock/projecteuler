/* Find the denominator of the product of the four non-trivial examples of a
 * curious fraction containing two digits in the numerator and denominator. */

#include <stdio.h>

typedef struct frac{
	int n;
	int d;
} frac;

void multiply(frac* f1, frac f2);
char isCuriousFraction(frac f); 
char equals(frac f1, frac f2); 
int gcd(frac f);
void printfrac(frac f);
frac simplify(frac f);

int main()
{
	frac product = {1, 1};
	for (int numerator = 10; numerator <= 99; ++numerator) {
		for (int denominator = 10; denominator <= 99; ++denominator) {
			frac f = (frac) {numerator, denominator};
			if (isCuriousFraction(f)) {
				multiply(&product, f);
			}
		}
	}

	printf("%d\n", product.d);
	return 0;
}

void multiply(frac* f1, frac f2)
{
	f1->n = f1->n * f2.n;	
	f1->d = f1->d * f2.d;	
	int g = gcd(*f1);
	f1->n /= g; 
	f1->d /= g; 
}

int gcd(frac f)
{
	int a = f.n;
	int b = f.d;
	int d = 0;
	while (a % 2 == 0 && b %2 == 0) {
		a /= 2;
		b /= 2;
		++d;
	}
	while (a != b) {
		if (a % 2 == 0)
			a /= 2;
		else if (b % 2 == 0)
			b /= 2; 
		else if (a > b)
			a = (a - b) / 2;
		else
			b = (b - a) / 2;
	}
	if (d == 0)
		return a;
	return a * (2 << (d - 1));  
}

char isCuriousFraction(frac f)
{
	int rdn = f.n % 10;
	int ldn = f.n / 10;
	int rdd = f.d % 10;
	int ldd = f.d / 10;

	if (rdn == 0 || ldn == 0 ||
	    rdd == 0 || ldd == 0)
		return 0;
	if (f.n == f.d)
		return 0;

	if (rdn == ldd) {
		frac t = {ldn, rdd};
		if (equals(t, simplify(f)))
			return 1;
	}
	return 0;
}

char equals(frac f1, frac f2)
{
	f1 = simplify(f1);
	f2 = simplify(f2);
	return (f1.n == f2.n) && (f1.d == f2.d);
}

void printfrac(frac f)
{
	printf("%d/%d\n", f.n, f.d);
}

frac simplify(frac f)
{
	frac f2 = {1, 1};	
	f.n = f.n * f2.n;	
	f.d = f.d * f2.d;	
	int g = gcd(f);
	f.n /= g; 
	f.d /= g; 
	return f;
}
