/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 20:02:39 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 20:59:05 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* INCLUDES */

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

#include <stdio.h>

# include "ft_printf.h"

/* DEFINES */

# define NO_DIFF 0
# define SPACE_DELIMETER ' '

# define DISORDER_SIMPLE 0.2
# define DISORDER_MEDIUM 0.5

# define SIMPLE_STRATEGY "Simple / O(n²)"
# define MEDIUM_STRATEGY "Medium / O(n√n)"
# define COMPLEX_STRATEGY "Complex / O(n log n)"

# define SIMPLE_FLAG "--simple"
# define MEDIUM_FLAG "--medium"
# define COMPLEX_FLAG "--complex"
# define ADAPTIVE_FLAG "--adaptive"
# define BENCH_FLAG "--bench"

# define PS_ERROR_MSG "Error\n"

/* TYPES */

typedef enum e_algo
{
	ALGO_NONE,
	ALGO_SIMPLE,
	ALGO_MEDIUM,
	ALGO_COMPLEX,
	ALGO_ADAPTIVE
}	t_algo;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_op;

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	const char	*strategy;
	double		disorder;

	t_list		*a;
	t_list		*b;

	size_t		operations[OP_COUNT];
	size_t		total_ops;

	bool		bench;
	bool		presort;
	t_algo		required_algo;
}	t_stack;

/* FUNCTION DECLARATIONS */

/* LINKED LIST FUNCTIONS */

int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
bool	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

/* OPERATIONS */

void	sa(t_stack *push_swap);
void	sb(t_stack *push_swap);
void	ss(t_stack *push_swap);
void	pa(t_stack *push_swap);
void	pb(t_stack *push_swap);
void	ra(t_stack *push_swap);
void	rb(t_stack *push_swap);
void	rr(t_stack *push_swap);
void	rra(t_stack *push_swap);
void	rrb(t_stack *push_swap);
void	rrr(t_stack *push_swap);

/* UTILITY FUNCTIONS */

size_t	ft_len(char **arr);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(const char *str);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
void	handle_op(t_stack *push_swap, char *op_name);

/* ARGUMENT PARSING */

void	get_benchmarks(t_stack *push_swap);
bool	fill_stack(int argc, char **argv, t_stack *push_swap);
void	set_strategy(t_stack *push_swap);
int		parse_args(int argc, char **argv, t_stack *push_swap);

#endif
