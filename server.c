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

int	ft_decimal (char *bin)
{
	//char ret;
	int decimal;
	int x;
	int total;

	x = 0;
	decimal = 128;
	total = 0;

	while (x < 8)
	{
		//printf("DECIMAL #%i == %d\n", x, total);
		if (bin[x] == '1')
		{
			total = total + decimal;
			//printf("encontre 1 en %i\n", x);
		}
		decimal = decimal / 2;
		x++;
	}
	//printf("\nBIN == %s == %c\n", bin, total);
	write(1, &total, 1);
	total = 0;
	//printf("c %c", (char)total);
	//printf("Decimal v1 == %i\n", total);
	return (0);
}


void	ft_sigusr(int numsig)
{
	static char str[8];
	static int x = 0;

	if (numsig == SIGUSR1)
	{
		//printf("1");
		str[x] = '1';
	}
	else
	{	
		//printf("0");
		str[x] = '0';
	}
	
	if (x == 7)
	{
		//printf("Se gan recibido %i senales\n", x);
		str[x + 1] = '\0'; 
		//printf("STR == %s\n", str);
		//printf("\nBIN == %s == ", str);
		ft_decimal(str);
		x = 0;
	}
	else
	{
		x++;
		//printf("no entro a if\n");
	}

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

	signal (SIGUSR1, ft_sigusr);
	signal (SIGUSR2, ft_sigusr);

	while (1)
	{
		//printf("Esperando senal\n");
		pause ();
		//if (signal (SIGUSR1, ft_sigusr1) || signal (SIGUSR2, ft_sigusr2))
			sig++;
		//printf("r = ");
	}
	//printf("FIN\n");
	return (0);
}
