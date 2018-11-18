# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lroux <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 14:23:48 by lroux             #+#    #+#              #
#    Updated: 2018/11/18 15:04:09 by lroux            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
LD		:= gcc
AR		:= ar
RM		:= rm -f

SRCDIR	:= srcs
INCLDIR := includes

CFLAGS	:= -Wall -Wextra -Werror -I$(INCLDIR)
LDFLAGS	:=
ARFLAGS	:= rcs

SRCS	:= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strndup.c \
		   ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
		   ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
		   ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		   ft_isascii.c ft_isprint.c ft_isupper.c ft_islower.c ft_toupper.c \
		   ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
		   ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		   ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
		   ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
		   ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		   ft_putnbr_fd.c ft_calloc.c ft_realloc.c ft_ltostr.c ft_lstnew.c \
		   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		   ft_strnjoin.c ft_strreset.c ft_strjoinfree.c ft_strnjoinfree.c \
		   gnl.c
SRCS	:= $(addprefix $(SRCDIR)/, $(SRCS))
OBJS	:= $(patsubst %.c,%.o,$(SRCS))
DEPS	:= Makefile libft.h
NAME	:= libft.a
SO		:= libft.so

all: $(NAME)

so: $(SO)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(SO): $(OBJS)
	$(LD) $(LDFLAGS) -shared -o $(SO) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(SO)

re: fclean all

.PHONY: all clean fclean so
