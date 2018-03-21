#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int array[], int N);
void writeArray(int array[], int N);
void randomArray(int array[], int N);

int main()
{
    const int width = 5;
    int numbers[width] = {0};
    printf("\n");
    writeArray(numbers, width);
    printArray(numbers, width);
    printf("\n");
    randomArray(numbers, width);
    printArray(numbers, width);
    printf("\n");

    return 0;
}

void printArray(int array[], int N)
{
    for (int i = 0 ; i < N ; i++)
        printf("%d\t", array[i]);
}

void writeArray(int array[], int N)
{
    do{
        scanf("%d", &array[--N]);
    }while(N>0);
}

void randomArray(int array[], int N)
{
    srand(time(NULL));
    do{
        array[--N] = rand()% 15;
    }while(N>0);
}