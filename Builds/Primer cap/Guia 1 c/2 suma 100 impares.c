#include <stdio.h>



#define INI 1 /*Iniciador (comenzamos con 1)*/
#define UPPER 100 /*Limite superior*/
#define STEP 2 /*Tamano del incremento*/
main()
{
    int imp;
    int sum;
for (imp=INI;imp < 100; imp= imp + STEP)
    sum += imp;
    printf("El resultado de la suma de los primero 100 numeros impares es: %d\n",sum);
return 0;
}