#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int maksimum(double tablica[], int N, int first, int last);
void zamien(double tablica[], int first, int last);
void sortuj(double tablica[], int N);


int main()
{
    printf("\n");
    srand(time(NULL));

    const int rozmiar = 10;
    double liczby[rozmiar];

    for (int i = 0 ; i < rozmiar ; i++)
    {
        liczby[i] = rand()% 15;
        printf("%.2lf\t", liczby[i]);
    }
    printf("\n");

    sortuj(liczby, rozmiar);
        for (int i = 0 ; i < rozmiar ; i++)
    {
        printf("%.2lf\t", liczby[i]);
    }

    printf("\n");
    return 0;
}

int maksimum(double tablica[], int N, int first, int last)
{
    int k = 0;  
    for (int i = first ; i <= last ; i++)
    {        
        if (tablica[i] > tablica[k]) k = i;
    }
    return k;
}

void zamien(double tablica[], int first, int last)
{
    int temp = tablica[first];
    tablica[first] = tablica[last];
    tablica[last] = temp;
}

void sortuj(double tablica[], int N)
{
    int indeksMax, first = 0, last = N-1;
    do{
        indeksMax = maksimum(tablica, first, last);
        zamien(tablica, indeksMax, last);
        last--;
    }while(last > first);
}
