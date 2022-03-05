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

#include "minitalk_bonus.h"

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
			total = total + decimal;
		decimal = decimal / 2;
		x++;
	}
	write(1, &total, 1);
	total = 0;
	return (0);
}

void	ft_sigusr(int numsig)
{
	if (numsig == SIGUSR1)
		s_st.str[s_st.bit] = '1';
	else
		s_st.str[s_st.bit] = '0';
	if (s_st.bit == 7)
	{
		s_st.str[s_st.bit + 1] = '\0';
		ft_decimal(s_st.str);
		s_st.bit = 0;
	}
	else
		s_st.bit++;
}

int	main(void)
{
	pid_t	process_id;

	process_id = getpid();
	ft_printf("The process id (PID): %d\n", process_id);
	signal(SIGUSR1, ft_sigusr);
	signal(SIGUSR2, ft_sigusr);
	while (1)
		sigaction(SIGUSR1);
		//pause ();
	return (0);
}
