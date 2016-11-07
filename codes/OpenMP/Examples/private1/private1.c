#include <omp.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i, nthreads;
    double *x;
    double y;
    double dx;

    x = (double*)malloc(100 * sizeof(double));

    //Specify number of threads to use:
    nthreads = 2;
    omp_set_num_threads(nthreads);
    printf("Using OpenMP with %d threads\n", nthreads);

    n = 7;
    y = 2.0;
    #pragma omp parallel for firstprivate(y) lastprivate(y)
    for(i = 1; i <= n; i++)
    {
        y = y + 10.0;
        x[i - 1] = y;
        #pragma omp critical
        {
            printf("i = %d, x[i - 1] = %f\n", i, x[i - 1]);
        }
    }
    printf("At end y = %f\n", y);

    free(x);

    return 0;
}