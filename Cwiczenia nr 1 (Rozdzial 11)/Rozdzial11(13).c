#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
     /* CWICZENIE 13
    Napisz program do potęgowania, działający w oparciu o wiersz poleceń. Pierwszym
    argumentem powinna być liczba typu double (podstawa potęgi), a drugim —
    liczba całkowita (wykładnik)
    */

    printf("\n\n---------------- CWICZENIE   13 ----------------\n\n");

    float a = 0;
    int b = 0;

    if (argc < 3 || ((a = atof(argv[1])) && (b = atoi(argv[2]))) < 1 )
            printf("Podaj podstawe i wykladnik\n", argv[0]);

    double wynik = 1.0;

    for(int i = 1; i <= b; i++)
    {
        wynik *= a;
        printf("\n%g^%d = %g\n",a,i, wynik);
    }

    printf("\n");

    printf("\n-----------------------------------------------------");


    return 0;
}