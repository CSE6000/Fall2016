#define _USE_MATH_DEFINES

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// Add your header file

int main(int argc, char* argv[])
{
	double x;
	int iter;
	//Check argument count	
	if (argc == 1)
	{
		printf("myexp() example\n");
		x = 1;
		iter = 0;
		//printf("x = %f, iter = %2d, %.15f\n", x, iter, myexp(x, iter));

		iter = 1;
		//printf("x = %f, iter = %2d, %.15f\n", x, iter, myexp(x, iter));

		iter = 2;
		//printf("x = %f, iter = %2d, %.15f\n", x, iter, myexp(x, iter));

		iter = 20;
		//printf("x = %f, iter = %2d, %.15f\n", x, iter, myexp(x, iter));

		iter = -5;
		//printf("x = %f, iter = %2d, %f\n", x, iter, myexp(x, iter));

		printf("mysin() example\n");
		x = M_PI / 2; iter = 2;
		//printf("x = %f, iter = %2d, %.15f\n", x, iter, mysin(x, iter));

		iter = 3;
		//printf("x = %f, iter = %2d, %.15f\n", x, iter, mysin(x, iter));

		iter = 4;
		//printf("x = %f, iter = %2d, %.15f\n", x, iter, mysin(x, iter));

		iter = 5;
		//printf("x = %f, iter = %2d, %.15f\n", x, iter, mysin(x, iter));

		iter = -3;
		//printf("x = %f, iter = %2d, %f\n", x, iter, mysin(x, iter));

		return 1;
	}

	if (argc == 2 && (strcmp(argv[1], "output") == 0))
	{
		x = 1.0;
		iter = 20;
		//double exp_true = exp(x);
		//double exp_taylor = myexp(x, iter);
		printf("=== myexp() ===\n");
		//printf("x = %.15f\n", x);
		//printf("iterations = %d\n", iter);
		//printf("exp_true = %.15f\n", exp_true);
		//printf("exp_tayor = %.15f\n", exp_taylor);
		//printf("error = %e\n", exp_taylor - exp_true);

		printf("\n");

		x = M_PI / 2;
		iter = 10;
		printf("=== mysin() ===\n");
		//double sin_true = sin(x);
		//double sin_taylor = mysin(x, iter);
		//printf("x = %.15f\n", x);
		//printf("iterations = %d\n", iter);
		//printf("sin_true = %.15f\n", sin_true);
		//printf("sin_taylor = %.15f\n", sin_taylor);
		//printf("error = %e\n", sin_taylor - sin_true);
	}

	return 1;
}