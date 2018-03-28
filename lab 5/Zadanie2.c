#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drukuj2D(int K, int W, int tablica[K][W]);
void generuj2D(int K, int W, int tablica[K][W]);
void zamien(int *a , int *b);
void zadanie(int K, int W, int tablica[K][W]);

int main()
{
    const int Wiersze = 4, Kolumny = 4;
    int liczby[Wiersze][Kolumny];
    generuj2D(Kolumny, Wiersze , liczby);
    drukuj2D(Kolumny, Wiersze, liczby);
    zadanie(Kolumny, Wiersze, liczby);
    drukuj2D(Kolumny, Wiersze, liczby);

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

void generuj2D(int K, int W, int tablica[K][W])
{
    srand(time(NULL));
    printf("Generowanie wartosci pseudolosowych do tablicy:\n");
    for (int x = 0 ; x < K ; x++)
        for (int y = 0 ; y < W ; y++)
          tablica[x][y] = rand()% 50 +1;  
}

void zamien(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} 

void zadanie(int W, int K, int tablica[W][K]) //dzialanie wytlumaczono w pliku: wyjasnieni funkcji zadanie().txt
{
    for (int x = 0 ; x <= K-2 ; x++)
        for (int y = x+1 ; y <= K-1 ; y++)
            zamien(&tablica[x][y], &tablica[y][x]);
}
