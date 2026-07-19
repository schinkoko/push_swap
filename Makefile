# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/15 20:55:09 by aschinog          #+#    #+#              #
#    Updated: 2026/07/19 23:40:04 by mtrukhin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CHECKER     = checker

SRCS        = print_utils.c get_next_line.c ops_rot.c main.c chunk_utils.c \
    get_next_line_utils.c other_utils.c set_strategy.c ft_lstops.c \
    parse_args.c sort_algos.c ft_printf.c ops_cmb.c parse_utils.c \
    sort_utils.c ft_split.c ops_ps.c push_swap.c

CHECKER_SRCS = print_utils.c get_next_line.c ops_rot.c chunk_utils.c \
    get_next_line_utils.c other_utils.c set_strategy.c ft_lstops.c \
    parse_args.c ft_printf.c ops_cmb.c parse_utils.c \
    ft_split.c ops_ps.c checker.c push_swap.c sort_algos.c sort_utils.c

OBJS        = $(SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)

CFLAGS      = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

bonus: $(CHECKER)

$(CHECKER): $(CHECKER_OBJS)
	cc $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re