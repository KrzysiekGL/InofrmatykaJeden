#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float m_sin(float x);
float m_cos(float x);
float m_tan(float x);
int silnia(int A);

int main()
{
    float wartosc;

    printf("====================================================");
    printf("\nProgram liczacy wartosci funkcji trygonometrycznych\ndla podanego argumentu\n");
    printf("(podano przedzialy dla ktorych zaobserwowano\ndopuszczalne wartosci dla wzorow aproxymacyjnych)\n");
    printf("ctrl + c by zakonczyc...\n");

    while(1)
    {
        printf("\npodaj wartosc dla sinusa z przedzialu <-2 ; 2>: ");
        scanf("%f", &wartosc);
        printf("\nm_sin(%.3lf) = %lf \nsin(%.3lf) = %lf ", wartosc, m_sin(wartosc), wartosc, sin(wartosc));

        printf("\n\npodaj wartosc dla cosinusa z przedzialu <-2 ; 2>: ");
        scanf("%f", &wartosc);
        printf("\nm_cos(%.3lf) = %lf \ncos(%.3lf) = %lf ", wartosc, m_cos(wartosc), wartosc, cos(wartosc));

        printf("\n\npodaj wartosc dla tangensa z przedzialu <-0.5 ; 0.5> \nz zalozenia (-Pi/2 ; Pi/2): ");
        scanf("%f", &wartosc);
        printf("\nm_tan(%.3lf) = %lf \ntan(%.3lf) = %lf \n", wartosc, m_tan(wartosc), wartosc, tan(wartosc));
    }

    return 0;
}

int silnia(int A)
{
    int wynikSilni = 1;
    for (int i = 1 ; i < A+1 ; i++)
    {
        wynikSilni *= i;
    }
    return wynikSilni;
}

float m_sin(float x)
{
    int n = 0;
    float wartoscSin = 0;
    do
    {
        wartoscSin += ( ( pow(-1,n) / silnia(2*n+1) ) * pow(x,(2*n+1)) );
        n++;
    }while (n<13);

    return wartoscSin;
}

float m_cos(float x)
{
    int n = 0;
    float wartoscCos = 0;
    do
    {
        wartoscCos += ( ( pow(-1,n) / silnia(2*n) ) * pow(x,(2*n)) );
        n++;
    }while (n<13);

    return wartoscCos;
    
}

float m_tan(float x)
{
    float B[11] = {0, 0.16667, -0.03333, 0.02381, -0.03333, 0.07576, -0.25311, 1.16667, -7.09216, 54.97118, -529.12424};

    int n = 1;
    float wartoscTan = 0;
    do
    {
        wartoscTan += ( ( ( B[n] * pow(-4,n) * (1-pow(4,n)) ) / ( silnia(2*n) ) ) * pow(x,(2*n - 1)));
        n++;
    }while (n<10);

    return wartoscTan;    
}