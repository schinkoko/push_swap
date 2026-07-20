# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/15 20:55:09 by aschinog          #+#    #+#              #
#    Updated: 2026/07/20 19:11:23 by aschinog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CHECKER			= checker

SRCS			= chunk_utils.c ft_lstops.c ft_printf.c ft_split.c \
	get_next_line.c get_next_line_utils.c ops_cmb.c ops_ps.c ops_rot.c \
	other_utils.c parse_args.c parse_utils.c print_utils.c push_swap.c \
	set_strategy.c sort_algos.c sort_utils.c

CHECKER_SRCS	= checker.c chunk_utils.c ft_lstops.c ft_printf.c ft_split.c \
	get_next_line.c get_next_line_utils.c ops_cmb.c ops_ps.c ops_rot.c \
	other_utils.c parse_args.c parse_utils.c print_utils.c set_strategy.c \
	sort_algos.c sort_utils.c

OBJS			= $(SRCS:.c=.o)
CHECKER_OBJS	= $(CHECKER_SRCS:.c=.o)

CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c -o $@ $<

bonus: $(CHECKER)

$(CHECKER): $(CHECKER_OBJS)
	cc $(CFLAGS) -o $(CHECKER) $(CHECKER_OBJS)

clean:
	rm -f $(OBJS) $(CHECKER_OBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re