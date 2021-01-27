# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cilla <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 15:22:51 by cilla             #+#    #+#              #
#    Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
ft_isalnum.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isalpha.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_strlen.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strnstr.c \
ft_calloc.c \
ft_strdup.c \
ft_strmapi.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_itoa.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putnbr_fd.c \
ft_putendl_fd.c \
ft_split.c

OBJS = $(SRCS:.c=.o)

RM = rm -f
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror
INCS = .

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) -f $(OBJS)

re: fclean all

.PHONY: all clean fclean re .c.o
