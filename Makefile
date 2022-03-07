SRCS = libft.c

CFLAGS = -Wall -Werror -Wextra
RM = rm -f
OBJS = $(SRCS:.c=.o)
CC = gcc

all: client server

client: printf
	$(CC) client.c -L. -lftprintf $(SRCS) -o client

server: printf
	$(CC) server.c -L. -lftprintf $(SRCS) -o server

bonus: printf
	$(CC) server_bonus.c -L. -lftprintf $(SRCS) -o server
	$(CC) client_bonus.c -L. -lftprintf $(SRCS) -o client

printf:
	${MAKE} -C ./ft_printf all
	cp ./ft_printf/libftprintf.a .

clean:
	${MAKE} -C ./ft_printf clean
	$(RM) $(OBJS) client.o server.o libftprintf.a

fclean: clean
	${MAKE} -C ./ft_printf fclean
	$(RM) client server

re: fclean all

.PHONY: all client server bonus printf clean fclean re