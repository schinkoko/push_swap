/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 20:02:39 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 23:43:54 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* INCLUDES */

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

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

void	sa(t_stack *ps);
void	sb(t_stack *ps);
void	ss(t_stack *ps);
void	pa(t_stack *ps);
void	pb(t_stack *ps);
void	ra(t_stack *ps);
void	rb(t_stack *ps);
void	rr(t_stack *ps);
void	rra(t_stack *ps);
void	rrb(t_stack *ps);
void	rrr(t_stack *ps);

/* UTILITY FUNCTIONS */

size_t	ft_len(char **arr);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(const char *str);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		ft_sqrt(int n);

/* ARGUMENT PARSING */

void	get_benchmarks(t_stack *ps);
bool	fill_stack(int argc, char **argv, t_stack *ps);
void	set_strategy(t_stack *ps);
int		parse_args(int argc, char **argv, t_stack *ps);

/* SORTING UTILITIES */

void	assign_ranks(t_list *a);
int		value_at_index(t_list *lst, int i);
int		find_position(t_list *lst, int target_idx);
void	move_a_to_top(t_stack *ps, int target_idx);
void	move_b_to_top(t_stack *ps, int target_idx);
int		get_max_index(t_list *lst);
int		get_min_index(t_list *lst);

/* SELECTION SORT */

void	selection_sort(t_stack *ps);

/* CHUNK SORT */

void	chunk_sort(t_stack *ps);

#endif
