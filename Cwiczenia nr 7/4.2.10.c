#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wyswietl_tab(const int *tab, const int n);
void wyswietl_idx_tab(const int *tab, const int n);

typedef int(*tablica)(int*, int);

int zbadaj(tablica znajdz, int *tab1, int n)
{
    return znajdz(tab1, n);
}

int znajdz_max(const int *tab, const int n);
int znajdz_min(const int *tab, const int n);
int znajdz_idx_max(const int *tab, const int n);
int znajdz_idx_min(const int *tab, const int n);
int znajdz_wbzwg_max(const int *tab, const int n);
int znajdz_wbzwg_idx_max(const int *tab, const int n);


int main()
{
    /* ZADANIE 4.2.10 
    Napisz funkcje, ktora otrzymuje dwa argumenty: dodatnia liczbe calkowita n 
    oraz n-elementowa tablice tab o elementach typu int i:
        a) (r,!) zwraca najwieksza wartosc przechowywana w tablicy tab,
        b) zwraca najmniejsza wartosc przechowywana w tablicy tab,
        c) (r,!) zwraca indeks elementu tablicy tab o najwiekszej wartosci,
        d) zwraca indeks elementu tablicy tab o najmniejszej wartosci,
        e) zwraca najwieksza sposrod wartosci bezwzglednych elementow przechowywanych w tablicy tab,
        f) zwraca indeks elementu tablicy tab o najwiekszej wartosci bezwzglednej.   */
    
    
    srand((unsigned int)time(NULL));

    const int n = 10;

    int tab1[n];

    for(int i = 0; i < n; i++)
        tab1[i] = -50+rand()%100;

    printf("TABLICA: ");
    wyswietl_idx_tab(tab1, n);

    printf("\nMAX: [%d] %d", zbadaj(znajdz_idx_max, tab1, n), zbadaj(znajdz_max, tab1, n));
    printf("\nMIN: [%d] %d", zbadaj(znajdz_idx_min, tab1, n), zbadaj(znajdz_min, tab1, n));
    printf("\n|MAX|: [%d] %d", zbadaj(znajdz_wbzwg_idx_max, tab1, n), zbadaj(znajdz_wbzwg_max, tab1, n));

    return 0;
}

void wyswietl_tab(const int *tab, const int n)
{
     for(int i = 0; i < n; i++)
        printf("%d\t", tab[i]);
}

void wyswietl_idx_tab(const int *tab, const int n)
{
    for(int i = 0; i < n; i++)
        printf("[%d]%d\t", i, tab[i]);
}

int znajdz_max(const int *tab, const int n)
{
    int w_max = tab[0];

    for(int i = 1; i < n; i++)
        if(tab[i] > w_max)
            w_max = tab[i];

    return w_max;
}

int znajdz_min(const int *tab, const int n)
{
    int w_min = tab[0];

    for(int i = 1; i < n; i++)
        if(tab[i] < w_min)
            w_min = tab[i];

    return w_min;
}

int znajdz_idx_max(const int *tab, const int n)
{
    int i_max = 0;

    for(int i = 1; i < n; i++)
        if(tab[i] > tab[i_max])
            i_max = i;

    return i_max;
}

int znajdz_idx_min(const int *tab, const int n)
{
    int i_min = 0;

    for(int i = 1; i < n; i++)
        if(tab[i] < tab[i_min])
            i_min = i;

    return i_min;
}

int znajdz_wbzwg_max(const int *tab, const int n)
{
    int w_max = abs(tab[0]);

    for(int i = 1; i < n; i++)
        if(abs(tab[i]) > w_max)
            w_max = abs(tab[i]);

    return w_max;
}

int znajdz_wbzwg_idx_max(const int *tab, const int n)
{
    int i_max = 0;

    for(int i = 1; i < n; i++)
        if(abs(tab[i]) > abs(tab[i_max]))
            i_max = i;

    return i_max;
}


