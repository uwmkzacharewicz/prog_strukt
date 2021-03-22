#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char pobierz_znak(void);
char pobierz_wybor(void);

void dzialanie(int typ_dzialania);              // wykonuje dzialanie na liczbach
float pobierz_float(void);                      // pobiera float rozna od zera
float pobierz_float_r(void);                    // pobiera float rozna od zera

int main()
{

    /* 1.3.9
    Napisz program kalkulator, który wykonuje wybraną przez użytkownika operacją arytmetyczną na dwóch wczytanych liczbach. Program
    powinien wczytywać dane ze standardowego wejścia i wypisywać wynik na standardowym wyjściu.
    */

   int wybor;

    while ( (wybor = pobierz_wybor()) != 'k')
    {
        switch(wybor)
        {
        case 'a'  :   dzialanie(1);  break;
        case 'b'  :   dzialanie(2);  break;
        case 'c'  :   dzialanie(3);  break;
        case 'd'  :   dzialanie(4);  break;
        default   :   printf("\nCos poszlo nie tak...\n");  break;
        }

     printf("\n\n");
    system("pause");
    system("CLS");

    }

    printf("\nKoniec programu...");

    return 0;
}

char pobierz_wybor(void)
{
    int ch;

    printf("\n*************  KALKULATOR  *************\n\n");
    printf(" Wybierz operacje: \n\n");
    printf(" [a] dodawanie \t\t [b] odejmowanie\n");
    printf(" [c] mnozenie \t\t [d] dzielenie \n");
    printf(" [k] wyjscie");
    printf("\n\n****************************************\n");
    printf("=> Wybor: ");

    ch = pobierz_znak();

    while (  (ch < 'a' || ch > 'd') && ch != 'k')
    {
        printf("Wpisz a, b, c, d lub k.\n");
        printf("Twoj wybor: ");
        ch = pobierz_znak();
    }
    return ch;
}


char pobierz_znak(void)
{
    int ch;

    do  // wczytuj dopoki nie napotka znaku drukowanego
    {
        ch = getchar();
    }while(!(isgraph(ch)));

        // czyszczenie pozostalych znakow
    while (getchar() != '\n')
        continue;

    return ch;
}

void dzialanie(int typ_dzialania)
{
    // 1 - dodawanie
    // 2 - odejmowanie
    // 3 - mnozenie
    // 4 - dzielenie

    float p_liczba;
    float d_liczba;

    printf("\nPodaj pierwsza liczbe: ");
    p_liczba = pobierz_float();
    printf("\nPodaj druga liczbe: ");
    d_liczba = pobierz_float();


    if(typ_dzialania == 4 && d_liczba == 0)
    {
        printf("\nNie dzielimy przez 0! Wprowadz druga liczbe jeszcze raz: ");
        d_liczba = pobierz_float_r();
    }

    printf("\nWynik dzialania: ");

    if (typ_dzialania == 1)         // dodawanie
        printf("%g + %g = %g", p_liczba, d_liczba, p_liczba + d_liczba);
    else if (typ_dzialania == 2)    // odejmowanie
        printf("%g - %g = %g", p_liczba, d_liczba, p_liczba - d_liczba);
    else if (typ_dzialania == 3)    // mnozenie
        printf("%g * %g = %g", p_liczba, d_liczba, p_liczba * d_liczba);
    else if (typ_dzialania == 4)    // dzielenie
        printf("%g / %g = %g", p_liczba, d_liczba, p_liczba / d_liczba);
    else
        printf("\nNie zdefiniowane dzialanie..."); return 1;

}

float pobierz_float(void)
{
    float liczba;
    char ch;

    while( (scanf("%f", &liczba) != 1))
    {
        while((ch = getchar()) != '\n')
            continue;

        printf("Bledne dane. Wprowadz liczbe jeszcze raz: ");
    }
    return liczba;
}

float pobierz_float_r(void)
{
    float liczba;
    char ch;

    while( (scanf("%f", &liczba) != 1) || (liczba == 0))
    {
        while((ch = getchar()) != '\n')
            continue;

        printf("Wprowadz liczbe rozna od zera: ");
    }
    return liczba;
}
