#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

    /* 1.4.5
    Napisz program, który wczytuje ze standardowego wejścia nieujemną
    liczbę całkowitą n i wypisuje na standardowym wyjściu sumę kwadratów liczb od 0 do n, czyli wartość 0^2 + 1^2 + 3^2 + ... + n^2
    */

    int n;
    int stan = 0;
    float suma = 0;

    printf("Podaj liczbe n: ");

    stan =  scanf("%d", &n);

    while (stan != 1 || n <= 0)       // czy wprowadzono poprawna liczbe i jest wieksza od zera
    {
        printf("Bledne wartosci, n musi byc liczba i wieksza od zera, sprobuj jeszcze raz: ");
        while (getchar() != '\n')
            continue;
        stan =  scanf("%d", &n);
    }

    printf("n = %d\n\n", n);
    printf("%5s %7s\n", "n", "n^2");

    for(int i = 0; i <= n; i++)
    {

        suma += (i*i);
        printf("%5d", i);
        printf("\t");
        printf("%5d", (i*i));
        printf("\n");
    }

    printf("\n  SUMA: %5g\n\n", suma);

    return 0;
}
