#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n = 1000;

	double *x;
	double *y;

	double norm, norm_thread, ynorm, ynorm_thread;
	int nthreads, points_per_thread, thread_num;
	int i, istart, iend;

	x = (double*)malloc(n * sizeof(double));
	y = (double*)malloc(n * sizeof(double));

	// Specify number of threads to use:
	nthreads = 1;       // need this value in serial mode
	nthreads = 4;
	omp_set_num_threads(nthreads);
	printf("Using OpenMP with %d threads\n", nthreads);

	// Determine how many points to handle with each thread.
	// Note that dividing two integers and assigning to an integer will
	// round down if the result is not an integer.  
	// This, together with the min(...) in the definition of iend below,
	// insures that all points will get distributed to some thread.
	points_per_thread = (n + nthreads - 1) / nthreads;
	printf("points_per_thread = %d\n", points_per_thread);

	// initialize x:	
	#pragma omp parallel for
	for (i = 0; i < n; i++)
		x[i] = (double)i;  // convert to double float

	norm = 0.0;
	ynorm = 0.0;

	#pragma omp parallel private(i, norm_thread, istart, iend, thread_num, ynorm_thread)
	{

		thread_num = 0; // needed in serial mode
		thread_num = omp_get_thread_num(); // unique for each thread

		// Determine start and end index for the set of points to be handled by this thread:
		istart = thread_num * points_per_thread;
		iend = min((thread_num + 1) * points_per_thread, n);

		#pragma omp critical
		{
			printf("Thread %d will take i = %d through i = %d\n", thread_num, istart, iend);
		}

		norm_thread = 0.0;
		for (i = istart; i < iend; i++)
			norm_thread = norm_thread + fabs(x[i]);

		// update global norm with value from each thread :
		#pragma omp critical
		{
			norm = norm + norm_thread;
			printf("norm updated to: %f\n", norm);
		}

		// make sure all have updated norm before proceeding :
		#pragma omp barrier

		ynorm_thread = 0.0;
		for (i = istart; i < iend; i++)
		{
			y[i] = x[i] / norm;
			ynorm_thread = ynorm_thread + fabs(y[i]);
		}

		// update global ynorm with value from each thread :
		#pragma omp critical
		{
			ynorm = ynorm + ynorm_thread;
			printf("ynorm updated to: %f\n", ynorm);
		}	
		#pragma omp barrier

	}

	printf("norm of x = %f  n(n+1)/2 = %d\n", norm, (n - 1)*(n / 2));
	printf("ynorm should be 1.0:   ynorm = %f\n", ynorm);
	
	free(x);
	free(y);

	return 0;
}