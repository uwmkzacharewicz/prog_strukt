#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define N_P 12
#define DL 20

struct dane_szcz
{
    char p_imie[DL];
    char d_imie[DL];
    char nazwisko[DL];
};

struct dane_osobowe
{
    char PESEL[N_P];
    struct dane_szcz dane;
};

void wyswietl_dane_sz_tab(const struct dane_osobowe tab[], const int n);
//void wyswietl_dane_sz_tab(const struct dane_osobowe *tab, const int n);
void wyswietl_dane_sz(const struct dane_osobowe skladnik);

int main()
{
    /* ZADANIE 4
    Napisz program, ktory tworzy szablon struktury o dwoch skladnikach zgodnie z ponizszymi kryteriami:
    a)  Pierwszym skladnikiem jest numer PESEL, a drugim -- struktura o trzech
        skladnikach. Jej pierwszy skladnik zawiera imie, drugi -- drugie imie, a trzeci --
        nazwisko. Utworz i zainicjuj tablice zlozona z trzech takich struktur. Program
        powinien wyswietlic dane w nastepujacej formie:
        Jordan, Michael J. -- 65092301159
    b)  Wyswietlana jest tylko pierwsza litera drugiego imienia wraz z kropka. Jesli
        skladnik zawierajacy drugie imie jest pusty, program nie powinien wyswietlic
        ani inicjalu (co oczywiste), ani kropki.
        Algorytm wyswietlania zaimplementuj w postaci oddzielnej funkcji,
        pobierajacej tablice struktur jako argument.
    c)  Zmodyfikuj program opisany w punkcie a. tak, aby funkcja wyswietlajaca
        przyjmowala strukture, a nie adres tablicy struktur.
    */

    printf("\n\n---------------- ZADANIE   4 ----------------");

    struct dane_osobowe spis_osob[N] =
    {
        { "67092196918", {"Karol", "Marcin", "Nowak"}},
        { "87042345711", { .p_imie = "Tomasz", .nazwisko = "Kowalski"}},
        { "83092336297", {"Jan", "Janusz", "Piekarski"}}
    };

    printf("\n\n----------------------------------------------\n\n");

    wyswietl_dane_sz_tab(spis_osob, N);

    printf("\n\n----------------------------------------------\n\n");

    for(int i = 0; i < N; i++)
        wyswietl_dane_sz(spis_osob[i]);

    printf("\n\n----------------------------------------------\n\n");

    return 0;
}

void wyswietl_dane_sz_tab(const struct dane_osobowe tab[], const int n)
{
    for(int i = 0; i < n; i++)
    {
        if (tab[i].dane.d_imie[0] == '\0')
            printf("\n%s, %s -- %s", tab[i].dane.nazwisko, tab[i].dane.p_imie, tab[i].PESEL);
        else
            printf("\n%s, %s %c. -- %s", tab[i].dane.nazwisko, tab[i].dane.p_imie, tab[i].dane.d_imie[0], tab[0].PESEL);
    }
}

void wyswietl_dane_sz(const struct dane_osobowe skladnik)
{
    if (skladnik.dane.d_imie[0] == '\0')
            printf("\n%s, %s -- %s", skladnik.dane.nazwisko, skladnik.dane.p_imie, skladnik.PESEL);
        else
            printf("\n%s, %s %c. -- %s", skladnik.dane.nazwisko, skladnik.dane.p_imie, skladnik.dane.d_imie[0], skladnik.PESEL);

}
