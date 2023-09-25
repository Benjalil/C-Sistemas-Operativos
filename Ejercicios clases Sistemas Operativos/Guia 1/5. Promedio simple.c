#include <stdio.h>
main(){
    float n1,n2,n3,n4;

    printf("Ingrese la primera nota: ");
    scanf("%f",&n1);

    printf("Ingrese la segunda nota: ");
    scanf("%f",&n2);

    printf("Ingrese la tercera nota: ");
    scanf("%f",&n3);

    printf("Ingrese la cuarta nota: ");
    scanf("%f",&n4);

    printf("%.2f\n", ((n1+n2+n3+n4)/4));

    return 0;

}