#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drukuj2D(int K, int W, int tablica[K][W]);
void wpisz2D(int K, int W, int tablica[K][W]);
void generuj2D(int K, int W, int tablica[K][W]);

int main()
{
    const int Wiersze = 3, Kolumny = 2;
    int liczby[Wiersze][Kolumny];
    generuj2D(Wiersze, Kolumny, liczby);
    drukuj2D(Wiersze, Kolumny, liczby);

    return 0;
}

void drukuj2D(int K, int W, int tablica[K][W])
{
    printf("Drukowanie podanej tablicy (max 19X75):\n");
    if (K > 19) K = 19;
    if (W > 75) W = 75;
    for (int x = 0 ; x < K ; x++)
    {
        printf("\n");
        for (int y = 0 ; y < W ; y++)
            printf("%d\t", tablica[x][y]);
    }
}

void wpisz2D(int K, int W, int tablica[K][W])
{
    printf("Wpisz wartosci do tablicy:\n");
    for (int x = 0 ; x < K ; x++)
        for (int y = 0 ; y < W ; y++)
            scanf("%d", &tablica[x][y]);
}

void generuj2D(int K, int W, int tablica[K][W])
{
    srand(time(NULL));
    printf("Generowanie wartosci pseudolosowych do tablicy:\n");
    for (int x = 0 ; x < K ; x++)
        for (int y = 0 ; y < W ; y++)
          tablica[x][y] = rand()% 50 +1;  
}