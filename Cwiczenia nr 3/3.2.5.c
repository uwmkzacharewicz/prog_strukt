#include <stdio.h>
#include <stdlib.h>

int suma(const int *a, const int *b);

int main()
{

	/* ZADANIE 3.2.5
    Napisz funkcje, ktorej argumentami sa dwa wskazniki
    do stalych typu int, zas zwracana wartoscia jest
    suma wartosci zmiennych wskazywanych przez argumenty*/

    printf("\n\n---------------- ZADANIE  3.2.5 ----------------\n\n");

    const int n = 100, m = 200;
    const int *wsk_n, *wsk_m;

    wsk_n = &n;
    wsk_m = &m;

    printf("\n%d + %d = %d", n, m, suma(wsk_n, wsk_m));


    printf("\n\n------------------------------------------------\n\n");

    return 0;
}

int suma(const int *a, const int *b)
{
    return (*a + *b);
}
