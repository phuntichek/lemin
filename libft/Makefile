# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anastasiaseliseva <anastasiaseliseva@st    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 19:10:52 by fmelda            #+#    #+#              #
#    Updated: 2020/05/27 14:15:34 by anastasiase      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
INCL=includes/
SRCS=ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	ft_strcmp.c ft_strncmp.c \
	ft_isspace.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c \
	ft_itoa.c ft_atoi.c \
	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	ft_lstiter.c ft_lstmap.c ft_swap.c ft_foreach.c ft_putrstr.c ft_sqrt.c get_next_line.c ft_free_arr.c ft_len_arr.c \
	ft_is_number.c ft_realloc.c ft_lstpushback.c convert_float.c crossroads.c do_for_char.c do_for_floats.c do_for_hex.c \
    do_for_int.c do_for_null.c do_for_oct.c do_for_pointer.c do_for_sized_hex.c do_for_sized_int.c do_for_sized_oct.c do_for_sized_u.c \
    do_for_string.c do_for_u_int.c format.c ft_fwrite.c ft_printf.c help_funcs.c init_st.c parse.c ft_l_itoa.c ft_ll_itoa_base.c\
	ft_ll_itoa.c ft_round.c ft_abs.c ft_l_itoa_base.c ft_strnchr.c ft_pow.c

OBJS=ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o \
	ft_memmove.o ft_memchr.o ft_memcmp.o ft_memalloc.o ft_memdel.o \
	ft_strlen.o ft_strdup.o ft_strcpy.o ft_strncpy.o ft_strcat.o ft_strncat.o \
	ft_strlcat.o ft_strchr.o ft_strrchr.o ft_strstr.o ft_strnstr.o \
	ft_strcmp.o ft_strncmp.o \
	ft_isspace.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	ft_toupper.o ft_tolower.o \
	ft_strnew.o ft_strdel.o ft_strclr.o ft_striter.o ft_striteri.o \
	ft_strmap.o ft_strmapi.o ft_strequ.o ft_strnequ.o ft_strsub.o ft_strjoin.o \
	ft_strtrim.o ft_strsplit.o \
	ft_itoa.o ft_atoi.o \
	ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o ft_putchar_fd.o \
	ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o \
	ft_lstnew.o ft_lstdelone.o ft_lstdel.o ft_lstadd.o \
	ft_lstiter.o ft_lstmap.o ft_swap.o ft_foreach.o ft_putrstr.o ft_sqrt.o get_next_line.o ft_free_arr.o ft_len_arr.o \
	ft_is_number.o ft_realloc.o ft_lstpushback.o convert_float.o crossroads.o do_for_char.o do_for_floats.o do_for_hex.o \
    do_for_int.o do_for_null.o do_for_oct.o do_for_pointer.o do_for_sized_hex.o do_for_sized_int.o do_for_sized_oct.o do_for_sized_u.o \
    do_for_string.o do_for_u_int.o format.o ft_fwrite.o ft_printf.o help_funcs.o init_st.o parse.o ft_l_itoa.o ft_ll_itoa_base.o \
	ft_ll_itoa.o ft_round.o ft_abs.o ft_l_itoa_base.o ft_strnchr.o ft_pow.o

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS) -I $(INCL)
	ar rc $(NAME) $(SRC) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
