#include <stdio.h>
#include <stdlib.h>

int str_len(const char *napis);
int porownaj(const char *napis1, const char *napis2);

int main()
{
	/*   ZADANIE  5.2.3
	Napisz funkcje porownaj, ktora jako argumenty otrzymuje dwa napisy i zwraca 1 gdy napisy sa rowne i 0 w przeciwnym przypadku
	
	*/

    char nap1[] = "Napis";
    char nap2[] = "Napis K";
    char nap3[] = "NApis";
    char *w_nap1 = "Napis";
    char *w_nap2 = "Napis";
    char *w_nap3 = " Napis";

    printf("\nPorownaj: [%s] <=> [%s]: %d",nap1, nap2, porownaj(nap1, nap2));
    printf("\nPorownaj: [%s] <=> [%s]: %d",nap2, nap3, porownaj(nap2, nap3));
    printf("\nPorownaj: [%s] <=> [%s]: %d",nap1, nap3, porownaj(nap1, nap3));

    printf("\nPorownaj: [%s] <=> [%s]: %d",w_nap1, nap1, porownaj(w_nap1, nap1));

    printf("\nPorownaj: [%s] <=> [%s]: %d",w_nap2, nap2, porownaj(w_nap3, nap2));
    printf("\nPorownaj: [%s] <=> [%s]: %d",w_nap2, w_nap1, porownaj(w_nap2, w_nap1));

    printf("\nPorownaj: [%s] <=> [%s]: %d","Napis K", nap2, porownaj("Napis K", nap2));
    printf("\nPorownaj: [%s] <=> [%s]: %d","  Napis", w_nap3, porownaj("  Napis", w_nap3));

    return 0;
}

int porownaj(const char *napis1, const char *napis2)
{
    int rowne = 0;

    while (*napis1 != '\0' || *napis2 != '\0')
    {
        //printf("\n=> POROWNUJE: [%c] <=> [%c]", *napis1, *napis2);

        if(*napis1 == *napis2)
        {
            napis1++;
            napis2++;
        }
        else
            return 0;
    }

    return 1;
}


int str_len(const char *napis)
{
    int dl = 0;

    while(*(napis++))
        dl++;

    return dl;
}
