#include <stdio.h>

int main()
{
    double x = 2.;
    double s = 1.;

    int i = 0;
    for (i = 0; i < 6; i++)
    {
        printf("Before iteration %d, s = %f\n", i, s);
        s = 0.5 * (s + x / s);
    }
    printf("After %d iterations, s = %f\n", i, s);

    printf("\nmysqrt(%f) = (%f)\n", x, s);

    return 0;
}