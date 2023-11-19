#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

int ai=0;
int ad=0;

sem_t izq_dere,dere_izq;



void* izq_der(void*(idc))
{
  int id = *((int*)idc);

  printf("Auto %i llego a la cola del lado izquierdo",id);
  sem_wait(&izq_dere);
  int t= usleep(1000000*((rand()%3-1+1)+1));
  ai++;
  printf("Auto %i cruzo en %i segundos",id,t);
  sem_post(&izq_dere);
  sem_post(&dere_izq);

  return NULL;
}


void* der_izq(void*(idc))
{
  int id = *((int*)idc);

  printf("Auto %i llego a la cola del lado derecho",id);
  sem_wait(&dere_izq);
  int t= usleep(1000000*((rand()%3-1+1)+1));
  ad++;
  printf("Auto %i cruzo en %i segundos",id,t);
  


  return NULL;
}





int main()
{

  printf("Auto ");
  sem_init(&izq_dere,0,1);
  sem_init(&dere_izq,0,0);
  
  pthread_t autosiz[5],autosder[5];


  
for (int i=0;i<5;i++)
  {
    int ida = i+1; pthread_create(&autosiz[i],NULL,izq_der ,(int*)&ida);
    
  }

for (int i=0;i<5;i++)
  {
    int ida = i*6; pthread_create(&autosiz[i],NULL,der_izq,(int*)&ida);

  }


  for (int i=0;i<5;i++)
    {
pthread_join(autosiz[i],NULL);
    }

  for (int i=0;i<5;i++)
    {
pthread_join(autosder[i],NULL);
    }

  printf("Auto ");
  sem_destroy(&izq_dere);
  sem_destroy(&dere_izq);

  return 0;
}