#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h> // Malloc

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
			printf("KILL 1\n");
		}
		else if (bin[x] == '0' )
		{
			kill (pid, SIGUSR2);
			printf("KILL 0\n");
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

	printf("WORD == %s y len == %i\n", word, ft_strlen(word));
	while (word[x] != '\0')
	{
		//printf("Valor x en bluce == %i\n", x);
		decimal = (int)*(word + x);
		temp = ft_binary(decimal);
		//printf("valor de %c en decimal == %i\n", *(argv[2] + x), decimal );
		//printf("temp = %s\n", temp);
		x++;
	}
	ft_send(temp, pid);
	printf("Fin\n");
	return (0);

}