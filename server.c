/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:17:25 by vaguilar          #+#    #+#             */
/*   Updated: 2022/03/05 12:17:27 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sigusr1(int numsig)
{
	printf("Recibiendo senal SIGUSR1 == 1\n");
}

void	ft_sigusr2(int numsig)
{
	printf("Recibiendo senal SIGUSR2 == 0\n");
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
		printf("Esperando senal\n");
		pause ();
		//if (signal (SIGUSR1, ft_sigusr1) || signal (SIGUSR2, ft_sigusr2))
			sig++;
		//printf("recibido\n");
	}
	return (0);
}
