SRCS = libft.c

CFLAGS = -Wall -Werror -Wextra
RM = rm -f
OBJS = $(SRCS:.c=.o)
CC = gcc

all: client server

client:
	${MAKE} -C ./ft_printf all
	cp ./ft_printf/libftprintf.a client
	$(CC) client.c -L. -lftprintf $(SRCS) -o client

server:
	${MAKE} -C ./ft_printf all
	cp ./ft_printf/libftprintf.a server
	$(CC) server.c -L. -lftprintf $(SRCS) -o server

clean:
	${MAKE} -C ./ft_printf clean
	$(RM) $(OBJS) client.o server.o

fclean: clean
	${MAKE} -C ./ft_printf fclean
	$(RM) client server

re: fclean all

.PHONY: all clean fclean re