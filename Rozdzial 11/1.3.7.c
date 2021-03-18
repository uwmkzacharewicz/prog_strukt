#include <stdio.h>
#include <stdlib.h>

int main()
{

    /* 1.3.7
    Napisz program, który wczytuje ze standardowego wejścia współczynniki równania kwadratowego z jedną niewiadomą
    i wypisuje na standardowym wyjściu wszystkie rozwiązania rzeczywiste tego równania
    lub odpowiednią informację w przypadku braku rozwiązań.
    */

    int a,b,c;
    int stan = 0;

    a = b = c = 0;

    printf("Podaj wspolczynniki a,b i c (oddziel spacja): ");
    stan =  scanf("%d %d %d", &a, &b, &c);

    while (stan != 3 || a == 0)       // czy 3 liczby prawdilowe i a rozne od zera
    {
        printf("Wpisz wartosci jeszcze raz: ");

        while (getchar() != '\n')
            continue;

        stan =  scanf("%d %d %d", &a, &b, &c);
    }

    printf("Wspolczynniki: a = %d, b = %d, c = %d", a, b ,c);

    float delta, x1, x2;
    x1 = 0;
    x2 = 0;
    delta = 0;

    // obliczenie delty
    delta = (b*b) - (4*a*c);

    if (delta > 0)          // dwa rozwiazania
    {
        x1 = (-b - sqrt(delta)) / (2*a);
        x2 = (-b + sqrt(delta)) / (2*a);

        printf("\nRozwiaznia: x1 = %g i x2 = %g", x1,x2);

    }

    else if (delta == 0) // jedno rozwiazanie
    {
        x1= -b / (2*a) ;
        printf("\nRozwiaznie: x = %g", x1);
    }

    else
        printf("\nBrak rozwiazan");

    return 0;
}
