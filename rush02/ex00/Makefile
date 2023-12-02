NAME = rush-02

MY_SOURCES = dictreader.c input.c lib2.c lib.c parsing.c main.c printer2.c printer.c recursive.c split.c

HEADERS= header.h

MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = cc -Wall -Wextra -Werror

CUR_DIR = $(shell pwd)

all:	$(NAME)

$(NAME): $(MY_OBJECTS)
	$(CC) -o $(NAME) $(MY_OBJECTS)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(MY_OBJECTS)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
