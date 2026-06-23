# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gerramir <gerramir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/13 17:44:15 by gerramir          #+#    #+#              #
#    Updated: 2026/06/14 16:40:47 by gerramir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I.

SRCS    =   push_swap.c \
            main_parsing.c \
            int_assignations.c \
            initit_free.c \
            bench.c \
            algo/algorythm/fonction_adaptive.c \
            algo/algorythm/fonction_complex.c \
            algo/algorythm/fonction_medium.c \
            algo/algorythm/fonction_simple.c \
            algo/mouvements/mouvement_rev_rotate.c \
            algo/mouvements/mouvement_swap.c \
            algo/mouvements/movement_push.c \
            algo/mouvements/movement_rotate.c \
            utils/lists_management.c \
            utils/utils.c \
            utils/utils1.c \
            utils/utils2.c

OBJS    = $(SRCS:.c=.o)

all:    $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re