#include <stdio.h>
#include <stdlib.h>

int main()
{

    /* Napisz program, ktory wczytuje ze standardowego wejscia dwie liczby
    calkowite i wypisuje na standardowym wyjsciu wieksza z nich
    (w przypadku gdy podane liczby sa rowne, program powinien wypisac ktora-
    kolwiek z nich)
    */

    int stan;
    int a,b;

    printf("Podaj dwie liczby: ");

    stan =  scanf("%d %d", &a, &b);

    while (stan != 2)       // dwie liczby wpisano prawidlowo
    {
        printf("Wpisz wartosci jeszcze raz: ");

        while (getchar() != '\n')
        continue;

        stan =  scanf("%d %d", &a, &b);

    }

    printf("\nLICZBY: %d %d, wieksza: ", a,b);

    if(a >= b)
        printf("%d", a);
    else
        printf("%d", b);

    return 0;
}
