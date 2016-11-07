#include <omp.h>
#include <stdio.h>

int main()
{
    int n = 20;
    int i, nthreads;

    //Specify number of threads to use:
    nthreads = 2;
    omp_set_num_threads(nthreads);
    printf("Using OpenMP with %d threads\n", nthreads);

    #pragma omp parallel for if (n > 10)
    for(i = 1; i <= n; i++)
    {
      #pragma omp critical
        {
            int thread_num = omp_get_thread_num();
            printf("This thread =");
            printf("%d\n", thread_num);
        } //end of omp critical
    }

    return 0;
}