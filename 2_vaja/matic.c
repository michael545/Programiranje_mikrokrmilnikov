#include <stdio.h>
#include <math.h>

double square_root(double d);

int main()
{
    double d;
    printf("Vnesi stevilko, ki je po moznosti nenegativna, ker drugace bom jezen :): ");
    scanf("%lf", &d);
    double root = square_root(d);
    printf("Evo kle mas aproksimacijo korena: %lf %lf\n", d, root);
    return 0;
}

double square_root(double d)
{
    if (d < 0)
    {
        printf("Alo šalabajzer dau si mi negativno število! Reku sm ti da ne deli tega!\n");
        return 0;
    }
    double x = 1;
    double y = (x + d / x) / 2;
    while (fabs(y - x) > 0.000001)
    {
        x = y;
        y = (x + d / x) / 2;
    }
    return y;
}   