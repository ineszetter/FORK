/*/
  Universidad Guadalajara LAMAR
  Sistemas Operativos Avanzados
  Maria Inés Calderón Zetter, LIC1759
  07/03/2014
/*/

#include <stdio.h>
#define MAXITER 5

void desplegar(int hijo, int i)
{
printf("Soy el Padre #: %d y mi Hijo es #: %d \n",getppid(),getpid());
printf("Iteracion: %d, PID: %d\n",i,getpid(),hijo);
}

int main(int argc, char **argv)
{
 int tam = atoi(argv[1]);
 int hijo, hijo1, hijo2;
 int i;

//Definimos desde antes el No. maximo de iteraciones.
   for(i=0; i < tam; i++)
      {
       hijo=fork();
      for(i=0; i < MAXITER; i++)
         {
          hijo=fork();
          //En esta parte reservamos la impresion
          if(hijo != 0 && hijo != -1)
            desplegar(hijo,i);
            sleep(3);
         }
      }   
 return(0);
}
