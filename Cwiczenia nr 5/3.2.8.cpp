#include <iostream>

using namespace std;

void zamien(int &a, int *b)
{
    int temp;

    temp = a;
    a = *b;
    *b = temp;
}

int main()
{
    /* 3.2.8
    Napisz funkcje otrzymujaca dwa argumenty referencje a oraz wskaznik b do zmiennych typu int,
    ktora zamienia ze soba wartosci zmiennych, do ktorych wskaznik i referencje dostala w argumentach.
    */

    int a, b;
    int *wsk_a = &a;
    int *wsk_b = &b;

    int &ref_do_a = a;
    int &ref_do_b = b;

    a = 50;
    b = 20;

    cout << "Przed zamiana: \n";

    cout << "Nazwa\t\tAdres\t\tWartosc";
    cout << "\nref_a\t\t" << &ref_do_a << "\t" << ref_do_a;
    cout << "\nwsk_b\t\t" << wsk_b << "\t" << *wsk_b;
    cout << "\na = " << a << ", b = " << b;

    zamien(ref_do_a, wsk_b);

    cout << "\n\nPo zamianie: \n";

    cout << "Nazwa\t\tAdres\t\tWartosc";
    cout << "\nref_a\t\t" << &ref_do_a << "\t" << ref_do_a;
    cout << "\nwsk_b\t\t" << wsk_b << "\t" << *wsk_b;
    cout << "\na = " << a << ", b = " << b;

    return 0;
}



