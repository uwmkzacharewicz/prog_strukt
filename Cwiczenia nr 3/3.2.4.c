#include <stdio.h>
#include <stdlib.h>

void zamien(int *a, int *b);

int main()
{

	/* ZADANIE 3.2.4
    Napisz funkcje otrzymujaca jako argumenty wskazniki do dwoch zmiennych typu int,
    ktora zamienia ze soba wartosci wskazywanych zmiennych tylko wtedy, gdy wskazywana
    przez drugi argument zmienna jest
    mniejsza od zmiennej wskazywanej przez pierwszy argument*/

    printf("\n\n---------------- ZADANIE  3.2.4 ----------------\n\n");

    int n = 22;
    int m = 10;

    int *wsk_n;
    int *wsk_m;

    wsk_n = &n;
    wsk_m = &m;

    printf("n = %d, m = %d", n, m);

    zamien(wsk_n,wsk_m);
    printf("\nPo zmianie:\nn = %d, m = %d", n, m);



    printf("\n\n------------------------------------------------\n\n");

    return 0;
}


void zamien(int *a, int *b)
{
    int temp;

    if (*b < *a)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }

}
