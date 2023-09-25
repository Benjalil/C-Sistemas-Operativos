/*Constantes simbolicas*/
#include <stdio.h>

/*Como observación, es importante no dejar en 
el código números mágico como 300 y 20 en un programa, ya que 
estos proporcionan poca información a quien tenga que 
leer el programa y son difíciles de modificar , para eliminar
 esta mala practica se aconseja el uso de #define */



#define LOWER 0 /* límite inferior de la tabla */
#define UPPER 300   /* limite superior */
#define STEP 20 /* tamaño del incremento */


/* Las cantidades LOWER, UPPER y STEP son constantes 
simbólicas, no variables,
por lo que no aparecen entre las declaraciones. 
Los nombres de constantes
simbólicas, por convención, se escriben con letras mayúsculas,
 de modo que se
puedan distinguir fácilmente de los nombres de variables escritos con
 minúsculas.
Nótese que no hay punto y coma al final de una línea #define.*/
main( )
{
int fahr;
printf("Fahr Cel\n");
for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
printf("%3d%6.1f\n", fahr,(5.0/9.0)*(fahr-32));;
}
