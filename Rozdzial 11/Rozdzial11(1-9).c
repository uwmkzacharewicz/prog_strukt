#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NULL ((void *)0)                            // cwiczenie 4


void wczytaj_n_znak(char *bufor, int n);

void wyswietl(const char* str);
void wyswietl_adresy(const char* str);

void wczytaj_n_znak_bialy(char *bufor, int n);
void wczytaj_slowo(char *bufor);                    // cwiczenie 3

char *znajdz_znak_wsk(char *bufor, char c);         //cwiczenie 4
bool zawiera(char ch, const char *str);             //cwiczenie 5

char *zawiera_lan(char *str, char* szukaj);         //cwiczenie 7


 /* CWICZENIE 8
      Napisz funkcje, ktora odwraca zawartosc lancucha i zapisuje ja w tym samym
    lancuchu.
    */

void odwroc_lancuch(char *str);


/* CWICZENIE 9
      Napisz funkcje, ktora pobiera lancuch i usuwa z niego odstepy.
      Wyprobuj ja w programie, ktory odczytuje wiersze za pomoca petli i konczy dzialanie po wpisaniu pustej linii.
      Program powinien stosowac funkcje do kazdego wpisanego wiersza i wyswietlac wynik.
    */

void wczytaj_zdanie_usun_odstepy(char bufor[]);


int main()
{
	 /* CWICZENIE 1
   Zaprojektuj funkcje, ktora pobiera z klawiatury najblizsze n znakow (wlacznie
	z odstepami, tabulatorami i znakami nowej linii) i zapisze wynik do tablicy przekazanej przez adres argumentem wywolania funkcji.
    */

    printf("\n\n---------------- CWICZENIE   1 ----------------\n\n");

    char napis1[50];

    int n = 10;

    printf("Wpisz zdanie, %d znakow przepisze do tablicy: ", n);
    wczytaj_n_znak(napis1, n);

    printf("zawartosc tablicy: ");
    wyswietl(napis1);

    fflush(stdin);

    printf("\n-----------------------------------------------------");


    /* CWICZENIE 2
    Zmodyfikuj funkcje z cwiczenia 1 tak,
    aby konczyla dzialanie po odczytaniu n znakow lub
    po napotkaniu pierwszego odstepu, tabulatora lub znaku nowej linii.
    (Nie korzystaj z funkcji scanf()).
    */

    printf("\n\n---------------- CWICZENIE   2 ----------------\n\n");

    char napis2[50];

    int n2 = 10;

    printf("Wpisz zdanie, %d znakow przepisze do tablicy: ", n2);
    wczytaj_n_znak_bialy(napis2, n2);

    printf("zawartosc tablicy: ");
    wyswietl(napis2);

    fflush(stdin);

    printf("\n-----------------------------------------------------");


	/* CWICZENIE 3
    Zaprojektuj funkcje, ktora pobiera z danych wejsciowych i zapisuje do przekazanej tablicy pierwsze slowo,
    a reszte wiersza porzuca.
    Za slowo mozesz uznac ciag znakow niezawierajacy odstepow,
    tabulatorow lub znakow nowej linii.
    Uzyj funkcji getchar()
    */

    printf("\n\n---------------- CWICZENIE   3 ----------------\n\n");

    char napis3[50];

    printf("Wpisz zdanie, przepisze pierwsze slowo: ");
    wczytaj_slowo(napis3);

    printf("zawartosc tablicy: ");
    wyswietl(napis3);

    fflush(stdin);

    printf("\n-----------------------------------------------------");


    /* CWICZENIE 4
     Zaprojektuj i sprawdz funkcje wyszukujaca w lancuchu przekazanym w pierwszym argumencie pierwszego
     wystapienia znaku podanego w drugim argumencie.
    W przypadku znalezienia znaku funkcja ma zwrocic wskaznik do niego, w przeciwnym wypadku wartosc null.
    (Bedzie to analogiczne do dzialania funkcji strchr()).
    */

    printf("\n\n---------------- CWICZENIE   4 ----------------\n\n");

    char napis4[] = "Znajdz X w tekscie?";
    char znajdz = 'X';

    printf("\nAdresy:\n");
    wyswietl_adresy(napis4);

    printf("\n- Znak %c wystepuje pod adresem: %p", znajdz, znajdz_znak_wsk(napis4,znajdz));

    printf("\n-----------------------------------------------------");


    /* CWICZENIE 5
     Napisz funkcje zawiera(), pobierajaca jako argumenty znak oraz lancuch
     i zwracajaca wartosc niezerowa(prawda), jesli znak znajduje sie w lancuchu,
     a w przeciwnym wypadku - wartosc 0
     */

    printf("\n\n---------------- CWICZENIE   5 ----------------\n\n");

    char napis5[] = "Czy znak X jest w tekscie?";
    char zn = 'X';

    printf("\nCzy X jest? (1 - tak, 0 - nie): %d", zawiera(zn, napis5));

    printf("\n-----------------------------------------------------");



	 /* CWICZENIE 7
     Napisz funkcje zawiera_lan(), ktora pobiera jako argumenty dwa wskazniki
    lancuchowe. Jesli drugi lancuch zawiera sie w pierwszym lancuchu, funkcja powinna zwrocic adres,
    pod ktorym rozpoczyna sie ten lancuch. Na przyklad wywo-
    lanie zawiera_lan("pula", "ul") powinno zwrocic adres litery u w slowie pula.
    Jesli drugi lancuch nie zawiera sie w pierwszym lancuchu, zwracana wartoscia
    powinien byc wskaznik zerowy.
    */

    printf("\n\n---------------- CWICZENIE   7 ----------------\n\n");

	char napis7[] = "Ciekawe czy MNIE znajdziesz...";
    char szuk[] = "MNIE";

    wyswietl_adresy(napis7);

    printf("\nNapis : %s\n", napis7);
    printf("Szukaj: %s", szuk);
    printf("\nAdres: |%p|\n",zawiera_lan(napis7,szuk));

     printf("\n-----------------------------------------------------");


      /* CWICZENIE 8
     Napisz funkcje zawiera_lan(), ktora pobiera jako argumenty dwa wskazniki
    lancuchowe. Jesli drugi lancuch zawiera sie w pierwszym lancuchu, funkcja powinna zwrocic adres,
    pod ktorym rozpoczyna sie ten lancuch. Na przyklad wywo-
    lanie zawiera_lan("pula", "ul") powinno zwrocic adres litery u w slowie pula.
    Jesli drugi lancuch nie zawiera sie w pierwszym lancuchu, zwracana wartoscia
    powinien byc wskaznik zerowy.
    */

    printf("\n\n---------------- CWICZENIE   8 ----------------\n\n");

	char napis8[] = "Ciekawe czy MNIE znajdziesz...";
    char szukaj[] = "MNIE";

    wyswietl_adresy(napis8);

    printf("\n\nNapis : %s\n", napis8);
    printf("Szukaj: %s", szukaj);
    printf("\nAdres: |%p|\n",zawiera_lan(napis8,szukaj));

     printf("\n-----------------------------------------------------");


	/* CWICZENIE 9
      Napisz funkcje, ktora pobiera lancuch i usuwa z niego odstepy.
      Wyprobuj ja w programie, ktory odczytuje wiersze za pomoca petli i konczy dzialanie po wpisaniu pustej linii.
      Program powinien stosowac funkcje do kazdego wpisanego wiersza i wyswietlac wynik.
    */

     printf("\n\n---------------- CWICZENIE   9 ----------------\n\n");

	 char zdanie[100];

        while (*zdanie != '\0')
        {
            printf("\nZdanie (pusta linia koczy program): ");
            wczytaj_zdanie_usun_odstepy(zdanie);
            fflush(stdin);
            wyswietl(zdanie);
        }

     printf("\n-----------------------------------------------------");



    return 0;
}

void wyswietl(const char* str)
{
    while(*str != '\0')
        putchar(*str++);
}

void wyswietl_adresy(const char* str)
{
    while(*str != '\0')
    {
        printf("\n|%p| ", str);
        putchar(*str++);
    }
}
void wczytaj_n_znak(char *bufor, int n)
{
    char tmp;
    int i = 0;

    do
    {
        tmp = getchar();
        bufor[i] = tmp;
        i++;

    }while( tmp != EOF && i < n);

    bufor[i] = '\0';
}

// cwiczenie 2
void wczytaj_n_znak_bialy(char *bufor, int n)
{
    char tmp;
    int i = 0;

    do
    {
        tmp = getchar();
        bufor[i] = tmp;
        i++;

    }while( tmp != '\n' && tmp != '\t' && tmp != ' ' && i < n);

    bufor[i] = '\0';
}

// cwiczenie 3
void wczytaj_slowo(char *bufor)
{
   char tmp;
    int i = 0;

    do
    {
        tmp = getchar();
        bufor[i] = tmp;
        i++;

    }while( tmp != '\n' && tmp != '\t' && tmp != ' ');

    bufor[i] = '\0';
}

//CWICZENIE 4
char *znajdz_znak_wsk(char *bufor, char c)
{
    const char *str = bufor;

    while (*str)
    {
        if (*str == c)
            return str;
        str++;
    }
    return NULL;
}

//CWICZENIE 5
bool zawiera(char ch, const char *str)
{
     while (*str)
    {
        if (*str == ch)
            return 1;
        str++;
    }
    return 0;

    /* NOTACJA TABLICOWA
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ch)
            return 1;
        i++;
    }
    return 0;
    */
}

// CWICZENIE 7
char *zawiera_lan(char *str, char *szukaj)
{
    const char *bufor = str;        // bufor pomocniczy
    char *wynik;

    while (*bufor)
    {
        if(*bufor == *szukaj)           // porownanie znaku
        {
            wynik = bufor;              // wskaznik na lancuch

            int i;
            int dl = strlen(szukaj);    // dlugosc szukanego lanucha

            for(i = 0; szukaj[i] != '\0'; i++)    // szukanie znakow lancucha
            {
                if(wynik[i] == szukaj[i])         // jezeli jest przechodzimy dalej
                    continue;
                else                              // jezeli inny znak wychodzimy z petli
                    break;
            }

            if(i == dl)              // jezeli i = dlugosci lancucha czyli znaleziono caly szukany lanuch
               return wynik;
        }
        bufor++;
    }

    wynik = NULL;               // jezeli nie znaleziono zwroc pusty wskaznik
    return wynik;

}

// Cwiczenie 8
void odwroc_lancuch(char *str)
{
    int dl = 0;

    while (str[dl] != '\0')
        dl++;

    int start = 0;
    int koniec = dl-1;

    char temp;

   while(start < koniec)
   {
        temp = str[start];
        str[start] = str[koniec];
        str[koniec] = temp;
        start++;
        koniec--;
   }
}

//CWICZENIE 9
void wczytaj_zdanie_usun_odstepy(char bufor[])
{
    char tmp;
    int i = 0;


    while( tmp != '\n')
    {
        tmp = getchar();

        if(tmp != ' ')
        {
            bufor[i] = tmp;
            i++;
        }
    }
    bufor[i-1] = '\0';
}
