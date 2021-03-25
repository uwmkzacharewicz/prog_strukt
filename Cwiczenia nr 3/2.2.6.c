#include <stdio.h>
#include <stdlib.h>

int n_do_m(int n, int m);

int main()
{

	/* ZADANIE 2.2.6
    Napisz funkcje, ktora dostaje jako argumenty nieujemne liczby calkowite n i m,
    z ktorych conajmniej jedna jest rozna od zera i zwraca
    jako wartosc n^m  */

    printf("\n\n---------------- ZADANIE  2.2.6 ----------------\n\n");

    int n = 5;
    int m = 5;

    printf("%d\n", n_do_m(5, 0));

    printf("\n\n------------------------------------------------\n\n");

    return 0;
}



int n_do_m(int n, int m)
{
    double pot = 1;

    if (n == 0 && m == 0)
    {
        printf("Przynajmniej jedna liczba musi byc rozna od zera\n");
        return 0;
    }

    for(int i = 1; i <= m; i++)
        pot *= n;

    return pot;

}