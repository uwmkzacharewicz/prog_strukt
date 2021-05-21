#include <stdlib.h>
#include <stdio.h>

/* 7.2.16.
    Zdefiniuj strukture trojkat mogaca sluzyc jako typ elementow listy jednokierunkowej.
    Struktura trojkat powinna posiadac pola sluzace do przechowywania wszystkich bokow trojkata oraz jego pola.

    Napisz funkcje pole, ktora otrzymuje w argumencie liste wskaznikowa o elementach typu trojkat i we wszystkich elementach listy
    do odpowiedniego pola wstawia wartosc pola trojkata o bokach, ktorych dlugosc przechowuje dana struktura.
    Napisz dwie wersje funkcji: dla list z glowa i dla list bez glowy. */


typedef struct trojkat
{
    int bok_a;
    int h;
    double pole;
    struct trojkat *next;

} Trojkat;

void oblicz_pole(Trojkat *lista);


int main()
{
    Trojkat tr1, tr2, tr3;

    tr1.bok_a = 5;
    tr1.h = 12;

    tr2.bok_a = 3;
    tr2.h = 6;

    tr3.bok_a = 4;
    tr3.h = 10;

    tr1.next = &tr2;
    tr2.next = &tr3;
    tr3.next = (Trojkat*) 0;

    Trojkat *lista = &tr1;

    oblicz_pole(lista);

    return 0;
}

void oblicz_pole(Trojkat *lista)
{
    while(lista != NULL)
    {
        lista->pole = 0.5*lista->bok_a*lista->h;
        printf("\nPOLE: %g", lista->pole);
        lista = lista->next;
    }

}
