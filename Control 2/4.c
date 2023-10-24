#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>


int main ()
{
    int n=2,m=2;

    pid_t pid;

  for(int i=0;i<n;i++)
    {
      pid=fork();
      
      if(pid==0)
      {
        printf("Hola mundo\n");
        exit(0);
      }
    }

  for(int i=0;i<m;i++)
    {
      pid=fork();

      if(pid==0)
      {
        printf("Mundo hola\n");
        exit(0);
      }
    }

  
  for(int i=0;i<n;i++)
    {
      wait(NULL);
    }
  for(int i=0;i<m;i++)
    {
      wait(NULL);
    }
  
}