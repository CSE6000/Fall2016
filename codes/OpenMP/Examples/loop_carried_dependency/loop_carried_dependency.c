#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void example1()
{
	int n;
	int i;
	double dt;
	double *y;

	n = 5000; //number of steps to reach t = 5000
	y = (double*)malloc(n * sizeof(double));
	y[0] = 1.0;
	dt = 0.001; //time step
	for (i = 1; i < n; i++)
	{
		y[i] = y[i - 1] + dt * 2.0 * y[i - 1];
	}
	free(y);
}

void example2()
{
	int n = 10;
	int i;
	double y;
	double *x;

	x = (double*)malloc(n * sizeof(double));
	y = 0.0;
	for (i = 0; i < n; i++)
	{
		if (i == 3)
			y = 1.0;
		x[i] = y;
	}

	free(x);
}

int main()
{
	example1();

	example2();

	return 0;
}