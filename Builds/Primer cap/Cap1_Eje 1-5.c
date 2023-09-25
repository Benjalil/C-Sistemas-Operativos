
/*Ejercicio 1-5. Modifique el programa 
de conversión de tem peraturas de manera
que escriba la tabla en orden inverso, esto es, 
desde 300 grados hasta 0. */

#include <stdio.h>
main()
/*Imprime la tabla Fahrenheit-Celcius*/

{
    int fahr;
    printf("Fahr Cel\n");
    for (fahr = 300;fahr <= 0; fahr= fahr - 20)
        printf("%3d%6.1f\n", fahr,(5.0/9.0)*(fahr-32));
}