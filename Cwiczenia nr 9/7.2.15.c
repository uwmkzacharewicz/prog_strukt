#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 


/* 7.2.15.
   Zdefiniuj typ wyliczeniowy zwierzak, mogacy przyjmowac wartosci
    odpowiadajace nazwom roznych zwierzat domowych. */

enum zwierzak{pies, kot, krowa, kon, renifer};

int main()
{
    enum zwierzak pierwszy;

    pierwszy = pies;

    printf("%d", pierwszy);
    printf("\n%d", renifer);

    return 0;
}