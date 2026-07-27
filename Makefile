# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/15 20:55:09 by aschinog          #+#    #+#              #
#    Updated: 2026/07/27 22:50:40 by mtrukhin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECKER			= checker

SRCS			= chunk_utils.c ft_lstops.c ft_printf.c ft_split.c \
	get_next_line.c get_next_line_utils.c ops_cmb.c ops_ps.c ops_rot.c \
	other_utils.c parse_args.c parse_utils.c parse_utils2.c print_utils.c push_swap.c \
	set_strategy.c sort_algos.c sort_utils.c

CHECKER_SRCS	= checker.c chunk_utils.c ft_lstops.c ft_printf.c ft_split.c \
	get_next_line.c get_next_line_utils.c ops_cmb.c ops_ps.c ops_rot.c \
	other_utils.c parse_args.c parse_utils.c parse_utils2.c print_utils.c set_strategy.c \
	sort_algos.c sort_utils.c

OBJS			= $(SRCS:.c=.o)
CHECKER_OBJS	= $(CHECKER_SRCS:.c=.o)

CFLAGS			= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $<

bonus: $(CHECKER)

redo:
	make all
	make bonus
	make clean
	clear

$(CHECKER): $(CHECKER_OBJS)
	cc $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS)

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re