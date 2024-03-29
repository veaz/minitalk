/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:16:52 by vaguilar          #+#    #+#             */
/*   Updated: 2023/09/14 20:57:01 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_sigclient(int numsig)
{
	(void)numsig;
	s_st.correctsend++;
}

int	ft_send(char *bin, int pid)
{
	int	x;

	x = 0;
	while (bin[x] != '\0')
	{
		if (bin[x] == '1')
		{
			kill (pid, SIGUSR1);
		}
		else if (bin[x] == '0' )
		{
			kill (pid, SIGUSR2);
		}
		usleep(200);
		x++;
	}
	return (0);
}

char	*ft_binary(int decimal)
{
	char	*bin;
	int		start;
	int		x;

	start = 128;
	x = 0;
	bin = (char *)malloc(8 * sizeof(char));
	if (!bin)
		return (0);
	x = 0;
	while (x < 8)
	{
		if (decimal >= start)
		{
			decimal = decimal - start;
			bin[x] = '1';
		}
		else
			bin[x] = '0';
		start = start / 2;
		x++;
	}
	bin[x] = '\0';
	return (bin);
}

int	main(int argc, char **argv)
{
	char	*word;
	int		pid;
	int		x;
	int		decimal;
	char	*temp;

	(void)argc;
	x = 0;
	decimal = 0;
	temp = 0;
	pid = ft_atoi(argv[1]);
	word = argv[2];
	signal(SIGUSR1, &ft_sigclient);
	signal(SIGUSR2, &ft_sigclient);
	while (word[x] != '\0')
	{
		decimal = (int)*(word + x);
		if (decimal < 0)
			decimal += 256;
		temp = ft_binary(decimal);
		ft_send(temp, pid);
		x++;
	}
	ft_printf("Se han enviado %i senales\n", s_st.correctsend);
	return (0);
}
