#include <stdio.h>

int main ()
{
    int ARR[5]={5,2,3,4,1};
    int tamanho= 5;
    int i= 0;
    while (i < tamanho-1)
    {
        int j=i+1;
        while (j < tamanho)
        {

         if (ARR[j]< ARR[i])
         {
            int temp= ARR[i];
            ARR[i]=ARR[j];
            ARR[j]=temp;
           
         }
        ++j;
        }
    ++i;
    }
for (int i = 0; i < tamanho; i++) 
    {
        printf("%d ", ARR[i]);
    }
return 0;

 