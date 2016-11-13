#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void print_matrix(char* desc, int m, int n, double* a);

int main()
{
	int n = 3;
	int i, j, k;
	double *a;
	double *b;
	double *c;

	a = (double*)malloc(n * n * sizeof(double));
	b = (double*)malloc(n * n * sizeof(double));
	c = (double*)malloc(n * n * sizeof(double));

	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			a[j * n + i] = i;
			b[j * n + i] = i;
		}
	}

	#pragma omp parallel for private(i,k)
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			c[j * n + i] = 0.0;
			for (k = 0; k < n; k++)
			{
				c[j * n + i] = c[j * n + i] + a[j * n + k] * b[k * n + i];
			}
		}
	}

	print_matrix("A : ", n, n, a);
	print_matrix("B : ", n, n, b);
	print_matrix("C : ", n, n, c);

	free(a);
	free(b);
	free(c);

	return 0;
}

void print_matrix(char* desc, int m, int n, double* a) 
{
	int i, j;
	printf("\n %s\n", desc);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) printf(" %6.2f", a[i*n + j]);
		printf("\n");
	}
}