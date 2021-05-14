int sumuj_tablice(int tab[][100], unsigned int n)
{
    int suma = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 100; j++)
            suma += tab[i][j];

    return suma;
}

