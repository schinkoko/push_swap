/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 20:02:39 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/22 00:18:32 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* INCLUDES */

# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>

/* DEFINES */

# define BUFFER_SIZE 2048
# define MAX_FD 4096

# define DEC_BASE 10
# define HEX_BASE 16
# define DEC "0123456789"
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define PRINTF_ERROR_CODE -1

# define NO_DIFF 0
# define SPACE_DELIMETER ' '

# define DISORDER_SIMPLE 0.2
# define DISORDER_MEDIUM 0.5

# define SIMPLE_STRATEGY "Simple"
# define MEDIUM_STRATEGY "Medium"
# define COMPLEX_STRATEGY "Complex"
# define ADAPTIVE_STRATEGY "Adaptive"

# define SIMPLE_COMPLEXITY "O(n²)"
# define MEDIUM_COMPLEXITY "O(n√n)"
# define COMPLEX_COMPLEXITY "O(n log n)"

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
	const char	*complexity;
	double		disorder;

	t_list		*a;
	t_list		*b;

	size_t		operations[OP_COUNT];
	size_t		total_ops;

	bool		bench;
	t_algo		algo;
}	t_stack;

/* FUNCTION DECLARATIONS */

/* UTILITY FUNCTIONS */

size_t	ft_arrlen(char **arr);
int		ft_strcmp(const char *s1, const char *s2);
long	ft_atol(const char *str);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);

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

/* PRINTF */

int		print_char(int fd, char c);
int		print_str(int fd, const char *str);
int		print_int(int fd, long n);
int		print_ubase(int fd, uintmax_t n, uintmax_t base, const char *alphabet);
int		print_ptr(int fd, void *n);
int		spec_handler(int fd, va_list *lst, const char **str);
int		ft_printf(int fd, const char *str, ...);

/* GET_NEXT_LINE */

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

/* ARGUMENT PARSING */

bool	fill_stack(int argc, char **argv, t_stack *ps);
bool	add_to_stack(t_stack *ps, char **values, char *value);
bool	is_empty_argument(char *s);
bool	is_numerical(char *value);
bool	clean_up(char **values, t_stack *ps);
void	set_strategy(t_stack *ps);
bool	is_sorted(t_list *a);
void	set_ps(t_stack *ps);
void	assign_ranks(t_list *a);
void	print_bench(t_stack *ps);

/* CHUNK SORT UTILITIES */

void	push_all_chunks(t_stack *ps, int chunk_size, int n);
void	pull_all(t_stack *ps);

/* SORTING UTILITIES */

int		find_position(t_list *lst, int target_idx);
void	move_a_to_top(t_stack *ps, int target_idx);
void	move_b_to_top(t_stack *ps, int target_idx);
int		get_max_index(t_list *lst);
int		get_min_index(t_list *lst);

/* SORTING ALGORITHMS */

void	selection_sort(t_stack *ps);
void	chunk_sort(t_stack *ps);
void	radix_sort(t_stack *ps);

#endif
