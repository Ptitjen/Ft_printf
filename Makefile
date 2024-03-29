# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeulliot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 11:21:49 by jeulliot          #+#    #+#              #
#    Updated: 2022/03/01 11:21:51 by jeulliot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c functions/ft_putchar_fd.c \
			functions/ft_putnbr_fd.c \
			functions/ft_putstr_fd.c \
			functions/ft_put_unsigned_nbr_hexa.c \
			functions/ft_put_unsigned_nbr.c \
			functions/ft_putnbr_point.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	${OBJS}
			ar rc $(NAME) ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c ${LDFLAGS} $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} $(NAME)

re:	fclean all

.PHONY: all clean fclean re