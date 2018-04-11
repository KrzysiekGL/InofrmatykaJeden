#include <stdio.h>
#include <stdlib.h>

void ususnNW(char *napis, int N);     //kasuje \n
void printNapis(char *napis, int N);  //drukuje printf()

int main()
{
    const int rozmiar = 64; 

    char dlugiNapis[rozmiar];
    char jedenNapis[rozmiar];
    char drugiNapis[rozmiar];

    fgets(dlugiNapis, rozmiar, stdin);
    fgets(jedenNapis, rozmiar, stdin);
    fgets(drugiNapis, rozmiar, stdin);

    ususnNW(dlugiNapis, rozmiar);
    ususnNW(jedenNapis, rozmiar);
    ususnNW(drugiNapis, rozmiar); 

    puts(dlugiNapis);
    puts(jedenNapis);
    puts(drugiNapis);

    printNapis(dlugiNapis, rozmiar);
    printNapis(jedenNapis, rozmiar);
    printNapis(drugiNapis, rozmiar);

    return 0;
}

void ususnNW(char *napis, int N)
{
    for(int i = 0 ; i < N ; i++)
    {
        if(napis[i] == 0xA) napis[i] = EOF;
    }
}

void printNapis(char *napis, int N)
{
    for(int i = 0 ; i < N ; i++)
        if (napis[i] != '\0') printf("%c", napis[i]);
        else break;
}
