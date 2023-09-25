/*
    Curso C 
    conversion de fahrenheint a celcius

    cap 1, var, expre e iteraciones
*/
    
#include <stdio.h>
// print la tabla de F-C para fahr=0,20 .., 300

main(){
    // Definicion
    
    int fahr,celsius;
    int lower,upper,step;

    // inicializador
    
    lower=0;
    upper=300;
    step=20;

     // %d -> SIRVE PARA REPRESENTAR VARIABLES
    fahr = lower ;


    while(fahr<= upper)
    {
        /*  %d -> SIRVE PARA REPRESENTAR VARIABLES 
            \t%d -> SIRVE PARA TABULAR CADA RESULTADO
        */
        celsius=5*(fahr-32)/9;
        printf("%d\t%d\n",fahr,celsius);
        fahr=fahr+step;
    }

}
