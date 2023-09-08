/*

Cambiemos la conversión en este caso de Celsius a Fahrenheit:

Crea un nuevo fichero cap1_pr02.c
Genera la estructura del programa main
Busca la fórmula a través de google u otro buscador de la conversión desde Celsius a Fahrenheit
Modifica tanto la fórmula de conversión como las variables para que el código realice la nueva conversión
Modifica también los límites para que se realicen desde -10ºC hasta 50ºC de 10º en 10º
*/

#include <stdio.h>
main()
{
    int fahr,cel;
    int top,bot,step;

    top=-10;
    bot=50;
    step=10;

    cel=top;

    while (cel<=bot)
    {
        fahr=((cel*9)/5)+32;
        printf("%d\t%d\n",cel,fahr);
        cel=cel+step;
    }
}
