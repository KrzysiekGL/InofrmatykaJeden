#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drukuj(int tablica2D[5][5]);
void generuj(int tablica2D[5][5]);
void zamiana(int tablica2D[5][5] , int *X, int *Y);
void sprawdzenie(int *X, int *Y, int tablica2D[5][5]);

int main()
{
    int swiatla[5][5];

    generuj(swiatla);
    drukuj(swiatla);

    int W, K, czyZnow = 0;
    do{
        if (czyZnow) drukuj(swiatla);
        printf("wprowadz kolejno wiersz i kolumne do zmiany: \n");
        scanf("%d", &W);
        scanf("%d", &K);
        sprawdzenie(&W, &K, swiatla);
        printf("jezeli chcesz zakonczyc wporwadz [0] \npo wprowadzeniu innej wartosci program bedzie bedzie kontynowany: ");
        scanf("%d", &czyZnow);
    }while(czyZnow);

    return 0;
}

void drukuj(int tablica2D[5][5])
{
    for (int x = 0 ; x < 5 ; x++)
    {
        printf("\n");
        for (int y = 0 ; y < 5 ; y++)
            printf("%d ", tablica2D[x][y]);
    }
    printf("\n");      
}

void generuj(int tablica2D[5][5])
{
    srand(time(NULL));
    for (int x = 0 ; x < 5 ; x++)
        for (int y = 0 ; y < 5 ; y++)
            tablica2D[x][y] = rand()% (1 +1);
}

void sprawdzenie(int *X, int *Y, int tablica2D[5][5])
{
    if((*X >= 0 && *X <= 4)&&(*Y >= 0 && *Y <= 4))
        zamiana(tablica2D, X, Y);
    else printf("\nNiepoprawne wspolrzedne\n");
}

void zamiana(int tablica2D[5][5] , int *X, int *Y)
{
    if (tablica2D[*X][*Y] == 0)
        for (int i = 0 ; i < 5 ; i++)
        {
            tablica2D[*X][i] = 1;
            tablica2D[i][*Y] = 1;
        }
    else
        for (int i = 0 ; i < 5 ; i++)
        {
            tablica2D[*X][i] = 0;
            tablica2D[i][*Y] = 0;
        }
    drukuj(tablica2D);
}