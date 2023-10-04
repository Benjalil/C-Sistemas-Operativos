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
    
    if (n1<1.0 || n2<1.0||n3<1.0||n1>7||n2>7||n3>7)
    {
        printf("ingrese correctamente sus notas");
        return 0;
    }
    else {
        if (promedio< 3.95)
        {
            printf("Tu promedio de notas es : %.2f\n Estas REPROBADO", promedio);
        }
        else if (3.95 <= promedio && promedio <= 4.94)
        {

        
            printf("Tu promedio de notas es : %.2f\n Vas a Examen", promedio);
        }
        else if (promedio >= 4.95)
        {
            printf("Tu promedio de notas es : %.2f\n Estas Aprobado", promedio);
        }
    }
    return 0;

}