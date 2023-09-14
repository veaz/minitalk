/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:17:25 by vaguilar          #+#    #+#             */
/*   Updated: 2023/09/14 20:55:37 by vaguilar         ###   ########.fr       */
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

void	ft_sigserver(int numsig, int sig)
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
		kill (sig, SIGUSR1);
	}
	else
		s_st.bit++;
}

void	get_pid(int sig, siginfo_t *info, void *context)
{
	(void)context;
	s_st.signalpid = info->si_pid;
	ft_sigserver(sig, s_st.signalpid);
}

int	main(void)
{
	pid_t	process_id;

	process_id = getpid();
	ft_printf("## B O N U S ##\nThe process id (PID): %d\n", process_id);
	s_st.sa.sa_flags = SA_SIGINFO;
	s_st.sa.sa_sigaction = get_pid;
	sigaction(SIGUSR1, &s_st.sa, NULL);
	sigaction(SIGUSR2, &s_st.sa, NULL);
	pause();
	while (1)
		sleep(10);
	return (0);
}
