#include <stdio.h>
int main(){
    
    int ARR[5]={5,2,3,4,1};
    int tamanho= 5;
    for (int i=0; i< tamanho-1; i++)
    {  
        for(int j=i+1; j<tamanho ;j++)
        {
            if (ARR[j] < ARR[i])
            {
                int temp = ARR[i];
                ARR[i] = ARR[j] ;
                ARR[j] =  temp;

            }
        }
    }
    for (int i = 0; i < tamanho; i++) 
    {
        printf("%d ", ARR[i]);
    }

    return 0;
    
}