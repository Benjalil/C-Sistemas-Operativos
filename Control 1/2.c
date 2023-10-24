#include <stdio.h>
#include <math.h>



int main() 
{

int C1,C2,h,p;

float A;


printf("Ingrese el cateto 1 ");
scanf("%i",&C1);


printf("Ingrese el cateto 2  ");
scanf("%i",&C2);


h = sqrt( (C1*C1)+ (C2 * C2));

printf("La hipotenusa es:");

if (C1+C2 > h ||C1+h > C2 || h+C2 > C1   )

{
     A= (0.5*(C1*C2));
     p= h + C2+C1;
    printf("La hipotenusa es: %i el area es: %f y el perimetro es %i", h,A,p);
}
else{
    printf("Triangulo invalido");

}



}