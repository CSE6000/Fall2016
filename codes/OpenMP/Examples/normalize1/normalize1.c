#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i;
	int n = 1000;

	double *x;
	double *y;

	double norm, ynorm;

	int nthreads;

	x = (double*)malloc(n * sizeof(double));
	y = (double*)malloc(n * sizeof(double));

	// Specify number of threads to use:
	nthreads = 1;       // need this value in serial mode
	nthreads = 4;
	omp_set_num_threads(nthreads);
	printf("Using OpenMP with %d threads\n", nthreads);

	// initialize x:
	#pragma omp parallel for
	for (i = 0; i < n; i++)
		x[i] = (double)i;  // convert to double float
	
	norm = 0.0;
	ynorm = 0.0;

	#pragma omp parallel private(i)
	{
		#pragma omp for reduction(+: norm)
		for (i = 0; i < n; i++)
			norm = norm + fabs(x[i]);

		#pragma omp barrier   //not needed(implicit)

		#pragma omp for reduction(+: ynorm)
		for (i = 0; i < n; i++)
		{
			y[i] = x[i] / norm;
			ynorm = ynorm + fabs(y[i]);
		}
	}

	printf("norm of x = %f  n(n+1)/2 = %d\n", norm, (n - 1)*(n / 2));
	printf("ynorm should be 1.0:   ynorm = %f\n", ynorm);

	return 0;
}