#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N_HILOS 10

int res_h;

void *printhola(void) {
  srand(time(NULL));
  int texto = rand() % 21;
  printf("y retorno %i\n", texto);
  res_h = texto;
}

int main() {
  int arr[10];
  pthread_t hilos[N_HILOS];


  for (int i = 0; i < N_HILOS; i++) {
    sleep(1);
      printf("soy hilo %i\n" , i);
    int resultado = pthread_create(&hilos[i], NULL, printhola, i);
    arr[i] = res_h;
  }

  for (int i = 0; i < N_HILOS; i++) {
    pthread_join(hilos[i], NULL);
  }

  arr[0] = res_h;

  int total = 0;
  for (int i = 0; i < N_HILOS; i++) {
    int temp = arr[i];
    total = temp + total;
  }
  printf("La suma de los numeros entregado por cada hilo es :%i\n", total);
  return 0;
}
