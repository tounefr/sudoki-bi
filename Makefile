##
## Makefile for  in /home/thomas/Documents/epitech/sudoki-bi
## 
## Made by Thomas HENON
## Login   <thomas.henon@epitech.net>
## 
## Started on  Sun Feb 28 15:44:15 2016 Thomas HENON
## Last update Sun Feb 28 16:23:16 2016 Thomas HENON
##

CC	= gcc

NAME	= sudoki-bi

RM	= rm -f

CFLAGS	= -W -Wall

SRCS	=	clean.c \
		display.c \
		linkedlists.c \
		load_map.c \
		main.c \
		parsing.c \
		resolv_sudoku.c \
		util.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
