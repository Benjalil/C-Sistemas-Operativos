/*
    Curso C 
    conversion de fahrenheint a celcius

    cap 1, var, expre e iteraciones
*/
    
#include <stdio.h>
// print la tabla de F-C para fahr=0,20 .., 300

main(){
    // Definicion
    
    float fahr,celsius;
    int lower,upper,step;

    // inicializador
    
    lower=0;
    upper=300;
    step=20;

     // %d -> SIRVE PARA REPRESENTAR VARIABLES
    fahr = lower ;

    printf("celsius   fahr\n");
    while(celsius <= upper)
    {
        /*  %d -> SIRVE PARA REPRESENTAR VARIABLES 
            \t%d -> SIRVE PARA TABULAR CADA RESULTADO
        */
        fahr=((9.0/5.0)*celsius)+32.0;
        printf("%3.0f\t%6.2f\n",celsius,fahr);
        celsius=celsius+step;
    }

}
