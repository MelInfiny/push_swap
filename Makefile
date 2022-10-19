# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: enolbas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 22:55:08 by enolbas           #+#    #+#              #
#    Updated: 2022/06/30 22:55:12 by enolbas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRCS =	\
	parser.c    \
	finder.c  \
	insert.c  \
	main.c	  \
	move.c 	  \
	sort.c	  \
	order.c   \
	push_op.c \
	rotate_op.c  \
	stack_del.c  \
	stack_init.c \
	swap_op.c

OBJS := ${SRCS:.c=.o}

BSRCS = \
	checker.c    \
	parser.c    \
	stack_del.c  \
	stack_init.c \
	rotate_op.c \
	swap_op.c	\
	push_op.c

BOBJS := ${BSRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

bonus : $(BONUS)

$(NAME): ${OBJS}
	${CC} -o $@ ${OBJS}

checker : $(BOBJS)
	$(CC) -o $@ $(BOBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f ${OBJS} $(BOBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
