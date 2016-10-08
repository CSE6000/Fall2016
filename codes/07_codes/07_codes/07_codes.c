#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i;
	int j;
	double z = 0.0;
	double w = 0.0;
	double* pX;
	int length = 1024 * 10;

	pX = (double*)malloc(length * sizeof(double));
	for (int i = 0; i < length; i++)
	{
		pX[i] = i;
	}
	
	//Temporal locality
	//Case 1
	for (i = 0; i < length; i++)
	{
		z = z + pX[i];
	}
	for (i = 0; i < length; i++)
	{
		w = w + 3.0 * pX[i];
	}

	//Case 2
	z = 0.0;
	w = 0.0;
	for (i = 0; i < length; i++)
	{
		z = z + pX[i];
		w = w + 3.0 * pX[i];
	}

	free(pX);

	//Spatial locality
	double** a;
	double** b;
	double* d;
	int n = 1000;

	//memory allocation
	a = (double**)malloc(n * sizeof(double*));
	b = (double**)malloc(n * sizeof(double*));
	d = (double*)malloc(n * sizeof(double));

	for (i = 0; i < n; i++)
	{
		a[i] = (double*)malloc(n * sizeof(double));
		b[i] = (double*)malloc(n * sizeof(double));
	}

	//memory initialzation
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = j;
			b[i][j] = 0;
		}
		d[i] = i;
	}

	//Case 1
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			b[i][j] = d[i] * a[i][j];
		}
	}


	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			b[i][j] = 0;
		}
	}

	//Case 2
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			b[i][j] = d[i] * a[i][j];
		}
	}

	for (i = 0; i < n; i++)
	{
		free(a[i]);
		free(b[i]);
	}
	free(d);

	return 0;
}