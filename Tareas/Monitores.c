
//Felipe Rios
//Benjamin Huilitraro
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 10

int tmax = 5, tmin = 1, numh = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void registroEstudiantes(int idpar) {
  pthread_mutex_lock(&mutex);
  while (numh >= 5) {
    pthread_cond_wait(&cond, &mutex);
  }
  numh++;
  pthread_mutex_unlock(&mutex);

  printf("El estudiante %d se está registrando\n", idpar);
  usleep((1000000 * (rand() % (tmax - tmin + 1) + tmin)));
  printf("El estudiante %d ya se registró\n", idpar);

  pthread_mutex_lock(&mutex);
  numh--;
  pthread_cond_broadcast(&cond);
  pthread_mutex_unlock(&mutex);
}

void *participante(void *arg) {
  int idpar = *((int *)arg);
  registroEstudiantes(idpar);
}

int main() {
  pthread_t participantes[N];
  int idpar[N];

  for (int i = 0; i < N; i++) {
    idpar[i] = i + 1;
    pthread_create(&participantes[i], NULL, participante, (void *)&idpar[i]);
  }

  for (int i = 0; i < N; i++) {
    pthread_join(participantes[i], NULL);
  }

  return 0;
}
