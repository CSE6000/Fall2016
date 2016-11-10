#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n = 10;
	int i, j, nthreads;
	double *x;
	double norm;
	double mysum;

	x = (double*)malloc(n * sizeof(double));

	for (i = 0; i < n; ++i)
	{
		x[i] = i;
	}

	//Incorrect code
	norm = 0.0;
	#pragma omp parallel for
	for (i = 0; i < n; i++)
	{
		norm = norm + fabs(x[i]);
	}
	printf("norm : %f\n", norm);

	//correct code
	norm = 0.0;
	#pragma omp parallel for reduction(+ : norm)
	for (i = 0; i < n; i++)
	{
		norm = norm + fabs(x[i]);
	}
	printf("norm : %f\n", norm);

	//A more complicated way to do this:
	norm = 0.0;
	#pragma omp parallel private(mysum) shared(norm)
	{
		mysum = 0;
		#pragma omp for
		for(i = 0; i < n; i++)
		{
			mysum = mysum + fabs(x[i]);
		}
		#pragma omp critical
		{
			norm = norm + mysum;
		}
	}
	printf("norm : %f\n", norm);

	int any_zero = 0;
	#pragma omp parallel for reduction(||: any_zero)
	for(i = 0; i < n; i++)
	{
		any_zero = any_zero || (x[i] == 0.0);
	}
	printf("any zero in x, (1 is true, 0 is false) : %d\n", any_zero);

	free(x);

	return 0;
}
