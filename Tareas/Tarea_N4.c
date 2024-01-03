
//Felipe Ignacio Rios
//Benjamin Alejandro Huilitraro
//Ilan Camilo Vargas
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5

char tuneles[] = "ABCDE";
int id_tunel1 = 0;
int id_tunel2 = 0;
pthread_mutex_t mutex;
pthread_cond_t condac, condbc, conded;
volatile int esAmbulancia = 0;

int ac = 0, bc = 0, ed = 0;
int pip[2], pips[2], pipv[2],pipesta[2];

void Ambulancias(int signo) {
  if (signo == SIGUSR1) {
    esAmbulancia = 1;
  }
}

void *monitor() {
  int idt, ids, idv;

  read(pip[0], &idt, sizeof(idt));
  read(pips[0], &ids, sizeof(ids));
  read(pipv[0], &idv, sizeof(idv));

  if (idt == 0) {
    pthread_mutex_lock(&mutex);
    if (ac == 0) {

      ac = 1;
      sleep(rand() % 3 + 1);
      ac = 0;
      pthread_mutex_unlock(&mutex);
      pthread_cond_signal(&condac);
    }
    pthread_mutex_lock(&mutex);
    while (ac == 1) {

      pthread_cond_wait(&condac, &mutex);
    }
    printf("Monitor Autoriza Acceso al vehiculo %i \n", idv);
    pthread_mutex_unlock(&mutex);

  }

  else if (idt == 1) {
    pthread_mutex_lock(&mutex);
    if (bc == 0) {

      bc = 1;
      sleep(rand() % 3 + 1);
      bc = 0;
      pthread_mutex_unlock(&mutex);
      pthread_cond_signal(&condbc);
    }
    pthread_mutex_lock(&mutex);
    while (bc == 1) {

      pthread_cond_wait(&condbc, &mutex);
    }
    printf("Monitor Autoriza Acceso al vehiculo %i \n", idv);
    pthread_mutex_unlock(&mutex);

  }

  else if (idt == 2 && ids == 0) {
    pthread_mutex_lock(&mutex);
    if (ac == 0) {

      ac = 1;
      sleep(rand() % 3 + 1);
      ac = 0;
      pthread_mutex_unlock(&mutex);
      pthread_cond_signal(&condac);
    }
    pthread_mutex_lock(&mutex);
    while (ac == 1) {

      pthread_cond_wait(&condac, &mutex);
    }
    printf("Monitor Autoriza Acceso al vehiculo %i \n", idv);
    pthread_mutex_unlock(&mutex);
  }

  else if (idt == 2 && ids == 1) {
    pthread_mutex_lock(&mutex);
    if (bc == 0) {

      bc = 1;
      sleep(rand() % 3 + 1);
      bc = 0;
      pthread_mutex_unlock(&mutex);
      pthread_cond_signal(&condbc);
    }
    pthread_mutex_lock(&mutex);
    while (bc == 1) {

      pthread_cond_wait(&condbc, &mutex);
    }
    printf("Monitor Autoriza Acceso al vehiculo %i \n", idv);
    pthread_mutex_unlock(&mutex);
  }

  else if (idt == 3) {
    pthread_mutex_lock(&mutex);
    if (ed == 0) {

      ed = 1;
      sleep(rand() % 3 + 1);
      ed = 0;
      pthread_mutex_unlock(&mutex);
      pthread_cond_signal(&conded);
    }
    pthread_mutex_lock(&mutex);
    while (bc == 1) {

      pthread_cond_wait(&conded, &mutex);
    }
    printf("Monitor Autoriza Acceso al vehiculo %i \n", idv);
    pthread_mutex_unlock(&mutex);
  }

  else if (idt == 4) {
    pthread_mutex_lock(&mutex);
    if (ed == 0) {

      ed = 1;
      sleep(rand() % 3 + 1);
      ed = 0;
      pthread_mutex_unlock(&mutex);
      pthread_cond_signal(&conded);
    }
    pthread_mutex_lock(&mutex);
    while (bc == 1) {

      pthread_cond_wait(&conded, &mutex);
    }
    printf("Monitor Autoriza Acceso al vehiculo %i \n", idv);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}





void *tunelOcupado(void *arg) {
  int id = *(int *)arg;

  int identrada = id_tunel1;
  write(pipesta[1], &identrada, sizeof(identrada));

  int idsalida = id_tunel2;
  write(pipesta[1], &idsalida, sizeof(idsalida));

  if (esAmbulancia) {
    printf("El vehículo %d tiene prioridad, es una ambulancia\n", id);
    esAmbulancia = 0;
  }

  printf("El vehículo %d va a entrar al túnel %c\n", id, tuneles[identrada]);

  write(pip[1], &identrada, sizeof(identrada));
  write(pips[1], &idsalida, sizeof(idsalida));
  write(pipv[1], &id, sizeof(id));

  monitor();

  printf("El vehículo %d ha entrado al túnel %c\n", id, tuneles[identrada]);
  printf("El vehículo %d ha salido del túnel %c\n", id, tuneles[idsalida]);

  return NULL;
}

int num_aleatorio() { return rand() % 5; }

int num_ambulancia() { return rand() % 2; }

int main() {
  pipe(pip);
  pipe(pips);
  pipe(pipv);
  pipe(pipesta);
  pthread_t vehiculos[N];
  int ids_vehiculos[N];
  struct sigaction sa;
  sa.sa_handler = Ambulancias;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  signal(SIGUSR1, Ambulancias);
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&condac, NULL);
  pthread_cond_init(&condbc, NULL);
  pthread_cond_init(&conded, NULL);

  srand((unsigned int)time(NULL));

  for (int i = 0; i < N; i++) {
    ids_vehiculos[i] = i + 1;

    if (num_ambulancia() == 1) {
      kill(getpid(), SIGUSR1);
    }

    pthread_create(&vehiculos[i], NULL, tunelOcupado,
                   (void *)&ids_vehiculos[i]);

    int aleatorio = num_aleatorio();

    if (aleatorio == 0) {
      id_tunel1 = 0;
      id_tunel2 = 2;
    } else if (aleatorio == 1) {
      id_tunel1 = 1;
      id_tunel2 = 2;
    } else if (aleatorio == 2) {
      id_tunel1 = 2;
      id_tunel2 = rand() % 2;
    } else if (aleatorio == 3) {
      id_tunel1 = 3;
      id_tunel2 = 4;
    } else if (aleatorio == 4) {
      id_tunel1 = 4;
      id_tunel2 = 3;
    }
  }




  for (int i = 0; i < N; i++) {
    pthread_join(vehiculos[i], NULL);
  }



  close(pipesta[1]);

  int num = 0,na=0,nb=0,nc=0,nd=0,ne=0 ;
  while (read(pipesta[0], &num, sizeof(int)) > 0) {
    if (num==0)
    {
      na++;
    }
    else if (num==1)
    {
      nb++;
    }
    else if (num==2)
    {
      nc++;
    }
    else if (num==3)
    {
      nd++;
    }
    else if (num==4)
    {
      ne++;
    }
  }

  printf("Han ocupado %i vehiculos el Tunel A \n",na);
  printf("Han ocupado %i vehiculos el Tunel B \n",nb);
  printf("Han ocupado %i vehiculos el Tunel C \n",nc);
  printf("Han ocupado %i vehiculos el Tunel D \n",nd);
  printf("Han ocupado %i vehiculos el Tunel E \n",ne);

  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&condac);
  pthread_cond_destroy(&condbc);
  pthread_cond_destroy(&conded);




  return 0;
}
