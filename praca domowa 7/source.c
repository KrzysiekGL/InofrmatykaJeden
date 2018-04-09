/*
Napisz program, który pobiera ze standardowego wejścia linie tekstu. W programie mają być zliczane litery
alfabetu oraz cyfry występujące w danych doprowadzonych na wejście. Po zakończeniu podawania danych (gdy wystąpi EOF) prorgram ma zwrócić statystykę:
liczbę liter, liczbę cyfr oraz liczbę wprowadzonych linii tekstu(każda linia zakończona jest '\n').
*/

/*
Instrukcja:
program należy w ten sposób uruchomić po skompilowaniu:
w cmd (w katalogu programu): program.exe < dane.txt
gdzie plik "dane.txt" jest dowolnym plikiem tekstowym
(niestety eNauczanie nie pozwoliło mi dołączyć własnych plików tekstowych, ograniczenie do uploadu jednego pliku w ramach pracy domowej)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int alphabet = 0, numeric = 0, newLine = 0;
    int znak;
    do{
        znak = getchar();
        if(znak == 0xA) newLine++;
        if((znak >= 65 && znak <= 90) || (znak >= 97 && znak <= 122)) alphabet++;
        if(znak >= 48 && znak <= 57) numeric++;
    }while (znak != EOF);
    printf("\nW podanym tekscie naliczono:\n%d znakow alfabetu \n%d cyfr \n%d znakow nowej linii\n", alphabet, numeric, newLine);

    return 0;
}