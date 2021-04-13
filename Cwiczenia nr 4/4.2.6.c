#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void wyswietl_tab(int *tab, int rozmiar);
void przepisz_tab(int n,int t1[],int t2[]);
void przepisz_tab_odw(int n,int t1[],int t2[]);


int main()
{
    /* ZADANIE 4.2.6
    Napisz funkcje, ktora otrzymuje trzy argumenty: dodatnia liczbe cal-
    kowita n oraz dwie n-elementowe tablice tab1, tab2 o elementach
    typu int i:
    a) (r) przepisuje zawartosc tablicy tab1 do tablicy tab2,
    b) przepisuje zawartosc tablicy tab1 do tablicy tab2 w odwrotnej
    kolejnosci (czyli element tab1[0] ma zostac zapisany do komorki
    tablicy tab2 o indeksie n - 1).
    */

    srand((unsigned int)time(NULL));

    const int n = 10;

     printf("\n\n---------------- ZADANIE  4.2.6 ----------------\n\n");

    int tab1[n], tab2[n];

    for(int i = 0; i < n; i++)
        tab1[i] = 1+rand()%100;

    for(int i = 0; i < n; i++)
        tab2[i] = 1+rand()%100;

    printf("Tab1:\t");
    wyswietl_tab(tab1, n);

    printf("\nTab2:\t");
    wyswietl_tab(tab2, n);

    przepisz_tab(n, tab1, tab2);
    printf("\n\nTab1 => Tab2:\n");

    printf("Tab1:\t");
    wyswietl_tab(tab1, n);

    printf("\nTab2:\t");
    wyswietl_tab(tab2, n);

     printf("\n\nTab1 => Tab2, odwrocone:\n");
    przepisz_tab_odw(n, tab1, tab2);

    printf("Tab1:\t");
    wyswietl_tab(tab1, n);

    printf("\nTab2:\t");
    wyswietl_tab(tab2, n);

     printf("\n\n------------------------------------------------\n\n");


    return 0;
}

void wyswietl_tab(int *tab, int rozmiar)
{
     for(int i = 0; i < rozmiar; i++)
        printf("%d\t", tab[i]);
}

void przepisz_tab(int n,int t1[],int t2[])
{
     for(int i = 0; i < n; i++)
        t1[i] = t2[i];
}

void przepisz_tab_odw(int n,int t1[],int t2[])
{
    int koniec;
    int pocz;

    for(pocz = 0, koniec = n - 1; pocz < n; pocz++, koniec--)
        t2[pocz] = t1[koniec];
}
