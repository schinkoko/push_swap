# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/15 20:55:09 by aschinog          #+#    #+#              #
#    Updated: 2026/07/16 22:12:32 by mtrukhin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
# SRCS = bench.c converters.c ft_lstops.c ft_printf.c ft_split.c ops_cmb.c \
# ops_ps.c ops_rot.c parse_args.c parse_utils.c push_swap.c set_strategy.c

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
