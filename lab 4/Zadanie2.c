#include <stdio.h>

void printArray(int array[], int N);
void rightShift(int array[], int N);
void leftShift(int array[], int N);
void rightShiftN(int array[], int N, int toRight);
void leftShiftN(int array[], int N, int toLeft);

int main()
{
    printf("\n");
    int N = 8 , numbers[8] = {1,2,3,4,5,6,7,8};
    leftShiftN(numbers, N, 2);
    printArray(numbers, N);
    printf("\n");

    return 0;
}

void printArray(int array[], int N)
{
    for (int i = 0 ; i < N ; i++)
        printf("%d\t", array[i]);
}

void rightShift(int array[], int N)
{
    for (int i = N-1 ; i > 0 ; i--)
        array[i] = array[i-1];
    array[0] = 0;
}

void leftShift(int array[], int N)
{
    for (int i = 0; i < N-1 ; i++)
            array[i] = array[i+1];
    array[N-1] = 0;    
}

void rightShiftN(int array[], int N, int toRight)
{
    for (int i = N-1 ; i >= 0 ; i--)
        if (i+toRight < N) array[i+toRight] = array[i];

    for (int i = 0 ; i < toRight ; i++) array[i] = 0;
}

void leftShiftN(int array[], int N, int toLeft)
{
    for (int i = 0 ; i < N ; i++)
        if (i-toLeft >= 0) array[i-toLeft] = array[i];

    for (int i = N-1 ; i > N-1-toLeft ; i--) array[i] = 0;
}