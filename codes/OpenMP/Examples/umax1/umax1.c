#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100
int main()
{
	double dt, umax, umax_thread;
	int n, nthreads, points_per_thread, thread_num;
	int m, i, istart, iend, nsteps;
	int debug;

	double u[N];
	double c[N];

	debug = 0;

	// Specify number of threads to use :
	nthreads = 1; //need this value in serial mode
	nthreads = 4;
	omp_set_num_threads(nthreads);
	printf("('Using OpenMP with %d threads')\n", nthreads);

	n = N; //number of ODEs

	// Determine how many points to handle with each thread.
	// Note that dividing two integers and assigning to an integer will
	// round down if the result is not an integer.  
	// This, together with the min(...) in the definition of iend below,
	// insures that all points will get distributed to some thread.
	points_per_thread = (n + nthreads - 1) / nthreads;
	printf("points_per_thread = %d\n", points_per_thread);
	
	for (i = 0; i < N; i++)
	{
		u[i] = 1.0;
	}
	
	for (i = 0; i < n; i++)
	{
		c[i] = (double)(i - n / 2);// some positive, some negative
	}

	dt = 0.01;
	nsteps = 1000;
	umax = 1.0;

	#pragma omp parallel private(i, m, umax_thread, istart, iend, thread_num)
	{
		thread_num = 0; // needed in serial mode
		thread_num = omp_get_thread_num(); // unique for each thread

		// Determine start and end index for the set of points to be handled by this thread:
		istart = thread_num * points_per_thread + 1;
		iend = min((thread_num + 1) * points_per_thread, n);

		#pragma omp critical
			printf("Thread %d, will take i = %d through i = %d\n", thread_num, istart, iend);

		for (m = 0; m < nsteps; m++)
		{
			if (debug)
				printf("+++ begin loop      thread %d m = %d  umax = %f\n", thread_num, m, umax);
			umax_thread = 0.0;

			#pragma omp single
				umax = 0.0;

			for (i = istart; i < iend; i++)
			{
				u[i] = (1.0 + c[i] * dt) * u[i];
				umax_thread = max(umax_thread, u[i]);
			}

			// update global umax with value from each thread :
			#pragma omp critical
				umax = max(umax, umax_thread);

			// make sure all have updated umax before proceeding :
			#pragma omp barrier
			// Try removing the barrier above, in which case the code
			// will sometimes hang-- - quit out with ctrl - c

			if (umax > 100)
			{
				if (debug)
					printf("+++ umax>100: exit  thread %d m = %d  umax = %f  umax_thread = %f\n", thread_num, m, umax, umax_thread);
				break;
			}

			if (debug)
				printf("+++ umax<100        thread %d m = %d  umax = %f  umax_thread = %f\n", thread_num, m, umax, umax_thread);

			// make sure all threads are done testing umax before going
			// on to next iteration(where umax is re - initialized to 0).
			#pragma omp barrier
		}
	}

	printf("Done!  umax = %f\n", umax);

	return 0;
}