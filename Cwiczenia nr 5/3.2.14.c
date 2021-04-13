#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sgn_x1(int x);
int sgn_x2(int x);

int fun1(int a);
int fun2(int b);

typedef int(*wsk_fun)(int);

// bool wykonaj(int(*wsk_fun)(int), int(*wsk_fun)(int), unsigned int n);
bool wykonaj(wsk_fun pierwsza, wsk_fun druga, unsigned int n);

int main()
{
    /*
    Napisz funkcję, która otrzymuje trzy argumenty:
    — dwa wskaźniki na funkcje o jednym argumencie typu int zwracające wartość typu int,
    — wartość n typu unsigned int, i zwraca:
        true,   jeżeli otrzymane w argumentach funkcje są równe dla wartości od 0 do n i
        false,  w przeciwnym wypadku.
    */

    printf("\n\n-----------------  3.2.14  ---------------------\n\n");

    printf("\nWYNIK: %d", wykonaj(fun1,fun2,10));
    printf("\nWYNIK: %d", wykonaj(fun2,fun2,5));
    printf("\nWYNIK: %d", wykonaj(fun2,fun2,10));
    printf("\nWYNIK: %d", wykonaj(fun1,fun2,10));

    printf("\n\n\nWYNIK: %d", wykonaj(sgn_x1,sgn_x2,5));
    printf("\nWYNIK: %d", wykonaj(sgn_x1,sgn_x2,9));
    printf("\nWYNIK: %d", wykonaj(sgn_x1,sgn_x2,10));

    printf("\n\n------------------------------------------------\n\n");

    return 0;
}

int fun1(int a)
{
    return a;
}

int fun2(int b)
{
    return b * 2;
}

int sgn_x1(int x)
{
  return (x > 10) - (x < 10);
}

int sgn_x2(int x)
{
  return (x > 20) - (x < 20);
}

bool wykonaj(wsk_fun pierwsza, wsk_fun druga, unsigned int n)
{
    for (unsigned int i = 0; i <= n; i++)
        if (pierwsza(i) != druga(i))
            return false;       // jezeli nie sa rowne zwroc false

    // jezeli wszystkie wywolania funkcji sa rowne
    // zwroc true
    return true;
}
