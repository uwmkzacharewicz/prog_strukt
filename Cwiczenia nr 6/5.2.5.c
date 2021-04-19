#include <stdio.h>
#include <stdlib.h>

int str_len(const char *napis);
void przepisz(char *docelowy, char *zrodlo);

int main()
{
	/*   ZADANIE  5.2.5
	Napisz funkcje przepisz, ktora otrzymuje dwie tablice znakow i przepisuje
	napis znajdujacy sie w pierwszej tablicy do drugiej tablicy.
	Zakladamy, ze w drugiej tablicy jest wystarczajaco duzo miejsca.
	*/

    char nap1[] = "Napis";
    char *w_nap1 = "Napis G";

    char napis_z[20];

    przepisz(napis_z, w_nap1);
    printf("%s", napis_z);
    przepisz(napis_z, nap1);
    printf("\n%s", napis_z);

    return 0;
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
