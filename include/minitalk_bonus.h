/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:17:15 by vaguilar          #+#    #+#             */
/*   Updated: 2023/09/14 20:55:25 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf.h"

struct s_st{
	struct sigaction	sa;
	char				str[8];
	int					bit;
	int					signalpid;
	int					correctsend;
} s_st;

int		ft_decimal(char *bin);
void	ft_sigclient(int numsig);
void	ft_sigserver(int numsig, int sig);
void	get_pid(int sig, siginfo_t *info, void *context);
char	*ft_binary(int decimal);
int		ft_send(char *bin, int pid);
int		ft_atoi(char *str);

#endif
