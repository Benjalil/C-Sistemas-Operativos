#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>


int ai = 0;
int ad = 0;

sem_t izq_dere, dere_izq;

void *izq_der(void *idc) {
  int *id = (int *)idc;

  printf("Auto %i llegó a la cola del lado izquierdo\n", *id);
  sem_wait(&izq_dere);
  int t = 1 + rand() % 3;
  usleep(1000000 * t);
  ai++;
  printf("Auto %i cruzó de izq a der en %i segundos\n", *id, t);
  sem_post(&izq_dere);
  sem_post(&dere_izq);

  free(id); // Liberar memoria asignada dinámicamente

  return NULL;
}

void *der_izq(void *idc) {
  int *id = (int *)idc;

  printf("Auto %i llegó a la cola del lado derecho\n", *id);
  sem_wait(&dere_izq);
  int t = 1 + rand() % 3;
  usleep(1000000 * t);
  ad++;
  printf("Auto %i cruzó  de der a iz en %i segundos\n", *id, t);

  free(id); // Liberar memoria asignada dinámicamente

  return NULL;
}

int main() {
  printf("Simulación de cruces de autos\n");
  sem_init(&izq_dere, 0, 1);
  sem_init(&dere_izq, 0, 0);

  pthread_t autosiz[5], autosder[5];

  for (int i = 0; i < 5; i++) {
    int *ida = malloc(sizeof(int));
    *ida = i + 1;
    pthread_create(&autosiz[i], NULL, izq_der, (void *)ida);
  }

  for (int i = 0; i < 5; i++) {
    int *ida = malloc(sizeof(int));
    *ida = i + 10;
    pthread_create(&autosder[i], NULL, der_izq, (void *)ida);
  }

  for (int i = 0; i < 5; i++) {
    pthread_join(autosiz[i], NULL);
  }

  for (int i = 0; i < 5; i++) {
    pthread_join(autosder[i], NULL);
  }

  printf("Fin de la simulación\n");
  sem_destroy(&izq_dere);
  sem_destroy(&dere_izq);

  return 0;
}