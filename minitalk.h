/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:17:15 by vaguilar          #+#    #+#             */
/*   Updated: 2022/03/05 12:17:16 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

struct s_st{
	char	str[8];
	int		bit;
} s_st;

int		ft_decimal(char *bin);
void	ft_sigusr(int numsig);
char	*ft_binary(int decimal);
int		ft_send(char *bin, int pid);
int		ft_atoi(char *str);

#endif
