#include <stdio.h>
#include "mymath.h"


int main()
{
	double x = 2.;
	double s = mysqrt(x, true);
	printf("\nmysqrt(%f) = %f\n", x, s);
	return 0;
}