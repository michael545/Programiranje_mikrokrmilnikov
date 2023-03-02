#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int stdni, prvi_dan;

    printf("Vnesite stevilo dni v mesecu in pritisni enter \n");
    scanf("%i", &stdni);

    while (stdni < 28 || stdni > 31)
    {
        printf("Vnos je napacen poskusite znova\n");
        scanf("%i", &stdni);

        // printf("%i", stdni);
    }
    printf("Vnesite s katerim dnem se zacne mesec(1-pon, 2-tor, ... 7-ned) in pritisni enter: \n");
    scanf("%i", &prvi_dan);

    printf("P  T  S  C  P  S  N \n");

    int mesec[38];
    prvi_dan--;
    int x = 1;
    for (int i = 0; i <= (stdni + prvi_dan); i++)
    {
        if (i < prvi_dan)
        {
            mesec[i] = -1;
            printf("   ");
        }
        else
        {
            if (x <= stdni)
            {
                mesec[i] = x;
                printf("%i", mesec[i]);
                printf(" ");
                if (x < 10)
                {
                    printf(" ");
                }
            }
            x++;
        }
        if ((i + 1) % 7 == 0 && i != 0)
        {
            printf("\n");
        }
    }
    return 0;
}
//nova vrstica za limitne primere !!