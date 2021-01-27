# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cilla <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/02 14:54:03 by cilla             #+#    #+#              #
#    Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./srcs/function1.c ./srcs/function2.c ./srcs/main.c ./srcs/ft_check_instructions.c ./srcs/ft_optimisations.c ./srcs/ft_start.c ./srcs/ft_board.c

OBJS	= ${SRCS:.c=.o}
	
INCS	= includes

NAME	= BSQ

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAFS} -c $< -o ${<:.c=.o} -I${INCS}

${NAME}:	${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

norm :
	norminette -R CheckForbiddenSourceHeader */*.[ch]

re : fclean all


.PHONY: all clean fclean re .c.o
