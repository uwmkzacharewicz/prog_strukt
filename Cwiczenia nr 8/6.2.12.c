int sumuj_tablice(int **tab,unsigned int n , unsigned int m)
{
    int suma = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
           suma += tab[i][j];
    }
 
	return suma;
}