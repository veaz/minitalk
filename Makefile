SRCS = libft.c

CFLAGS = -Wall -Werror -Wextra
RM = rm -f
OBJS = $(SRCS:.c=.o)
CC = gcc

all: client server

client:
	$(CC) client.c $(SRCS) -o client

server:
	$(CC) server.c $(SRCS) -o server

clean:
	$(RM) $(OBJS) client.o server.o

fclean: clean
	$(RM) client server

re: fclean all

.PHONY: all clean fclean re