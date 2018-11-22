# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2018/11/22 11:23:19 by pscott           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	:= make
CC		:= gcc
LD		:= gcc
AR		:= ar
RM		:= rm -f

SRCDIR	:= srcs
INCLDIR := -I libft/includes -I includes/

CFLAGS	:= -Wall -Wextra -Werror $(INCLDIR)
LDFLAGS	:= -Llibft/ -lft
ARFLAGS	:=

SRCS	:= main.c fill.c utils.c usage.c error.c rcf.c algo.c map.c
SRCS	:= $(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:= $(patsubst %.c,%.o,$(SRCS))
DEPS	:= libft Makefile includes/fillit.h
NAME	:= fillit

all: $(NAME)

libft:
	$(MAKE) -C libft

$(NAME): $(DEPS) $(OBJS)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

comp:
	-./fillit tetris > ours
	-./gguichar tetris > theirs
	diff ours theirs

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft comp
