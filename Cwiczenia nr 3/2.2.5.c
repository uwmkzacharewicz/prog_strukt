#include <stdio.h>
#include <stdlib.h>

double dwa_do_n(int n);

int main()
{

	/* ZADANIE 2.2.5
    Napisz funkcje, ktora dostaje jako argument liczbe calkowita n i zwraca jako wartosc liczbe 2^n  */

    printf("\n\n---------------- ZADANIE  2.2.5 ----------------\n\n");

    printf("%g\n", dwa_do_n(10));
    
    printf("\n\n------------------------------------------------\n\n");

    return 0;
}

double dwa_do_n(int n)
{
    double wynik = 1;

    for(int i = 1; i <= abs(n); i++)
        wynik *= 2;

    if (n > 0)
        return wynik;
    else if (n == 0)
        return 1;
    else
        return (1/wynik);

}
