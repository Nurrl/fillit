# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2018/11/22 13:48:56 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE	:= make
CC		:= gcc
LD		:= gcc
AR		:= ar
RM		:= rm -f

SRCDIR	:= srcs
INCLDIR := -I libft/includes -I includes/
LIBDIR	:= libft/

CFLAGS	:= -Wall -Wextra -Werror $(INCLDIR)
LDFLAGS	:= -L$(LIBDIR) -lft
ARFLAGS	:=

SRCS	:= main.c fill.c utils.c usage.c error.c rcf.c algo.c map.c
SRCS	:= $(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:= $(patsubst %.c,%.o,$(SRCS))
DEPS	:= Makefile includes/fillit.h
LIB		:= $(LIBDIR)/libft.a
NAME	:= fillit

all: $(NAME)

$(LIB):
	$(MAKE) -C libft/

$(NAME): $(LIB) $(OBJS)
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re comp
