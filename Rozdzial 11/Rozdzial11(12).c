#include <stdio.h>


int main(int argc, char *argv[])
{
     /* CWICZENIE 12
    Napisz program, ktory wyswietla na ekranie argumenty wiersza polecen
    w odwrotnej kolejnosci. Jesli argumentami sa na przyklad slowa idz do domu,
    program powinien wyswietlic domu do idz.
    */

    printf("\n\n---------------- CWICZENIE   12 ----------------\n\n");

    int licznik;
    printf("Wiersz polecen zawiera %d argumentow, odwrotna kolejnosc:\n", argc - 1);

    for (licznik = argc - 1; licznik > 0; licznik--)
        printf("%d: %s\n", licznik, argv[licznik]);

    printf("\n");

    printf("\n-----------------------------------------------------");


    return 0;
}