#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>


/* 7.2.16.
    Zdefiniuj typ wyliczeniowy, sluzacy do przechowywania informacji o stanie polaczenia internetowego,
    o trzech wartosciach odpowiadajacych trzem stanom: polaczenie nawiazane, polaczenie nienawiazane
    i polaczenie w trakcie nawiazywania.Nastepnie zdefiniuj strukture komputer przechowującą stan połączenia,
    IP podłączonego komputera (jako napis) oraz nazwę jego właściciela.
    Napisz funkcję, która jako argument otrzymuje strukturę komputer
    i wyświetla na standardowym wyjściu jej zawartość w sposób przyjazny dla użytkownika. */

typedef enum {nawiazano, nienawiazano, w_trakcie} Stan;

typedef struct komputer
{
    Stan stan;
    char *IP;
    char *nazwa_w;

} Komputer;

void wczytaj_stan(const Komputer kom);

int main()
{
    Komputer temp;

    temp.stan = 0;
    temp.IP = "192.168.0.1";
    temp.nazwa_w = "Komputer_1";

    wczytaj_stan(temp);
    return 0;
}

void wczytaj_stan(const Komputer kom)
{
    printf("%s", kom.nazwa_w);
    printf("\n%s", kom.IP);
    printf("\nStan polaczenia:\n");

    for(int i = 0; i < 10; i++)
    {
        printf(".");
        Sleep(200);
    }

    printf("\n");

    switch(kom.stan)
    {
    case nawiazano:
        printf("Polaczenia nawiazano...");
        break;
    case nienawiazano:
        printf("Blad polaczenia.");
        break;
    case w_trakcie:
        printf("W trakcie nawiazywania polaczenia.");
        break;
    default:
        printf("Nieprawidlowy stan polaczenia.");
        break;
    }
}


