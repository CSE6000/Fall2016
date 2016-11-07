#include <omp.h>
#include <stdio.h>

int main()
{
    int thread_num;

    omp_set_num_threads(2);
    printf("Testing openmp ...\n");
    #pragma omp parallel private(thread_num)
    {
        #pragma omp critical
        {
            thread_num = omp_get_thread_num();
            printf("This thread =");
            printf("%d\n", thread_num);
        } //end of omp critical
    } //end of omp paralle
    return 0;
}