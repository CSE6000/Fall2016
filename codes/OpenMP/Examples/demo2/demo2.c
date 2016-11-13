#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 100000;
	int i;
	int debug = 0;
	double *x;
	double *y;
	double *z;
	
	x = (double*)malloc(n * sizeof(double));
	y = (double*)malloc(n * sizeof(double));
	z = (double*)malloc(n * sizeof(double));

	#pragma omp parallel num_threads(2) // spawn two threads
	{
		#pragma omp sections //split up work between them
		{
			if (debug)
				printf("start, thread_num : %d\n", omp_get_thread_num());
			#pragma omp section //one thread initializes x array
			{
				if (debug)
					printf("x section, thread_num : %d\n", omp_get_thread_num());
				for (i = 0; i < n; i++)
					x[i] = 1.0;
			}

			#pragma omp section //another thread initializes x array
			{
				if (debug)
					printf("y section, thread_num : %d\n", omp_get_thread_num());
				for (i = 0; i < n; i++)
					y[i] = 1.0;
			}
		}
		#pragma omp barrier // not needed, implied at end of sections

		#pragma omp single
		{
			printf("Done initializing x and y, thread_num : %d\n", omp_get_thread_num());
		}

		#pragma omp for
		for (i = 0; i < n; i++)
		{
			z[i] = x[i] + y[i];
			if (debug)
				printf("z[%d] = %f, thread_num : %d\n", i, z[i], omp_get_thread_num());
		}
	}

	return 0;
}