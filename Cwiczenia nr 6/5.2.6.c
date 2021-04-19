#include <stdio.h>
#include <stdlib.h>

int str_len(const char *napis);
void przepisz(char *docelowy, char *zrodlo);
void kopiuj_n(char *docelowy,const char *zrodlo, const int ilosc_zn);

int main()
{
	/*   ZADANIE  5.2.6
	Napisz funkcje kopiujn, ktora dostaje w argumentach dwie tablice znakow nap1, nap2 oraz liczbe n
	i przekopiowuje n pierwszych znakow z napisu przechowywanego w tablicy nap1 do tablicy nap2.
	W przypadku gdy napis w tablicy nap1 jest krotszy niz n znakow, funkcja powinna po prostu przepisac caly napis.
	Funkcja powinna zadbac o to, zeby na koncu napisu w tablicy nap2 znalazl sie znak o kodzie 0.
	*/

    char nap1[] = "Napis";
    char *w_nap1 = "Napis G";

    char napis_z[20];

    kopiuj_n(napis_z, w_nap1, 20);
    printf("%s", napis_z);

    kopiuj_n(napis_z, nap1, 2);
    printf("\n%s", napis_z);

    return 0;
}

void kopiuj_n(char *docelowy, const char *zrodlo, const int ilosc_zn)
{
    for(int i = 0; i < ilosc_zn; i++, ++docelowy, ++zrodlo)
    {
        if(*zrodlo == '\0')     // jezeli skonczyl sie napis przerwij
            break;

        *docelowy = *zrodlo;
    }

    *docelowy = '\0';           // dodanie na koniec '\0'
}

void przepisz(char *docelowy, char *zrodlo)
{
    while (*zrodlo != '\0')
    {
        *docelowy = *zrodlo;

        docelowy++;
        zrodlo++;
    }

    // na koncu lancucha umieszczamy \0
	 *docelowy = '\0';    
}


int str_len(const char *napis)
{
    int dl = 0;

    while(*(napis++))
        dl++;

    return dl;
}
