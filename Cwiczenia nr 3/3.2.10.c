#include <stdio.h>
#include <stdlib.h>

double *lokuj_pamiec();

int main()
{

	/* ZADANIE 3.2.10
    Napisz bezargumentową funkcję, która rezerwuje pamięć dla pojedynczej zmiennej typu double
    i zwraca jako wartość wskaźnik do niej */

    printf("\n\n---------------- ZADANIE  3.2.10 ----------------\n\n");

    double *zmienna = lokuj_pamiec();

    *zmienna = 1.75;

    printf("\nadres, main: %p", zmienna);
    printf("\nWartosc: %g", *zmienna);

    free(zmienna);
    zmienna = NULL;


    printf("\n\n------------------------------------------------\n\n");

    return 0;
}

double *lokuj_pamiec()
{
    double *db = (double*)malloc(sizeof(double));

    printf("\nadres, funkcja: %p", db);

    return db;
}
