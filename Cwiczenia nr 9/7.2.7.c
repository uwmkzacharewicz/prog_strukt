#include <stdio.h>
#include <stdlib.h>

/* 7.2.7.
    Zdefiniuj strukture zespolone sluzaca do przechowywania liczb zespolonych.
    Zdefiniowana struktura powinna zawierac pola im i re typu double sluzace
    do przechowywania odpowiednio czesci urojonej i rzeczywistej liczby zespolonej.

    Napisz funkcje dodaj, ktora dostaje dwa argumenty typu zespolone
    i zwraca jako wartosc ich sume. */

typedef struct zespolone
{
    double re;      // czesc rzeczywsita
    double im;      // czesc urojona
} Zespolone;

//typedef struct zespolone Zespolone;

Zespolone suma_zesp(const Zespolone n1, const Zespolone n2);

int main()
{
    Zespolone liczba1;
    Zespolone liczba2;
    Zespolone suma;

    liczba1.re = 20;
    liczba1.im = 5;

    liczba2.re = 12;
    liczba2.im = 7;

    printf("%g + %gj", liczba1.re, liczba1.im);
    printf("\n%g + %gj", liczba2.re, liczba2.im);
    printf("\n---------------");

    suma = suma_zesp(liczba1, liczba2);

    printf("\n%g + %gj", suma.re, suma.im);

    return 0;
}

Zespolone suma_zesp(const Zespolone n1, const Zespolone n2)
{
    Zespolone wynik;

        wynik.re = n1.re + n2.re;
        wynik.im = n1.im + n2.im;

    return wynik;
}
