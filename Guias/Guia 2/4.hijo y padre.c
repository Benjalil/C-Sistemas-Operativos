#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>
#include <stdlib.h>

#define NUM_H 50

int main(void) {
    pid_t pidC;
    double sum = 0;

    printf("Hola soy el proceso padre PID = %d\n", getpid());

    int fd[50]; // Tubería para comunicación entre procesos
    if (pipe(fd) == -1) 
    {
        perror("pipe");
        exit(1);
    }

    for (int i = 0; i < NUM_H; i++) 
    {
        pidC = fork();
        clock_t inicio = clock();
        if (pidC < 0) 
        {
            perror("fork");
            exit(1);
        } else if (pidC == 0) {
            clock_t fin = clock(); 
 
            double tiempo_hijo = (double)(fin - inicio) / CLOCKS_PER_SEC;
            printf("Soy el proceso hijo numero = %i, mi pid es= %d , y demore %f segundos en ser creado\n",i,getpid(),tiempo_hijo);
            // Escribir el tiempo en la tubería
            write(fd[1], &tiempo_hijo, sizeof(double));
            
            close(fd[1]);
            exit(0);
        }
    }

    // Esperar a que los procesos hijos terminen
    for (int i = 0; i < NUM_H; i++) {
        wait(NULL);
    }

    close(fd[1]); // Cerrar el extremo de escritura de la tubería en el proceso padre

    double tiempo_hijo;
    while (read(fd[0], &tiempo_hijo, sizeof(double)) > 0) {
        sum += tiempo_hijo;
    }

    sum=sum/50;
    printf("Tiempo medio en la creación de cada uno de estos procesos.: %f\n segundos", sum);

    return 0;
}
