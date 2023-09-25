#include <stdio.h>


/*Imprime la tabla Fahrenheit-Celcius*/
main()
{
    int fahr;
    printf("Fahr Cel\n");
    for (fahr = 0;fahr <= 300; fahr= fahr + 20)
        printf("%3d%6.1f\n", fahr,(5.0/9.0)*(fahr-32));
}
