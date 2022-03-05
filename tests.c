/*#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

void manejador(int signum){
switch (signum){
case SIGUSR1:
printf("He recibido la señal SIGUSR1\n");
break;
case SIGUSR2:
printf("He recibido la señal SIGUSR2\n");
break;
case SIGTERM:
printf("Fin de ejecucion\n");
exit(EXIT_SUCCESS);
}
}

int main(int argc, char *argv[])
{
if (signal(SIGUSR1, manejador) == SIG_ERR) {
perror("error en la señal SIGUSR1");
exit(EXIT_FAILURE);
}
if (signal(SIGUSR2, manejador) == SIG_ERR) {
perror("error en la señal SIGUSR2");
exit(EXIT_FAILURE);
}
if (signal(SIGTERM, manejador) == SIG_ERR) {
perror("error en SIGTERM");
exit(EXIT_FAILURE);
}
if (signal(SIGINT, SIG_IGN) == SIG_ERR) {
perror("error en SIGINT");
exit(EXIT_FAILURE);
}

while (1)
pause();
}*/


/* 2 */


/*
 * Javier Abellán. 8 de Abril de 2003
 *
 * Ejemplo de como una proceso puede enviar una señal a otro proceso mediante
 * kill()
 */
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

/* Prototipo de la función para tratamiento de la señal */
void trataSenhal (int);


/* Programa principal.
 * Crea un proceso hijo y le envía una señal SIGUSR1 cada segundo.
 */
int main()
{
	/* Identificador del proceso hijo */
	pid_t idProceso;

	/* Se crea el proceso hijo y se comprueba el error */
	idProceso = fork();

	if (idProceso == -1)
	{
		perror ("No se puede lanzar proceso");
		return (0);
	}

	/* Camino que sigue el proceso hijo.
	 * Pone trataSenhal() para tratar la señal SIGUSR1 y se mete en un bucle
	 * de espera
	 */
	if (idProceso == 0)
	{
		signal (SIGUSR1, trataSenhal);
		while (1)
			pause ();
	}

	/* Camino que sigue el proceso padre.
	 * Cada segundo envía una señal SIGUSR1 a su proceso hijo.
	 */
	if (idProceso > 0)
	{
		while (1)
		{
			sleep (1);
			kill (idProceso, SIGUSR1);
		}
	}
}

/* Función de tratamiento de SIGUSR1.
 * Escribe en pantalla un aviso de que ha llegado la señal.
 */
void trataSenhal (int numeroSenhal)
{
	printf ("Recibida señal del padre\n");
}

