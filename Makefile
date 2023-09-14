CFLAGS = -Wall -Werror -Wextra -I ./srcs/ft_printf/include/ -I ./include
RM = rm -f
OBJS = $(SRCS:.c=.o)
CC = gcc $(CFLAGS)

all: client server
	@echo "\x1b[32mCompilation successful\x1b[0m"

client: printf
	$(CC) ./srcs/client.c -L. -lftprintf ./srcs/libft.c -o client

server: printf
	$(CC) ./srcs/server.c -L. -lftprintf ./srcs/libft.c -o server

bonus: printf
	$(CC) ./bonus/server_bonus.c -L. -lftprintf ./srcs/libft.c -o server
	$(CC) ./bonus/client_bonus.c -L. -lftprintf ./srcs/libft.c -o client
	@echo "\x1b[32mCompilation successful\x1b[0m"

printf:
	${MAKE} -C ./srcs/ft_printf all
	cp ./srcs/ft_printf/libftprintf.a .

clean:
	${MAKE} -C ./srcs/ft_printf clean
	$(RM) $(OBJS) client server libftprintf.a

fclean: clean
	${MAKE} -C ./srcs/ft_printf fclean
	$(RM) client server client_bonus server_bonus

re: fclean all

.PHONY: all client server bonus printf clean fclean re
