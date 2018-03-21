//czestosc liczby z tablicy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int liczby[50] = {0};
    int czestosc[91] = {0};

    for (int i = 0 ; i < 50 ; i++) liczby[i] = rand() % 80 +11;
    for (int i = 0 ; i < 50 ; i++) printf("%d\t", liczby[i]);

    for (int i = 0 ; i < 50 ; i++) czestosc[liczby[i]]++;


    printf("\n\n");
    for (int i = 10 ; i < 91 ; i++) printf("%d: %d\t", i, czestosc[i]);

    return 0;
}