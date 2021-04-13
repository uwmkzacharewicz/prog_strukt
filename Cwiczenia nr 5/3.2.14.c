#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


int fun1(int a)
{
    return a * 2;
}

int fun2(int b)
{
    return b * 3;
}

typedef int(*wsk_fun)(int);

bool wykonaj(wsk_fun pierwsza, wsk_fun druga, unsigned int n)
{
    for (unsigned int i = 0; i <= n; i++)
        if (pierwsza(i) != druga(i))
            return false;       // jezeli nie sa rowne zwroc false

    // jezeli wszystkie wywolania funkcji sa rowne
    // zwroc true
    return true;
}

int main()
{
    /*
    Napisz funkcję, która otrzymuje trzy argumenty:
    — dwa wskaźniki na funkcje o jednym argumencie typu int zwracające wartość typu int,
    — wartość n typu unsigned int, i zwraca:
        true,   jeżeli otrzymane w argumentach funkcje są równe dla wartości od 0 do n i
        false,  w przeciwnym wypadku.
    */

    printf("\n\n--------------------  3.2.14  ---------------------");

    printf("\n\nWYNIK: %d", wykonaj(fun1,fun2,10));
    printf("\n\nWYNIK: %d", wykonaj(fun2,fun2,5));
    printf("\n\nWYNIK: %d", wykonaj(fun2,fun1,7));
    printf("\n\nWYNIK: %d", wykonaj(fun1,fun1,2));

    printf("\n\n------------------------------------------------\n\n");

    return 0;
}

