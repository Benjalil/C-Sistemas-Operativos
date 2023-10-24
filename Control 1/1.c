#include <string.h>
#include <stdio.h>


main (){

        char cadena[99];
        char letra[1];
        int tamanho,si,cont=0;

        printf("ingrese su cadena de texto ");

        scanf("%s",&cadena);
        
        printf("ingrese su letra  ");

        scanf("%s",&letra);

        tamanho=strlen(cadena);


            for (si = tamanho - 1; si >= 0 ;si-=1)
            {
                
             if (cadena[si] == letra[0])
             {
              cont+=1;
             }

            }

printf("La cadena %s\n",cadena);
printf("Contiene %i letras",cont);

return 0;
}