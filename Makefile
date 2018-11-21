# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2018/11/21 18:31:46 by pscott           ###   ########.fr        #
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
