#include <stdio.h>
#include <stdlib.h>

double *lokuj_n_pamiec(int n);

int main()
{
    /*  3.2.12
    Napisz funkcję, która dostaje jako argument dodatnią liczbę całkowitą n,
    rezerwuje w pamięci blok n zmiennych typu double
    i zwraca jako wartość wskaźnik do początku zarezerwowanego bloku pamięci.
    */

    printf("\n\n-----------------  3.2.12  ---------------------\n\n");

    const int n = 5;

    double *vec = lokuj_n_pamiec(n);

    for(int i=0; i<n; i++)
        vec[i] = i+1;               // notacja tablicowa

    for(int i=0; i<5; i++)
        printf("%g\t", *(vec+i));   // notacja wskaźnikowa

    free(vec);
    vec = NULL;

    printf("\n\n------------------------------------------------\n\n");

    return 0;
}

double *lokuj_n_pamiec(int n)
{
    double *db = (double*)malloc(n * sizeof(double));

    return db;
}