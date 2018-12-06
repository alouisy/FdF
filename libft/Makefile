# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alouisy- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/16 10:58:09 by alouisy-          #+#    #+#              #
#    Updated: 2016/12/16 10:58:13 by alouisy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c\
ft_bzero.c\
ft_memcpy.c\
ft_memccpy.c\
ft_memmove.c\
ft_memchr.c\
ft_memcmp.c\
ft_strlen.c\
ft_strdup.c\
ft_strcpy.c\
ft_strncpy.c\
ft_strcat.c\
ft_strncat.c\
ft_strlcat.c\
ft_strchr.c\
ft_strrchr.c\
ft_strstr.c\
ft_strnstr.c\
ft_strcmp.c\
ft_strncmp.c\
ft_atoi.c\
ft_isalpha.c\
ft_isdigit.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_toupper.c\
ft_tolower.c\
ft_memalloc.c\
ft_memdel.c\
ft_strnew.c\
ft_strdel.c\
ft_strclr.c\
ft_striter.c\
ft_striteri.c\
ft_strmap.c\
ft_strmapi.c\
ft_strequ.c\
ft_strnequ.c\
ft_strsub.c\
ft_strjoin.c\
ft_strtrim.c\
ft_strsplit.c\
ft_itoa.c\
ft_putchar.c\
ft_putchar_fd.c\
ft_putstr.c\
ft_putstr_fd.c\
ft_putnbr.c\
ft_putnbr_fd.c\
ft_putendl.c\
ft_putendl_fd.c\
ft_lstnew.c\
ft_lstdelone.c\
ft_lstdel.c\
ft_lstadd.c\
ft_lstiter.c\
ft_lstmap.c\
ft_isspace.c\
ft_isupper.c\
ft_islower.c\
ft_n.c\
ft_sqrt.c\
ft_power.c\
get_next_line.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -c $(SRC) -I includes/.
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\"libft.a\" has been succefully created !"

clean:
	@/bin/rm -f $(OBJ)
	@echo "LIBFT Object files deleted."

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "LIBFT Library deleted."

re: fclean all

.PHONY: clean
