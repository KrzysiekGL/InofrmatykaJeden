//wypisywanie ocen
#include <stdio.h>

void slownie(float ocena);

int main()
{
    int ocena;
    do
    {
    printf("\nPodaj ocene w procentach: ");
    scanf("%d", &ocena);
    }while (!(ocena>=0 && ocena<=100));

    if (ocena < 60) slownie(2);
    else if(ocena < 67) slownie(3);
    else if(ocena < 74) slownie(3.5);
    else if(ocena < 81) slownie(4);
    else if(ocena < 89) slownie(4.5);
    else slownie(5);

    return 0; 
}

void slownie(float ocena)
{
    int ocenaInt = ocena*10;

    switch(ocenaInt)
    {
                case 20:
        printf("%.1f -> niedostateczny\n", ocena);
        break;
                case 30:
        printf("%.1f -> dostateczny\n", ocena);
        break;
                case 35:
        printf("%.1f -> dostateczny plus\n", ocena);
        break;
                case 40:
        printf("%.1f -> dobry\n", ocena);
        break;
                case 45:
        printf("%.1f -> dobry plus\n", ocena);
        break;
                case 50:
        printf("%.1f -> bardzo dobry\n", ocena);
        break;
    }
}