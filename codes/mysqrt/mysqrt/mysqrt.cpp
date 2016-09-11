#include <stdio.h>

int main()
{
    double x = 2.;
    double s = 1.;

    for (int i = 0; i < 6; i++)
    {
        s = 0.5 * (s + x / s);
    }
    printf("mysqrt(%f) = (%f)\n", x, s);

    return 0;
}