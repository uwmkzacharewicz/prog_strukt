#include <stdio.h>
#include <stdlib.h>

void wyswietl_tab(int *tab, int rozmiar);
void wyswietl_tab_nr(int *tab, int rozmiar);

void polacz_tab(const int *tab1,const int *tab2, int *tab_doc, const int n);
void polacz_p_np(const int *tab1,const int *tab2, int *tab_doc, const int n);

int main()
{
    /* ZADANIE 4.2.8
    Napisz funkcje, ktora otrzymuje cztery argumenty: dodatnia liczbe
    calkowita n, n-elementowe tablice tab1 i tab2 oraz 2 . n-elementowa
    tablice tab3 o elementach typu double.
    a) Funkcja powinna przepisywac zawartosc tablic tab1 i tab2 do tablicy tab3 w taki sposob, ze na poczatku tablicy tab3 powinny sie
    znalezc elementy tablicy tab1, a po nich elementy tablicy tab2.
    b) Funkcja powinna przepisywac zawartosc tablic tab1 i tab2 do tablicy tab3 w taki sposob, ze w komorkach
    tablicy tab3 o nieparzystych indeksach powinny sie znalezc elementy tablicy tab1,
    a w komorkach tablicy tab3 o parzystych indeksach elementy tablicy tab2.
    */

    const int n = 10;

     printf("\n\n---------------- ZADANIE  4.2.8 ----------------\n\n");

    int tab1[n], tab2[n], tab3[2*n];

    for(int i = 0; i < n; i++)
        tab1[i] = i;

    for(int i = 0; i < n; i++)
        tab2[i] = i+10;

    for(int i = 0; i < 2*n; i++)
        tab3[i] = 0;

    printf("Tab1:\t");
    wyswietl_tab(tab1, n);

    printf("\nTab2:\t");
    wyswietl_tab(tab2, n);

    printf("\nTab3:\t");
    wyswietl_tab(tab3, 2*n);

    printf("\n\nTab3 => Tab1 + Tab2:\n");
    polacz_tab(tab1, tab2, tab3, n);
    wyswietl_tab(tab3, 2*n);

    printf("\n\nTab3 => (niep) Tab1 + (parz) Tab2:\n");
    polacz_p_np(tab1, tab2, tab3, n);
    wyswietl_tab_nr(tab3, 2*n);

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

void polacz_tab(const int *tab1,const int *tab2, int *tab_doc, const int n)
{
    int i_tab_doc = 0;

    for(int i = 0; i < n; i++, i_tab_doc++)
        tab_doc[i_tab_doc] = tab1[i];

    for(int i = 0; i < n; i++, i_tab_doc++)
        tab_doc[i_tab_doc] = tab2[i];
}

void polacz_p_np(const int *tab1, const int *tab2, int *tab_doc, const int n)
{
    int i_tab_doc = 0;
    int rozmiar = 2*n;

    for(int i = 0; i < rozmiar; i++)
    {
        if(i%2 == 0)
            tab_doc[i] = *tab2++;
        else
            tab_doc[i] = *tab1++;
    }
}
