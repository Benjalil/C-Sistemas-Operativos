/*
    Curso C 
    conversion de fahrenheint a celcius

    cap 1, var, expre e iteraciones
    gcc tu_archivo.c -o nombre_ejecutable  
    ./nombre_ejecutable
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


    while(fahr<= upper)
    {
        /*  Esto es muy semejante a lo anterior, excepto que fahr y celsius están declarados como float, y la fórmula de 
        conversión está escrita en una forma más natural.
        No pudimos utilizar 5/9 en la versión anterior debido a que la división entera lo
        truncaría a cero. Sin embargo, un punto decimal en una constante indica que ésta
        es de punto flotante, por lo que 5.0/9.0 no se trunca debido a que es una relación
        de dos valores de punto flotante.
        Si un operador aritmético tiene operandos enteros, se ejecuta una operación
        entera. Si un operador numérico tiene un operando de punto flotante y otro entero, este último será convertido 
        a punto flotante antes de hacer la operación. Si
        se hubiera escrito fahr - 32, el 32 sería convertido autom áticam ente a punto
        flotante. Escribir constantes de punto flotante con puntos decimales explícitos,
        aun cuando tengan valores enteros, destaca su naturaleza de punto flotante para 
        los lectores humanos.

        


        */
        celsius=5.0*(fahr-32.0)/9.0;
        printf("%3.0f\t%6.1f\n",fahr,celsius);
        fahr=fahr+step;
    }

}
