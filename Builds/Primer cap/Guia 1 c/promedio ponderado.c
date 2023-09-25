#include <stdio.h>

main(){
    float n1,n2,n3;

    printf("Ingrese la primera nota: ");
    scanf("%f",&n1);

    printf("Ingrese la segunda nota: ");
    scanf("%f",&n2);

    printf("Ingrese la tercera nota: ");
    scanf("%f",&n3);

    float promedio = ((n1*0.4)+(n2*0.3)+(n3*0.3));

    if (promedio< 3.95){
        printf("Tu promedio de notas es : %.2f\n Estas REPROBADO", promedio);
    }  
    else if (3.95 <= promedio && promedio <= 4.94){
        printf("Tu promedio de notas es : %.2f\n Vas a Examen", promedio);
    }
    else if (promedio >= 4.95){
         printf("Tu promedio de notas es : %.2f\n Estas Aprobado", promedio);
    }
    return 0;

}


main() {
    float a,b,c;



    if( a + b > c || a + c > b || c + b > a ) { 

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
       
    }

    return 0;
}