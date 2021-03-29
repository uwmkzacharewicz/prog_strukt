#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void wyswietl_tab(int *tab, int rozmiar);
void wyswietl_tab_nr(int *tab, int rozmiar);

void przepisz_rosnaco(int *tab1, int *tab2, int *tab3, const int n);
void sortuj_rosnaco(int *w1, int *w2, int *w3);

int main()
{
    /* ZADANIE 4.2.9
    Napisz funkcje, ktora otrzymuje cztery argumenty: dodatnia liczbe
    calkowita n oraz trzy n-elementowe tablice tab1, tab2 i tab3 o elementach typu int
    i zamienia zawartosci komorek otrzymanych w argumentach tablic w nastepujacy sposob:
    -- dla dowolnego i komorka tab1[i] powinna zawierac najwieksza
    sposrod pierwotnych wartosci komorek tab1[i], tab2[i]
    oraz tab3[i],
    -- dla dowolnego i komorka tab2[i] powinna zawierac druga
    co do wielkosci sposrod pierwotnych wartosci komorek tab1[i],
    tab2[i] oraz tab3[i],
    -- dla dowolnego i komorka tab3[i] powinna zawierac najmniejsza sposrod pierwotnych wartosci komorek tab1[i], tab2[i]
    oraz tab3[i].
    */

    srand((unsigned int)time(NULL));

    const int n = 10;

     printf("\n\n---------------- ZADANIE  4.2.9 ----------------\n\n");

    int tab1[n], tab2[n], tab3[n];

    for(int i = 0; i < n; i++)
        tab1[i] = 1+rand()%100;

    for(int i = 0; i < n; i++)
        tab2[i] = 1+rand()%100;

    for(int i = 0; i < n; i++)
        tab3[i] = 1+rand()%100;

    printf("Tab1:\t");
    wyswietl_tab(tab1, n);

    printf("\nTab2:\t");
    wyswietl_tab(tab2, n);

    printf("\nTab3:\t");
    wyswietl_tab(tab3, n);

    przepisz_rosnaco(tab1, tab2, tab3, n);

    printf("\n\nPO ZMIANIE:\n");

    printf("Tab1:\t");
    wyswietl_tab(tab1, n);

    printf("\nTab2:\t");
    wyswietl_tab(tab2, n);

    printf("\nTab3:\t");
    wyswietl_tab(tab3, n);

    printf("\n\n------------------------------------------------\n\n");

    return 0;
}

void wyswietl_tab(int *tab, int rozmiar)
{
     for(int i = 0; i < rozmiar; i++)
        printf("%d\t", tab[i]);
}

void wyswietl_tab_nr(int *tab, int rozmiar)
{
    for(int i = 0; i < rozmiar; i++)
        printf("[%d] %d\t", i, tab[i]);
}


void przepisz_rosnaco(int *tab1, int *tab2, int *tab3, const int n)
{
    int i_min, i_mid, i_max;
    int *w_min, *w_mid, *w_max;

    w_min = &i_min;
    w_mid = &i_mid;
    w_max = &i_max;

    for(int i = 0; i < n; i++)
    {
        i_min = tab1[i];
        i_mid = tab2[i];
        i_max = tab3[i];

        sortuj_rosnaco(w_min, w_mid, w_max);

        tab1[i] = i_max;
        tab2[i] = i_mid;
        tab3[i] = i_min;
    }
}

void sortuj_rosnaco(int *w1, int *w2, int *w3)
{
    int temp;

    if(*w1 > *w2)
    {
        temp = *w1;
        *w1 = *w2;
        *w2 = temp;
    }

    if(*w2 > *w3)
    {
        temp = *w2;
        *w2 = *w3;
        *w3 = temp;
    }

   if(*w1 > *w2)
    {
        temp = *w1;
        *w1 = *w2;
        *w2 = temp;
    }
}