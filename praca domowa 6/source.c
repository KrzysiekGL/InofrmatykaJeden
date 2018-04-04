/*
Napisz definicje funkcji zamien(), minimum() i sortuj_wybor() (rozumiem, że "wybor" znaczy jak chcę posrotwac - dop. moja). Przyjmij wskaznikowe parametry tych funkcji
(zamiast tablicowych).W funkcjach zamiast indeksowania tablicowego wykorzystaj tylko arytmetyke wskaznikow. W programie glownym pokaz demo uzycia tych funkcji:
znajdz minimum w tablicy o rozmiarze 17 wygenerowanej losowo, posortuj tablice oraz zamien wartosci dwoch sasiednich elementow wokol elementu srodkowego.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *minimum(int *tablica, int first, int last, char wybor);
void zamien(int *tablica, int first, int last);
void sortuj_wybor(int *tablica, int N);
void drukuj(int *tablica, int N);
void generuj(int *tablica, int N);


int main()
{
    const int rozmiar = 17;
    int liczby[rozmiar];

    generuj(liczby, rozmiar);
    drukuj(liczby, rozmiar);
    sortuj_wybor(liczby, rozmiar);  //sortowanie
    drukuj(liczby, rozmiar);
    printf("\nminimum tablicy = %d", *(liczby + (rozmiar-1)));    //wartosc minimalna
    printf("\nzmienianie wartosci dwoch sasiednich elementow wokol elementu srodkowego...");
    int prim, bis;
    prim = ((liczby + (rozmiar-1)) - liczby)/2 -1;
    bis = ((liczby + (rozmiar-1)) - liczby)/2 +1;
    zamien(liczby, prim, bis);
    drukuj(liczby, rozmiar);

    return 0;
}

int *minimum(int *tablica, int first, int last, char wybor)
{
    int *k = tablica;  
    for (int i = first ; i <= last ; i++)
    {  
        if(wybor == 'r') if ( *(tablica + i) < *k ) k = (tablica + i);     
        if(wybor == 'm') if ( *(tablica + i) > *k ) k = (tablica + i);
    }
    return k;
}

void zamien(int *tablica, int first, int last)
{
    int temp = *(tablica + first);
    *(tablica + first) = *(tablica + last);
    *(tablica + last) = temp;
}

void sortuj_wybor(int *tablica, int N)
{
    printf("\nnie[m]alejaco czy nie[r]osnaco? wpisz odpowiednia litere [.]: ");
    char wybor;
    do{
        scanf("%c", &wybor);
    }while (wybor != 'r' && wybor != 'm');

    int *indeksMin = tablica;
    int first = 0, last = N-1;
    do{
        indeksMin = minimum(tablica, first, last, wybor);
        zamien(tablica, (indeksMin - tablica), last);
        last--;
    }while(last > first);
}

void drukuj(int *tablica, int N)
{
    printf("\n");
    for(int i = 0 ; i < N ; i++)
        printf("%d\t", *(tablica + i));
}

void generuj(int *tablica, int N)
{
    srand(time(NULL));
    for(int i = 0 ; i < N ; i++)
        *(tablica + i) = rand()% 10 +1;
}