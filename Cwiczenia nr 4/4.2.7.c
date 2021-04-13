#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void wyswietl_tab(int *tab, int rozmiar);

void sumuj_tablice(int *tab1, int *tab2, int *tab3, const int rozmiar);
void przypisz_wiekszy(int *tab1, int *tab2, int *tab3, const int rozmiar);
void przepisz_trzy_tab(int *tab1, int *tab2, int *tab3, const int rozmiar);

int main()
{
    /* ZADANIE 4.2.7
    Napisz funkcje, ktora otrzymuje cztery argumenty: dodatnia liczbe
    calkowita n oraz trzy n-elementowe tablice tab1, tab2 i tab3 o elementach typu int, i:
    a) przypisuje elementom tablicy tab3 sume odpowiadajacych im elementow tablic tab1 i tab2 (do komorki tablicy tab3 o indeksie i
        powinna trafic suma elementow tab1[i] i tab2[i]),
    b) przypisuje elementom tablicy tab3 wiekszy sposrod odpowiadajacych im elementow tablic tab1 i tab2
        (do komorki tablicy tab3 o indeksie i powinien trafic wiekszy sposrod elementow tab1[i] i tab2[i]),
    c) przypisuje zawartosc tablicy tab1 do tablicy tab2, zawartosc tablicy tab2 do tablicy tab3 oraz zawartosc tablicy
        tab3 do tablicy tab1.
    */

    srand((unsigned int)time(NULL));

    const int n = 10;

     printf("\n\n---------------- ZADANIE  4.2.7 ----------------\n\n");

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

    sumuj_tablice(tab1, tab2, tab3, n);
    printf("\n\nTab3 = Tab1 + Tab2:\n");

    printf("Tab1:\t");
    wyswietl_tab(tab1, n);

    printf("\nTab2:\t");
    wyswietl_tab(tab2, n);

    printf("\nTab3:\t");
    wyswietl_tab(tab3, n);

    printf("\n\nTab3 => wiekszy element:\n");
    przypisz_wiekszy(tab1, tab2, tab3, n);

     printf("Tab1:\t");
    wyswietl_tab(tab1, n);

    printf("\nTab2:\t");
    wyswietl_tab(tab2, n);

    printf("\nTab3:\t");
    wyswietl_tab(tab3, n);

	printf("\n\nTab1 => Tab2 => Tab3 => Tab1:\n");
    przepisz_trzy_tab(tab1, tab2, tab3, n);

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


void sumuj_tablice(int *tab1, int *tab2, int *tab3, const int rozmiar)
{
    for(int i = 0; i < rozmiar; i++)
        tab3[i] = tab1[i] + tab2[i];
}

void przypisz_wiekszy(int *tab1, int *tab2, int *tab3, const int rozmiar)
{
    for(int i = 0; i < rozmiar; i++)
    {
        if(tab1[i] > tab2[i])
            tab3[i] = tab1[i];
        else
            tab3[i] = tab2[i];
    }

}

void przepisz_trzy_tab(int *tab1, int *tab2, int *tab3, const int rozmiar)
{
    int temp;

    for(int i = 0; i < rozmiar; i++)
    {
        temp = tab3[i];
        tab3[i] = tab2[i];
        tab2[i] = tab1[i];
        tab1[i] = temp;
    }

}
