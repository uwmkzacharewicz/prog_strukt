#include <stdio.h>
#include <stdlib.h>

void kopiuj(char *napis, char **do_zmiany)
{
    printf("\n[f: kopiuj] otrzymano: %s\n", *do_zmiany);

    char *nowa_tab = (char*) malloc(strlen(napis)+1);
    strcpy(nowa_tab, napis);

    *do_zmiany = nowa_tab;

    printf("\n[f: kopiuj] oddano: %s\n", *do_zmiany);
}

int main(int argc, char** argv)
{
	/*   ZADANIE  5.2.25
	Napisz funkcje kopiuj, ktora dostaje jako argumenty napis oraz wskaznik do napisu (czyli wskaznik do wskaznika),
	tworzy nowa tablice znakow, kopiuje do niej napis zawarty w pierwszym argumencie,
	i przypisuje wskaznik do nowo utworzonej tablicy do zmiennej wskazywanej przez drugi argument.
	*/

	char *napis = "Napis pierwotny";

	printf("\nWartosc zmiennej [napis] przed zmiana: %s\n", napis);

	kopiuj("Zmieniony tekst", &napis);

	printf("\nWartosc zmiennej [napis] po zmianie: %s\n", napis);

    return 0;
}