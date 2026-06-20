/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:59:11 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/20 16:57:20 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGS_H
# define PARSE_ARGS_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>

# define NO_DIFF 0
# define SPACE_DELIMETER ' '

# define DISORDER_SIMPLE 0.2
# define DISORDER_MEDIUM 0.5

# define SIMPLE_STRATEGY "Simple / O(n²)"
# define MEDIUM_STRATEGY "Medium / O(n√n)"
# define COMPLEX_STRATEGY "O(n log n)"

# define SIMPLE_FLAG "--simple"
# define MEDIUM_FLAG "--medium"
# define COMPLEX_FLAG "--complex"
# define ADAPTIVE_FLAG "--adaptive"
# define BENCH_FLAG "--bench"

# define ERROR_MESSAGE "Error"

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

typedef struct s_stack
{
	const char	*strategy;
	double		disorder;

	t_node		*a;
	t_node		*b;

	size_t		size_a;
	size_t		size_b;

	size_t		operations[OP_COUNT];
	size_t		total_ops;

	bool		bench;
}	t_stack;

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strcmp(const char *s1, const char *s2);
void	set_settings(char **argv, t_stack *algo);
int		parse_args(int argc, char **argv);

#endif
