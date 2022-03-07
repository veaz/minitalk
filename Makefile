SRCS = libft.c

CFLAGS = -Wall -Werror -Wextra
RM = rm -f
OBJS = $(SRCS:.c=.o)
CC = gcc

all: client server bonus

client: printf
	$(CC) client.c -L. -lftprintf $(SRCS) -o client

server: printf
	$(CC) server.c -L. -lftprintf $(SRCS) -o server

bonus: printf
	$(CC) server_bonus.c -L. -lftprintf $(SRCS) -o server_bonus
	$(CC) client_bonus.c -L. -lftprintf $(SRCS) -o client_bonus

printf:
	${MAKE} -C ./ft_printf all
	cp ./ft_printf/libftprintf.a .

clean:
	${MAKE} -C ./ft_printf clean
	$(RM) $(OBJS) client.o server.o server_bonus.o client_bonus.o libftprintf.a

fclean: clean
	${MAKE} -C ./ft_printf fclean
	$(RM) client server client_bonus server_bonus

re: fclean all

.PHONY: all client server bonus printf clean fclean re