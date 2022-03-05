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
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h> // Malloc
# include <time.h> //nanosleep

int	ft_strlen(char *s);

int	ft_atoi(char *str);

char	*ft_binary(int decimal);

int	ft_send(char *bin, int pid);

#endif
