# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2018/11/20 15:57:58 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	:= make
CC		:= gcc
LD		:= gcc
AR		:= ar
RM		:= rm -f

SRCDIR	:= .
INCLDIR := -I libft/includes

CFLAGS	:= -Wall -Wextra -Werror $(INCLDIR)
LDFLAGS	:= -Llibft/ -lft
ARFLAGS	:=

SRCS	:= main.c fill.c utils.c usage.c error.c rcf.c
SRCS	:= $(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:= $(patsubst %.c,%.o,$(SRCS))
DEPS	:= libft Makefile fillit.h
NAME	:= fillit

all: $(DEPS) $(NAME)

libft:
	$(MAKE) -C libft

$(NAME): $(OBJS)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean libft
