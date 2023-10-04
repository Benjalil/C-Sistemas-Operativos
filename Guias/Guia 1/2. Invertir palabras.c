#include <stdio.h>
#include <string.h>

int main(){
    int tamanho;
    char cadena1[]="casa";
    tamanho=strlen(cadena1);
    
    printf("%s\n",cadena1);

    for (int i = tamanho - 1; i >= 0 ;i-=1)
        {

            char temp = cadena1[i];
            
            printf("%c\a",temp);
        
        }

return 0;
}
