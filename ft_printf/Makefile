# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cilla <cilla@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/17 11:59:55 by cilla             #+#    #+#              #
#    Updated: 2021/01/26 22:42:08 by cilla            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= ft_printf.c \
		ft_handle.c \
		ft_printf_format.c \
		ft_printf_putchar.c \
		ft_printf_flag_init.c \
		ft_printf_is_flag_char.c \
		ft_printf_reg_format.c \
		ft_printf_putstr.c \
		ft_printf_flag_parse.c \
		ft_printf_flag_validator.c \
		ft_printf_flag_handler.c \
		ft_printf_formatter_char.c \
		ft_printf_padder.c \
		ft_dprintf.c \
		ft_printf_format_decimal.c \
		ft_printf_which_unit.c \
		ft_printf_format_empty.c \
		ft_printf_format_octal_int.c \
		ft_printf_format_hex_int.c \
		ft_printf_format_string.c \
		ft_printf_format_uint.c \
		ft_vdprintf.c \
		ft_printf_format_pointer.c \
		ft_printf_format_pourcent.c \
		ft_vprintf.c

OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror
INCS = .
COMPILER = cc

.c.o :
	${COMPILER} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean:
	$(RM) -f $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT)

re: fclean all

bonus: all

.PHONY: all clean fclean re .c.o bonus
