#include <stdio.h>
#include <stdlib.h>

int przepisz(int n, int *w);

int main()
{

	/* ZADANIE 3.2.6
    Napisz funkcje, ktorej argumentami sa n typu int oraz w wskaznik
    do int, ktora przepisuje wartosc n do zmiennej wskazywanej przez w. */

    printf("\n\n---------------- ZADANIE  3.2.6 ----------------\n\n");

    int a = 999;
    int b = 111;

    int *wsk = &b;

    printf("\na = %d, b = %d", a, b);
    przepisz(a, wsk);
    printf("\nPo zamianie:\na = %d, b = %d", a, b);


    printf("\n\n------------------------------------------------\n\n");

    return 0;
}

int przepisz(int n, int *w)
{
    *w = n;
}
