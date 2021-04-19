#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int str_len(const char *napis);
void wytnij_zn(char *zrodlo, const char *wzor);

int main()
{
	/*   ZADANIE  5.2.12
	Napisz funkcje wytnijzn, ktora dostaje jako argument dwa napisy nap1 i nap2,
	i wycina z napisu nap1 wszystkie znaki niewystepujace w napisie nap2.
	*/

    char napis1[] = "Napis do wyciecia";
    char wzor1[] = "aei";

    char napis2[] = "Pozostaw kkkk iii zyzyzx";
    char wzor2[] = "kzi";

    printf("\n[%s]\\[%s] = ", napis1, wzor1);
    wytnij_zn(napis1, wzor1);
    printf("%s", napis1);

    printf("\n[%s]\\[%s] = ", napis2, wzor2);
    wytnij_zn(napis2, wzor2);
    printf("%s", napis2);

    return 0;
}

void wytnij_zn(char *zrodlo, const char *wzor)
{
    int idx = str_len(wzor);
    bool czy_jest;

    int aktual = 0;
	int odczyt = 0;

     while (zrodlo[odczyt] != '\0')
    {
        czy_jest = false;
        // porownanie znakow ze wzorem
        for(int i = 0; i < idx; i++)
        {
            if(zrodlo[odczyt] == wzor[i])
            {
                czy_jest = true;  // jezeli jest znak to ustaw true
                break;			  // przerwanie petli
            }
        }

        // Jezeli jest znak to pozostaw i przesun indeks
        if(czy_jest)
        {
            zrodlo[aktual] = zrodlo[odczyt];
            aktual++;
        }
        odczyt++;			// zwieksz indeks
    }

    // na koncu lancucha umieszczamy \0
    zrodlo[aktual++] = '\0';
}

int str_len(const char *napis)
{
    int dl = 0;

    while(*(napis++))
        dl++;

    return dl;
}
