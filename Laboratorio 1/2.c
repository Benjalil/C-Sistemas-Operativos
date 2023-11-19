#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


int np=0;
int pista1=0;
int pista2=0;
int meta=0;
pthread_barrier_t partida,fase1,fase2;

pthread_mutex_t correr;

void* carrera(void*(idc))
{
  int id = *((int*)idc);
  
  
  if (id==1)
  {
  printf("Corredor A esta listo para comenzar \n");
    pthread_mutex_lock(&correr);
  pista1++;
    pthread_mutex_unlock(&correr);
  printf("Corredor A alcanzo el primer checkpoint \n");
  }
  else if (id==2)
  {
    printf("Corredor B esta listo para comenzar \n");
      pthread_mutex_lock(&correr);
    pista1++;
      pthread_mutex_unlock(&correr);
    printf("Corredor B alcanzo el primer checkpoint \n");
  }
  else if (id==3)
  {
    printf("Corredor C esta listo para comenzar \n");
      pthread_mutex_lock(&correr);
    pista1++;
      pthread_mutex_unlock(&correr);
    printf("Corredor C alcanzo el primer checkpoint \n");
  }

  pthread_barrier_wait(&fase1);


  if (id==1)
  {
  printf("Corredor A esta listo para comenzar el 2do tramo \n");
    pthread_mutex_lock(&correr);
  pista2++;
    pthread_mutex_unlock(&correr);
  printf("Corredor A alcanzo el segundo checkpoint \n");
  }
  else if (id==2)
  {
    printf("Corredor B esta listo para comenzar el segundo tramo\n");
      pthread_mutex_lock(&correr);
    pista2++;
      pthread_mutex_unlock(&correr);
    printf("Corredor B alcanzo el segundo checkpoint \n");
  }
  else if (id==3)
  {
    printf("Corredor C esta listo para comenzar el segundo tramo\n");
      pthread_mutex_lock(&correr);
    pista2++;
      pthread_mutex_unlock(&correr);
    printf("Corredor C alcanzo el segundo checkpoint \n");
  }


  pthread_barrier_wait(&fase2);
  
  if (id==1)
  {
  printf("Corredor A esta listo para comenzar el 3er tramo \n");
    pthread_mutex_lock(&correr);
  meta++;
    pthread_mutex_unlock(&correr);
  printf("Corredor A alcanzo la meta \n");
  }
  else if (id==2)
  {
    printf("Corredor B esta listo para comenzar 3er tramo\n");
      pthread_mutex_lock(&correr);
    meta++;
      pthread_mutex_unlock(&correr);
    printf("Corredor B alcanzo la meta \n");
  }
  else if (id==3)
  {
    printf("Corredor C esta listo para comenzar el 3er tramo\n");
      pthread_mutex_lock(&correr);
    meta++;
      pthread_mutex_unlock(&correr);
    printf("Corredor C alcanzo la meta \n");
  }


  



  
  
  return NULL;
}



int main()
{

  pthread_t A,B,C;

  int a=1;
  int b=2;
  int c=3;

  pthread_barrier_init(&fase1,NULL,3);
  pthread_barrier_init(&fase2,NULL,3);
  
  pthread_create(&A,NULL,carrera,(int*)&a);

  pthread_create(&B,NULL,carrera,(int*)&b);
  pthread_create(&C,NULL,carrera,(int*)&c);
  

pthread_join(A,NULL);
pthread_join(B,NULL);
pthread_join(C,NULL);

pthread_barrier_destroy(&fase1);
pthread_barrier_destroy(&fase2);
  return 0;
}
