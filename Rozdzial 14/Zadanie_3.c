#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXTYT   40
#define MAXAUT   40
#define MAXKS   100

struct ksiazka {                 /* definiuje szablon ksiazka     */
    char tytul[MAXTYT];
    char autor[MAXAUT];
    float wartosc;
};

char *wczytaj(char * z, int ile);
void sortowanie(struct ksiazka tab[], const int n);

void wyswietl_struct(const struct ksiazka *tab, const int n);
void wyswietl_struct_s(const struct ksiazka tab[], const int n);


int main()
{
    /* ZADANIE 3
    Zmodyfikuj program z listingu 14.2 tak, aby wyswietlal opisy ksiazek w porzadku
    alfabetycznym (wg tytulu) oraz calkowita wartosc ksiazek
    */

    printf("\n\n---------------- ZADANIE   3 ----------------\n\n");

    struct ksiazka spis[10] =
    {
    {"Mitologia", "Jan Parandowski", 25.0},
    {"Kronika polska", "Gall Anonim", 45.5},
    {"Zbrodnia i kara", "Fiodor Dostojewski", 21.2},
    {"Boska komedia", "Dante Alighieri", 14.9},
    {"Zdazyc przed Panem Bogiem", "Hanna Krall", 39.9},
    {"Kazania sejmowe", "Piotr Skarga", 25.0},
    {"Wesele", "Stanislaw Wyspianski", 21.5},
    {"Oda do mlodosci", "Adam Mickiewicz", 21.9},
    {"Konrad Wallenrod", "Adam Mickiewicz", 20.0},
    {"Potop", "Henryk Sienkiewicz", 19.9}
    };

    //struct ksiazka *wsk;
    //wsk = spis;

    float suma = 0;

    printf("Spis ksiazek:\n\n");
          for (int i = 0; i < 10; i++)
          {
              printf("%d) %s, autor: %s, cena: %.2f zl\n", i+1, spis[i].tytul,
                    spis[i].autor, spis[i].wartosc);
              suma += spis[i].wartosc;
          }

    printf("\n\nPOSORTOWANE:\n\n");

    sortowanie(spis, 10);

    wyswietl_struct_s(spis,10);
    printf("\n-----------------------");
    printf("\nWartosc: %.2f zl\n\n", suma);

    printf("\n\n----------------------------------------------\n\n");


    return 0;
}


void sortowanie(struct ksiazka tab[], const int n)
{
    struct ksiazka temp;

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if( strcmp(tab[i].tytul, tab[j].tytul ) > 0)
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

void wyswietl_struct(const struct ksiazka *tab, const int n)
{
    struct ksiazka *ptr;
    ptr = tab;

    int *const arrayEnd = tab + n;


    for(ptr; ptr < arrayEnd ; ptr++ )
        printf("\n%s", ptr->autor);

}

void wyswietl_struct_s(const struct ksiazka tab[], const int n)
{
    for (int i = 0; i < 10; i++)
               printf("%d) %s, autor: %s, cena: %.2f zl\n", i+1, tab[i].tytul,
                    tab[i].autor, tab[i].wartosc);

}

char * wczytaj(char *z, int ile)
{
    char * wynik;
    char * tutaj;
    wynik = fgets(z, ile, stdin);
    if (wynik)
    {
        tutaj = strchr(z, '\n'); // szukamy nowego wiersza
        if (tutaj) // jesli adres jest rozny od NULL
            *tutaj = '\0'; // zamieniamy znak nowego wiersza na pusty
        else
            while (getchar() != '\n')
                continue;
    }
    return wynik;
}


