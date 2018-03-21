//odwracanie tablicy jednowymiarowej

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WT 10

int main()
{
    srand(time(NULL));

    int tablica[WT] = {0};

    for (int i = 0 ; i < WT ; i++)
    {
        tablica[i] = rand()% 20 +1;
        printf("%d\t", tablica[i]);
    }
    printf("\n\n");

    //algorytm odwracania
    int bufor = 0;
    for (int i = 0 ; i < (WT/2) ; i++)
    {
        bufor = tablica[i];
        tablica[i] = tablica[(WT-1-i)];
        tablica[(WT-1-i)] = bufor;         
    }

    for (int i = 0 ; i < WT ; i++)
    {
    printf("%d\t", tablica[i]);
    }
    printf("\n\n");

    return 0;
}
