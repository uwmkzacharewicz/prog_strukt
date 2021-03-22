#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


// zmienna globalna
int rok_przystepny = 0;

int dni(int miesiac);                   // ZADANIE 1
int ilosc_dni_s(char mies[]);           // ZADANIE 1


// ZADANIE 2
int wczytaj_dzien();
void wczytaj_miesiac(char bufor[]);
int wczytaj_rok();
bool sprawdz_dz_m(int dzien, int mies);
int znajdz_miesiac(char mies[]);
int zwroc_nr_miesiaca(char mies[]);

int policz_dni(int d, int m);



struct miesiac
{
    char nazwa[15];
    char skrot[4];
    int dni;
    int numer;
};

struct miesiac miesiace[12] =
{
    {"Styczen", "sty", 31, 1},
    {"Luty", "lut", 28, 2},
    {"Marzec", "mar", 31, 3},
    {"Kwiecien", "kwi", 30, 4},
    {"Maj", "maj", 31, 5},
    {"Czerwiec", "cze", 30, 6},
    {"Lipiec", "lip", 31, 7},
    {"Sierpien", "sie", 31, 8},
    {"Wrzesien", "wrz", 30, 9},
    {"Pazdziernik", "paz", 31, 10},
    {"Listopad", "lis", 30, 11},
    {"Grudzien", "gru", 31, 12}
};

int main()
{
    /* ZADANIE 1
    Ponownie wykonaj funkcje z pytania nr 5, ale tym razem niech jej argument bedzie
    nazwa, a nie numerem miesiaca. (Pamietaj o funkcji strcmp()). Przetestuj funkcje
    w malym programie.
    */

    extern struct miesiac miesiace[];
    int n = (sizeof miesiace/sizeof miesiace[0]);

    printf("\n\n---------------- ZADANIE   1 ----------------\n\n");
    for(int i = 0; i < n; i++)
        printf("\n%15s %5s %5d %5d", miesiace[i].nazwa, miesiace[i].skrot, miesiace[i].dni, miesiace[i].numer);

    int wynik = ilosc_dni_s("Sierpien");

    printf("\n\n----------------------------------------------\n\n");

     /* ZADANIE 2
    Napisz program, który prosi użytkownika o podanie dnia, miesiąca oraz roku. Miesiąc może zostać wskazany za pomocą numeru (np. „9”),
    nazwy („wrzesien”) lub
    nazwy skróconej („wrz”). Program powinien wyświetlić całkowitą liczbę dni w roku
    do podanego dnia włącznie (pamiętaj o latach przestępnych).
    */

    printf("\n\n---------------- ZADANIE   2 ----------------\n\n");

    int numer_d, numer_m, rok;
    int suma;
    char mies[50];
    int stan;

    printf("-> Podaj dzien: ");
    numer_d = wczytaj_dzien();

    printf("-> Podaj miesiac: ");
    wczytaj_miesiac(mies);
    numer_m = znajdz_miesiac(mies);

    while (numer_m == -1)
    {
        printf("\nNieznany miesiac");
        printf("\nWprowadz pelna nazwe (pierwsza duza litera), skrot (3 pierwsze male litery) lub nr miesiaca:");
        wczytaj_miesiac(mies);
        numer_m = znajdz_miesiac(mies);
    }

    printf("-> Podaj rok: ");
    rok = wczytaj_rok();

    // sprawdzenie czy rok jest przystepny
    if ( (rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0)
        rok_przystepny = 1;
    else
        rok_przystepny = 0;

    // sprawdzenie czy nie wpisano za duzo dni miesiaca
    while (sprawdz_dz_m(numer_d, numer_m) == false)
    {
        printf("\nZa duzo dni w miesiacy!!!");
        printf(" Wprowadz liczbe dni jeszcze raz: ");
        numer_d = wczytaj_dzien();
    }

    printf("\n\nTwoja data: %d-%s-%d, przystepny: %d", numer_d, miesiace[numer_m-1].nazwa, rok, rok_przystepny);

    suma = policz_dni(numer_d, numer_m);

    printf("\n\nOd pierwszego dnia roku minelo %d dni.\n\n", suma);

    printf("\n\n----------------------------------------------\n\n");




    return 0;
}

int dni(int miesiac)
{
    int suma = 0;

        if (miesiac < 1 || miesiac > 12)
            return(-1);
        else
        {
            for (int i = 0; i < miesiac; i++)
                suma += miesiace[i].dni;
            return(suma);
        }
}

// ZADANIE 1
int ilosc_dni_s(char mies[])
{
    int nr_miesiaca = 0;
    int suma = 0;

    // szukanie miesiaca
    for(int i = 0; i < 12; i++)
    {
        if( strcmp(mies , miesiace[i].nazwa) == 0)
        {
            nr_miesiaca = miesiace[i].numer;

            for (int i = 0; i < nr_miesiaca; i++)
                suma += miesiace[i].dni;

            //break;
            return suma;
        }
    }
    return -1;
}



// ZADANIE 2
int wczytaj_dzien()
{
    int bufor, stan;

    stan =  scanf("%d", &bufor);
        while (stan != 1 || (bufor < 1 || bufor > 31))
        {
            printf("Bledna wartosc, wpisz liczbe od 1 do 31: ", bufor);
            while (getchar() != '\n')
                continue;
            stan =  scanf("%d", &bufor);
        }

    while (getchar() != '\n')
                continue;

    return bufor;

}

void wczytaj_miesiac(char bufor[])
{
    char tmp;
    int i = 0;

    do
    {
        tmp = getchar();
        bufor[i] = tmp;
        i++;

    }while( tmp != '\n');

    bufor[i-1] = '\0';

    //while (getchar() != '\n')
    //    continue;
}

int wczytaj_rok()
{
    int bufor, stan;

    stan =  scanf("%d", &bufor);
        while (stan != 1)
        {
            printf("Bledna wartosc, wpisz ponownie: ", bufor);
            while (getchar() != '\n')
                    continue;
            stan =  scanf("%d", &bufor);
        }

    while (getchar() != '\n')
                continue;

    return bufor;
}

bool sprawdz_dz_m(int dzien, int mies)
{
    int max_dni = miesiace[mies-1].dni;

    // jezeli wybrano luty,
    // rok przystepny - 29 dni

    if(mies == 2 && rok_przystepny == 1)
        max_dni++;

    if (dzien > max_dni)
        return false;
    else
       return true;
}


int znajdz_miesiac(char mies[])
{
    int nr_miesiaca;

    // jeżeli wpisano liczbe
    if(isdigit(mies[0]))
    {
        nr_miesiaca = atoi(mies);

        if (nr_miesiaca < 1 || nr_miesiaca > 12)
            return(-1);
        else
            return nr_miesiaca;
    }

    // jezeli wpisano litere
    // to znajdz nr miesiaca
    if(isalpha(mies[0]))
    {
        nr_miesiaca = zwroc_nr_miesiaca(mies);
        return nr_miesiaca;
    }

    return -2;
}

int zwroc_nr_miesiaca(char mies[])
{
    int nr_miesiaca = 0;

    for(int i = 0; i < 12; i++)
    {
         if( (strcmp(mies , miesiace[i].nazwa) == 0) || (strcmp(mies , miesiace[i].skrot) == 0))
        {
            nr_miesiaca = miesiace[i].numer;
            return nr_miesiaca;
        }
    }
    return -1;
}

int policz_dni(int d, int m)
{
    int suma_dni = 0;

    // jezeli rok przystepny i wybrany miesiac wiekszy od lutego
    // dodajemy jeden dzien
    if(m > 2 && rok_przystepny == 1)
        suma_dni++;

    // zliczenie dni poprzednich miesiecy
    for (int i = 0; i < m-1; i++)
                suma_dni += miesiace[i].dni;

    // dodanie dni ostatniego miesiaca
    suma_dni += d;

    return(suma_dni);

}


