#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n = 10;
    int i, j, nthreads;
    double *x;
    double norm;
    double mysum;

    x = (double*)malloc(n * sizeof(double));

    for (i = 0; i < n; ++i)
    {
    	x[i] = i;
    }

    //Incorrect code
    norm = 0.0;
    #pragma omp parallel for
    for (i = 0; i < n; i++)
    {
        norm = norm + fabs(x[i]);
    }
    printf("norm : %f\n", norm);

    //correct code
    norm = 0.0;
    #pragma omp parallel for reduction(+ : norm)
    for (i = 0; i < n; i++)
    {
        norm = norm + fabs(x[i]);
    }
    printf("norm : %f\n", norm);

    //A more complicated way to do this:
    norm = 0.0;
    #pragma omp parallel private(mysum) shared(norm)
    {
        mysum = 0;
        #pragma omp for
        for(i = 0; i < n; i++)
        {
            mysum = mysum + fabs(x[i]);
        }
        #pragma omp critical
        {
            norm = norm + mysum;
        }
    }
    printf("norm : %f\n", norm);

	double y = -1.0e3; //very negative value
	#pragma omp parallel for reduction(max: y)
	for(i = 1; i < n; i++)
	{
	  y = fmax(y, x[i]);
	}
	printf("max of x = %f\n", y);



    bool anyzero = .false.
   !$omp parallel do reduction(.or.: anyzero)
   do i=1,n
      anyzero = anyzero .or. (x(i) == 0.d0)
      enddo
   print *, ’anyzero = ’,anyzero

	free(x);

	return 0;
}
