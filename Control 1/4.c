#include <string.h>
#include <stdio.h>
#include <math.h>



main()
{

int cont=100;


for(int i=0; i<=10 ; i++ )
{
    int cont1= cont + 10;
    int cont2= cont + 20;
    int cont3= cont + 30;
    int cont4= cont + 40;
    int cont5= cont + 50;
printf("%i\a -> %i\a  %i\a  %i\a %i\a %i\a",i ,cont1,cont2,cont3, cont4,cont5);

if (cont == 150)
{
    cont=100;
}

}

