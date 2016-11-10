#include <stdio.h>
#include <stdlib.h>
#include <mkl.h>

#define LOOP_COUNT 10

int main()
{
	int i;
	int j;
	double s_initial, s_elapsed;

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
	s_initial = dsecnd();
	for (int t = 0; t < LOOP_COUNT; t++)
	{
		for (i = 0; i < length; i++)
		{
			z = z + pX[i];
		}
		for (i = 0; i < length; i++)
		{
			w = w + 3.0 * pX[i];
		}
	}
	s_elapsed = (dsecnd() - s_initial) / LOOP_COUNT;
	printf(" == Temporal locality Case 1 == \n"
		" == %.5f milliseconds == \n\n", (s_elapsed * 1000));

	//Case 2
	z = 0.0;
	w = 0.0;
	s_initial = dsecnd();
	for (int t = 0; t < LOOP_COUNT; t++)
	{
		for (i = 0; i < length; i++)
		{
			z = z + pX[i];
			w = w + 3.0 * pX[i];
		}
	}
	s_elapsed = (dsecnd() - s_initial) / LOOP_COUNT;
	printf(" == Temporal locality Case 2 == \n"
		" == %.5f milliseconds == \n\n", (s_elapsed * 1000));

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
	s_initial = dsecnd();
	for (int t = 0; t < LOOP_COUNT; t++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				b[i][j] = d[i] * a[i][j];
			}
		}
	}
	s_elapsed = (dsecnd() - s_initial) / LOOP_COUNT;
	printf(" == Spatial locality Case 1 == \n"
		" == %.5f milliseconds == \n\n", (s_elapsed * 1000));

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			b[i][j] = 0;
		}
	}

	//Case 2
	s_initial = dsecnd();
	for (int t = 0; t < LOOP_COUNT; t++)
	{
		for (j = 0; j < n; j++)
		{
			for (i = 0; i < n; i++)
			{
				b[i][j] = d[i] * a[i][j];
			}
		}
	}
	s_elapsed = (dsecnd() - s_initial) / LOOP_COUNT;
	printf(" == Spatial locality Case 2 == \n"
		" == %.5f milliseconds == \n\n", (s_elapsed * 1000));

	for (i = 0; i < n; i++)
	{
		free(a[i]);
		free(b[i]);
	}
	free(d);

	return 0;
}