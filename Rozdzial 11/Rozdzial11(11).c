#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROZMIAR 81        /* granica dlugosci lancucha, wlacznie z \0  */
#define GRAN 10           /* maksymalna liczba wierszy                 */

#define NULL ((void *)0)


char *wczytaj(char *z, int ile);
void wyswietl(const char* str);
void pokazmenu();
int pobierz_wybor(int, int);
void wyswietl_lista(const char tab[][ROZMIAR], int licz);
void wyswietl_lista_wsk(const char *tab[], int licz);
void sort_alfab(char *lancuchy[], int num);
void sort_dlug(char *lanuchy[], int num);
void sort_p_wyraz(char *lancuchy[], int num);
int dl_pierw_slowa(const char str[]);


int main()
{
     /* CWICZENIE 11
      Napisz program, ktory wczytuje maksymalnie 10 lancuchow i konczy odczytywanie w przypadku wystapienia konca pliku.
      Powinien on wyswietlac menu zawierajace piec opcji:
      (1) wyswietlenie pierwotnej listy lancuchow,
      (2) wyswietlenie lancuchow w porzadku ASCII,
      (3) wyswietlenie lancuchow wedlug dlugosci (rosnaco),
      (4) wyswietlenie lancuchow wedlug dlugosci pierwszego slowa oraz
      (5) koniec.
    Menu powinno byc wyswietlane dopoty, dopoki uzytkownik nie wybierze opcji
    nr 5. Rzecz jasna, program powinien rzeczywiscie wykonywac zapowiedziane
    czynnosci.
    */

    char dane[GRAN][ROZMIAR];    /* tablica przechowujaca dane wejsciowe */
    char *wsklan[GRAN];          /* tablica zmiennych wskaznikowych      */

    int wybor;
    int licz = 0;                /* licznik danych wejsciowych           */
    int k;                       /* licznik danych wyjsciowych           */

    char temp[GRAN][ROZMIAR] = {
                            "Lorem Ipsum is simply dummy",
                            "It was popularised in the 1960s." ,
                            "And more recently with desktop",
                            "Content here, content here, making it look like readable English.",
                            "Many desktop publishing packages and web page editors.",
                            "Various versions have evolved over the years, sometimes by accident",
                            "Contrary to popular belief",
                            "Lorem Ipsum is not simply random text.",
                            "Lorem Ipsum comes from sections 1.10.32 and 1.10.33",
                            "written in 45 BC. This book is a treatise on the theory of ethics"};

    // utworzenie kopii pierwotnej tablicy lancuchow
    char pierwotna[GRAN][ROZMIAR];

    // skopiowanie zawartosci
    for (int i = 0; i < GRAN; i++)
        strncpy(pierwotna[i],temp[i], ROZMIAR);

    //printf("\nDANE:\n");
   // wyswietl_lista(temp,GRAN);

   // printf("\nKOPIA:\n");
    //wyswietl_lista(pierwotna,GRAN);

    /*
    printf("Podaj maksymalnie %d wierszy:\n",GRAN);
    printf("Aby zakonczyc, wcisnij Enter na poczatku wiersza.\n");
    while (licz < GRAN && wczytaj(dane[licz], ROZMIAR) != NULL
                              && dane[licz][0] != '\0')
    {
     wsklan[licz] = dane[licz];    //ustaw wskazniki na lancuchy
     licz++;
    }

    */


    // ustawienie tablicy wskazników na tablice lancuchów
    for(int i = 0; i < GRAN; i++)
        wsklan[i] = temp[i];



    pokazmenu();
    printf("Podaj numer wybranej opcji: \n");

    while ( (wybor = pobierz_wybor(1,5)) != 5)
    {

        switch(wybor)
        {
        case 1  :  wyswietl_lista(pierwotna,GRAN) ;  break;
        case 2  :  sort_alfab(wsklan,GRAN); wyswietl_lista_wsk(wsklan,GRAN) ;  break;
        case 3  :  sort_dlug(wsklan, GRAN) ; wyswietl_lista_wsk(wsklan,GRAN) ; break;
        case 4  :  sort_p_wyraz(wsklan, GRAN) ; wyswietl_lista_wsk(wsklan,GRAN) ; break;
        default :  printf("\nCos poszlo nie tak...\n");  break;
        }

        printf("Podaj numer wybranej opcji: \n");

        printf("\n\n");
        system("pause");
        system("CLS");
        pokazmenu();
    }

     printf("\n\n");

    return 0;
}


char *wczytaj(char *z, int ile)
{
    char * wynik;
    int i = 0;

    wynik = fgets(z, ile, stdin);

    if (wynik) // wynik rozny od NULL
    {
        while (z[i] != '\n' && z[i] != '\0')
            i++;

        if (z[i] == '\n')
                z[i] = '\0'; // znak nowego wiersza -> znak pusty
        else // z[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return wynik;
}

//void pierwotna_lista(char **tab, int licz)
void wyswietl_lista(const char tab[][ROZMIAR], int licz)
{
    for (int k = 0; k < licz; k++)
        puts(tab[k]) ;
}


void wyswietl_lista_wsk(const char *tab[], int licz)
{
    for (int k = 0; k < licz; k++)
        puts(tab[k]) ;

}

void sort_alfab(char *lancuchy[], int num)
{

  char *temp;
  int dol, szuk;
  for (dol = 0; dol < num-1; dol++)
     for (szuk = dol + 1; szuk < num; szuk++)
        if (strcmp(lancuchy[dol],lancuchy[szuk]) > 0)
        {
            temp = lancuchy[dol];
            lancuchy[dol] = lancuchy[szuk];
            lancuchy[szuk] = temp;
        }
}

void sort_dlug(char *lancuchy[], int num)
{
    char *temp;
    int dol, szuk;

    for (dol = 0; dol < num-1; dol++)
        for (szuk = dol + 1; szuk < num; szuk++)
            if (strlen(lancuchy[dol]) > strlen(lancuchy[szuk]))
            {
                temp = lancuchy[dol];
                lancuchy[dol] = lancuchy[szuk];
                lancuchy[szuk] = temp;
            }

}

int dl_pierw_slowa(const char str[])
{
     int licznik = 0;
     int nr_zn = 0;

     while(str[nr_zn] != ' ')
        {
            licznik++;
            nr_zn++;
        }

    return licznik;
}

void sort_p_wyraz(char *lancuchy[], int num)
{
    char *temp;
    int dol, szuk;

    for (dol = 0; dol < num-1; dol++)
        for (szuk = dol + 1; szuk < num; szuk++)
            if ( dl_pierw_slowa(lancuchy[dol]) > dl_pierw_slowa(lancuchy[szuk]))
            {
                temp = lancuchy[dol];
                lancuchy[dol] = lancuchy[szuk];
                lancuchy[szuk] = temp;
            }
}

void pokazmenu(void)
{
    printf("Wybierz jedna z ponizszych mozliwosci:\n");

    printf("[1] wyswietlenie pierwotnej listy lancuchow\n");
    printf("[2] wyswietlenie lancuchow w porzadku ASCII\n");
    printf("[3] wyswietlenie lancuchow wedlug dlugosci (rosnaco)\n");
    printf("[4] wyswietlenie lancuchow wedlug dlugosci pierwszego slowa\n");
    printf("[5] koniec\n");

}

int pobierz_wybor(int dol, int gora)
{
    int odp;
    int ok;

    ok = scanf("%d", &odp);

    while (ok == 1 && (odp < dol || odp > gora))
        {
        printf("%d nie jest poprawnym wyborem; sprobuj jeszcze raz: ",odp);
        //pokazmenu();
        ok = scanf("%d", &odp);
    }
    if (ok != 1)
        {
            printf("Nieprawidlowe wejscie. ");
            odp = 5;
        }
    return odp;
}


void wyswietl(const char* str)
{

    while(*str != '\0')
        putchar(*str++);

}
