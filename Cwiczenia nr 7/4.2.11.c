#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wyswietl_tab(const double *tab, const int n);
double iloczyn_skalarny(const double *tab1, const double *tab2, const int n);

int main()
{
    /* ZADANIE 4.2.11
    Napisz funkcję, która otrzymuje dwa argumenty: dodatnią liczbę całkowitą n
    oraz dwie n-elementowe tablice tab o elementach typu double
    przechowujące n-wymiarowe wektory i zwraca jako wartość iloczyn
    skalarny wektorów otrzymanych w argumentach.  */

    srand((unsigned)time(NULL));

    const int n = 3;

    double vec1[n], vec2[n];

    for(int i = 0; i < n; i++)
        vec1[i] = (rand()%100)/10.0;

    for(int i = 0; i < n; i++)
        vec2[i] = (rand()%100)/10.0;

    printf("wektor 1: ");
    wyswietl_tab(vec1, n);
    printf("\nwektor 2: ");
    wyswietl_tab(vec2, n);

    printf("\n\nILOCZYN SKALARNY: %g", iloczyn_skalarny(vec1, vec2, n));

    return 0;
}

void wyswietl_tab(const double *tab, const int n)
{
     for(int i = 0; i < n; i++)
        printf("%g\t", tab[i]);
}


double iloczyn_skalarny(const double *tab1, const double *tab2, const int n)
{
    double wynik = 0;

    for(int i = 0; i < n; i++)
        wynik += tab1[i] * tab2[i];

    return wynik;
}
