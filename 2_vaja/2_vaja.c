#include <stdio.h>
#include <math.h>

double kvadratni_koren(int stevilo)
{
    double i = 0;
    while (i < stevilo)
    {
        if (i * i == stevilo)
        {
            return i;
        }
        if (i * i - stevilo > 0)
        {
            break;
        }
        i++;
    }
    double x_0 = (i + i - 1) / 2.0;
    //x_0 = 1;
    // printf("%lf", x_0);
    double x_1 = x_0 - (x_0 * x_0 - stevilo) / (2.0 * x_0);
    while (fabs(x_1 - x_0) > 0.00001)
    {
        x_0 = x_1;
        x_1 = x_0 - ((x_0 * x_0 - stevilo) / (2.0 * x_0));
    }
    return x_1;
}
int main()
{
    printf("%lf", kvadratni_koren(3));
    return 0;
}