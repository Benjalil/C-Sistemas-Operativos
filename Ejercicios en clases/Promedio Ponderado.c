
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

    printf("El promedio de notas es : %.3f\n", promedio);

    return 0;


}