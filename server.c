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

int	ft_decimal(char *bin)
{
	int	decimal;
	int	x;
	int	total;

	x = 0;
	decimal = 128;
	total = 0;
	while (x < 8)
	{
		if (bin[x] == '1')
		{
			total = total + decimal;
		}
		decimal = decimal / 2;
		x++;
	}
	write(1, &total, 1);
	total = 0;
	return (0);
}

void	ft_sigusr(int numsig)
{
	static char	str[8];
	static int	x = 0;

	if (numsig == SIGUSR1)
	{
		str[x] = '1';
	}
	else
	{	
		str[x] = '0';
	}
	if (x == 7)
	{
		str[x + 1] = '\0';
		ft_decimal(str);
		x = 0;
	}
	else
		x++;
}

int	main(void)
{
	pid_t	process_id;

	process_id = getpid();
	ft_printf("The process id (PID): %d\n", process_id);
	signal (SIGUSR1, ft_sigusr);
	signal (SIGUSR2, ft_sigusr);
	while (1)
		pause ();
	return (0);
}
