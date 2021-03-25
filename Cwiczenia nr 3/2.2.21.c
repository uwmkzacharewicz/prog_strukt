#include <stdio.h>
#include <stdlib.h>

int rekur(int n);

int main()
{

	/* ZADANIE 2.2.21
    Napisz rekurencyjna funkcje zwracajaca dla otrzymanej w argumencie
    nieujemnej liczby calkowitej n wartosc elementu o indeksie n ciagu
    zdefiniowanego w nastepujacy sposob:
        a0 = 1
        an = 2 * an-1 + 5 dla n > 0  */

    printf("\n\n---------------- ZADANIE  2.2.21 ----------------\n\n");

    printf("%d\n", rekur(10));

    printf("\n\n------------------------------------------------\n\n");

    return 0;
}


int rekur(int n)
{
    if(n == 0)
        return 1;
    else
        return (2 * rekur(n-1) + 5);

}
