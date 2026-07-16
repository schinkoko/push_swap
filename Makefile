# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/15 20:55:09 by aschinog          #+#    #+#              #
#    Updated: 2026/07/16 23:48:40 by aschinog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = bench.c chunk_sort.c ft_lstops.c ft_printf.c ft_split.c math_utils.c \
ops_cmb.c ops_ps.c ops_rot.c parse_args.c parse_utils.c presort.c \
print_utils.c push_swap.c selection_sort.c set_strategy.c sort_utils.c
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
