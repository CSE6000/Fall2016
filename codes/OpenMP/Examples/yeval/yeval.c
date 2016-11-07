#include <omp.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 100000000;
    int i, nthreads;
    double *y;
    double dx, x;

    y = (double*)malloc(n * sizeof(double));

    //Specify number of threads to use:
    nthreads = 2;
    omp_set_num_threads(nthreads);
    printf("Using OpenMP with %d threads\n", nthreads);

    dx = 1.0 / (n+1.0);

    #pragma omp parallel for private(x)
    for(i = 1; i <= n; i++)
    {
      x = i*dx;
      y[i-1] = exp(x)*cos(x)*sin(x)*sqrt(5*x+6.0);
    }

    printf("Filled vector y of length %d\n", n);

    free(y);

    return 0;
}