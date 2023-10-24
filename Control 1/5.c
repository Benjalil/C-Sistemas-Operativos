#include <string.h>
#include <stdio.h>
#include <math.h>


main ()
{

        char cadena[99];
        int tamanho,si,no,cont=0;

        printf("ingrese su cadena de texto ");

        scanf("%s",&cadena);
        
        tamanho=strlen(cadena);


            for (si = tamanho - 1,no=0; si >= 0 ;si-=1,no++)
            {
                
             if (cadena[si] == cadena[no])
             {
             cont++;
             }}
             

if (cont==tamanho)
{
printf("La palabra es un palindromo");
}

else
{
    printf("La palabra no es palindromo");
}




return 0;
}