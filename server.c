/*#include <signal.h> //Senales
#include <stdio.h> //Printf, delete pls sr*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void	ft_sigusr1(int numsig)
{
	printf("Recibiendo senal SIGUSR1 == 0\n");
}

void	ft_sigusr2(int numsig)
{
	printf("Recibiendo senal SIGUSR2 == 1\n");
}

int main(void)
{
	static int sig;
	pid_t process_id;
	//pid_t p_process_id;

	sig = 0;
	process_id = getpid(); //ID del proceso principal PID
	//p_process_id = getppid(); //Parent PID

	printf("The process id (PID): %d\n",process_id);
	//printf("The process id of parent function (PPID): %d\n",p_process_id);

	signal (SIGUSR1, ft_sigusr1);
	signal (SIGUSR2, ft_sigusr2);

	while (1)
	{
		printf("Esperando senal, se han recibido %i\n", sig);
		pause ();
		printf("recibido\n");
	}
	return (0);
}