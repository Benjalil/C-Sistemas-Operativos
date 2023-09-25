#include <stdio.h>

main(){

    float a,b,c;

    printf("Ingrese el primer lado: ");
    scanf("%f",&a);

    printf("Ingrese el segundo lado: ");
    scanf("%f",&b);

    printf("Ingrese el tercer lado: ");
    scanf("%f",&c);


    if( a + b > c && a + c > b && c + b > a ) { 

            if ( a==b || a==c || c==b){
                printf("El triangulo es Isoceles");
            }

            else if ( a != b && a!= c && b !=c ){
                printf("El triangulo es Escaleno");
            }
            else if (a == b && a==c && b==c ){
                printf("El triangulo es equilatero"); 
            }       
    } 
    
    else { 
       printf("Introduzca un triagulo valido");
    }

    return 0;
}