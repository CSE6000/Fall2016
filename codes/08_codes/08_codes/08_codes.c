#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

int main()
{
	printf("pi = %.16f\n", M_PI);
	printf("1000 * pi = %.16f\n", 1000.0 * M_PI);

	double y = 1. + 3.e-16;
	printf("y = %.16f\n", y);
	printf("y - 1.0 = %.16e\n", y - 1.0);

	y = 1.0 + 1e-16;
	printf("y = %.16f\n", y);
	printf("%d\n", y == 1.0);

	printf("pi = %.16f\n", M_PI);
	y = M_PI * 1.e-10;
	printf("y = %.16e\n", y);

	double z = 1.0 + y;
	printf("z = %.16f\n", z);
	printf("z - 1 = %.16e\n", z - 1.0);

	return 0;
}