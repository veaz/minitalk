/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:17:02 by vaguilar          #+#    #+#             */
/*   Updated: 2022/03/05 12:17:03 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

int	ft_atoi(const char *str)
{
	int	x;
	int	sig;
	int	num;

	x = 0;
	sig = 1;
	num = 0;
	while (str[x] == ' ' || (str[x] >= '\t' && str[x] <= '\r'))
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			sig = sig * -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
	{
		num = (str[x] - '0') + (num * 10);
		x++;
	}
	return (num * sig);
}
