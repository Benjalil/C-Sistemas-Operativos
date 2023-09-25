#include <stdio.h>
#include <math.h>


main(){

    float a,b,c;

    printf("Ingrese el primer lado: ");
    scanf("%f",&a);

    printf("Ingrese el segundo lado: ");
    scanf("%f",&b);

    printf("Ingrese el tercer lado: ");
    scanf("%f",&c);


    if( a + b > c && a + c > b && c + b > a ) { 
        float perimetro = (a+b+c);
        float semiperimetro = (perimetro/2);
        printf("El perimetro es: %.1f\n",perimetro);
        printf("El semi-perimetro es: %.2f\n",semiperimetro);
        printf("El area es es: %.2f\n",sqrt(semiperimetro*(semiperimetro-a)*(semiperimetro-b)*(semiperimetro-c)));
    } 
    else { 
       printf("Introduzca un triagulo valido");
    }

    return 0;
}