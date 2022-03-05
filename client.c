/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:16:52 by vaguilar          #+#    #+#             */
/*   Updated: 2022/03/05 12:16:54 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_send(char *bin, int pid)
{
	int	x;

	x = 0;
	//printf("ft_send \"%s\", PID = %i\n", bin, pid);
	while (bin[x] != '\0')
	{
		if (bin[x] == '1')
		{
			kill (pid, SIGUSR1);
			usleep (1);
			//printf("KILL 1\n");
		}
		else if (bin[x] == '0' )
		{
			kill (pid, SIGUSR2);
			usleep (1);
			//printf("KILL 0\n");
		}
		x++;
	}
	//printf("Retornando\n");
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
	//printf("BIN == %s\n", bin);
	//printf("PID binary == %i\n", pid);
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
		//printf("Comprobando PID %i\n", pid);
		start = start / 2;
		x++;
	}
	//printf("Comprobando PID %i\n", pid);
	//printf("VALOR DE X == %i\n", x);
	bin[x] = '\0';
	//printf("PID ANTES DE ENVIAR == %i\n", pid);
	printf("BIN LAST == %s, len == %i\n", bin, ft_strlen(bin));

	//ft_send(bin, pid);
	printf("retornando binary\n");
	return (bin);
}

int main(int argc, char **argv)
{
	char *word;
	int	pid;
	int x;
	int	decimal;
	char	*temp;

	x = 0;
	decimal = 0;
	temp = 0;
	pid = ft_atoi(argv[1]);
	word = argv[2];
	//printf ("WORD == %s, PID == %i\n", word, pid);
    /*if (argc != 3)
    {
        printf("Error en numero de argumentos\n");
        return(0);
    }*/
    //printf("Recibiendo %i parametros\n", argc - 1);
    //printf("ARGV[1] (PID) == %s\n", argv[1]);
    //printf("ARGV[2] (STR) == %s\n", argv[2]);

    //kill (ft_atoi(argv[1]), SIGUSR1);
	//kill (ft_atoi(argv[1]), SIGUSR2);

	//printf("WORD == %s y len == %i\n", word, ft_strlen(word));
	while (word[x] != '\0')
	{
		//printf("Valor x en bluce == %i\n", x);
		decimal = (int)*(word + x);
		temp = ft_binary(decimal);
		ft_send(temp, pid);
		//printf("valor de %c en decimal == %i\n", *(argv[2] + x), decimal );
		//printf("temp = %s\n", temp);
		x++;
	}
	//ft_send(temp, pid);
	//printf("Fin\n");
	return (0);

}
