#include <stdio.h>
#include <math.h>
#include <complex.h>

float vrednost_konvergence(float a, float b)
{
    float complex x1 = a + b * I;
    printf("%f | %f\n", creal(x1), cimag(x1));
    float konv = creal(x1) * cimag(x1);
    return konv;
}

int main()
{
    // int bitna_slika[1000][1000];

    for (int i = -500; i < 500; i++)
    {
        for (int j = -500; j < 500; j++)
        {
            // resi enacbo in zapisi v tabelo 1000x1000
            float konver_proti = vrednost_konvergence((float)i, (float)j);
            printf("%f", konver_proti);
            // if (j > 0 && i > 0)
            // bitna_slika[i][j] = konver_proti;
        }
    }
    // int x = vrednost_konvergence(-1.0, 1.0);
    //  printf("%i", x);
    return 0;
}