#include <stdio.h>
#include <math.h>

double mysqrt(double x, bool debug = false)
{

    double s = 1.;

    int maxiter = 100;
    double tol = 1.e-14;
    int i = 0;
    for (i = 0; i < maxiter; i++)
    {
        if (debug)
            printf("Before iteration %d, s = %20.15f\n", i, s);
        double s0 = s;
        s = 0.5 * (s + x / s);

        double delta_s = s - s0;
        if (fabs(delta_s / x) < tol)
            break;
    }
    if (debug)
        printf("After %d iterations, s = %20.15f\n", i, s);

    return s;
}

int main()
{
    double x = 2.;
    double s = mysqrt(x, true);
    printf("\nmysqrt(%f) = (%f)\n", x, s);

    return 0;
}