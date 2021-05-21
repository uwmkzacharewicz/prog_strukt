#include <stdio.h>
#include <stdlib.h>

#define DL 50

/* 7.2.8.
    Zdefiniuj strukture student sluzaca do przechowywania danych osobowych studenta
    (struktura powinna zawierac takie pola, jak: imie,nazwisko, adres, pesel, kierunek i numer legitymacji).

    Napisz funkcje, ktora otrzymuje jako argument wskaznik na strukture student i wczytuje dane ze standardowego wejscia
    do rekordu wskazywanego przez argument funkcji */

typedef struct student
{
    char imie[DL];
    char nazwisko[DL];
    char adres[DL];
    char pesel[DL];
    char kierunek[DL];
    char nr_leg[DL];
} Student;

void wyswietl_dane(const Student *stud);

void wczytaj_studenta(Student *stud);
char *wczytaj(char *z, int ile);

int main()
{
    Student nowy;
    Student *wsk_st;

    wsk_st = &nowy;

    printf("%d", sizeof(nowy.nazwisko));

    //nowy.imie = "Karol";      // mozna jezeli *imie
    strcpy(nowy.imie, "Karol");
    strcpy(nowy.nazwisko, "Zacharewicz");
    strcpy(nowy.adres, "Gizycko");
    strcpy(nowy.pesel, "87111112716");
    strcpy(nowy.kierunek, "Informatyka");
    strcpy(nowy.nr_leg, "0001235456");

    wyswietl_dane(wsk_st);
    wczytaj_studenta(wsk_st);
    wyswietl_dane(wsk_st);

    return 0;
}

void wyswietl_dane(const Student *stud)
{
    printf("\n%s", stud->imie);
    printf("\n%s", stud->nazwisko);
    printf("\n%s", stud->adres);
    printf("\n%s", stud->pesel);
    printf("\n%s", stud->kierunek);
    printf("\n%s", stud->nr_leg);
}

void wczytaj_studenta(Student *stud)
{
    printf("\n=> Podaj imie: ");
    wczytaj(stud->imie, DL);
    printf("\n=> Podaj nazwisko: ");
    wczytaj(stud->nazwisko, DL);
    printf("\n=> Adres: ");
    wczytaj(stud->adres, DL);
    printf("\n=> Pesel: ");
    wczytaj(stud->pesel, DL);
    printf("\n=> kierunek: ");
    wczytaj(stud->pesel, DL);
    printf("\n=> Nr legitymacji: ");
    wczytaj(stud->nr_leg, DL);
}


char *wczytaj(char *z, int dl)
{
        char * wynik;
        char * temp;
        wynik = fgets(z, dl, stdin);

        if (wynik)
        {
            temp = strchr(z, '\n');
            if (temp)
                *temp = '\0';
            else
                while (getchar() != '\n')
                    continue;
        }

    return wynik;
}
