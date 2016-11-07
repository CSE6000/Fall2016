#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m = 10;
    int n = 10;
    int i, j, nthreads;
    double *a;

    a = (double*)malloc(m * n * sizeof(double));

    #pragma omp parallel for private(i)
    for(j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
        {
            a[j * n + i] = 0.0;
        }
    }

   // Incorrect code for replicating first column:
   #pragma omp parallel for private(j)
   for(i = 1; i < n; i++)
   {
      for(j = 0; j < m; j++)
      {
         a[j * n + i] = a[j * n + i - 1];
      }
   }

    //Corrected: (j’s can be done in any order, i’s cannot)
   #pragma omp parallel for private(i)
   for(j = 0; j < m; j++)
   {
      for (i = 1; i < n; i++)
      {
         a[j * n + i] = a[j * n + i - 1];
      }
   }

    free(a);
    return 0;
}