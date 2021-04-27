#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

void kopiuj(char *napis, char *tab_ch);

int main()
{
	/*   ZADANIE  5.2.24
	Napisz funkcje kopiuj, ktora dostaje jako argumenty napis oraz
	tablice znakow i przepisuje napis do otrzymanej w argumencie tablicy znakow.
	*/

    char nowa_tab[N];

    kopiuj("Wyraz", nowa_tab);

    printf("\n\n%s\n", nowa_tab);

    return 0;
}

void kopiuj(char *napis, char *tab_ch)
{
    int idx = 0;

    if(strlen(napis) > N-1)     // N - define N 10, okresla rozmiar tablicy znakow
    {
        printf("Za maly rozmiar tablicy, zwieksz rozmiar i sprobuj ponownie");
        return 0;
    }

    while (*napis != '\0')
    {
        printf("%c", *napis);
        tab_ch[idx] = *napis;

        napis++;
        idx++;
    }

    // na koncu lancucha umieszczamy \0
    tab_ch[idx] = '\0';

}
