#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv [] )
{
    FILE *f = fopen("sample.txt", "r+");
    if (f == NULL)
        return 1;
    long begin = ftell(f);
    printf("Poczatkowa pozycja w pliku: %d\n", begin);
    
    fseek(f, 0, 2);   // dziesiąta pozycja od końca

    long offset = ftell(f);
    printf("Pozycja koncowa w pliku: %d\n", offset);
    printf("Roznica pozycji w pliku: %d\n", offset - begin );

    fclose(f);
    return 0;
    return 0;
}