/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:44:11 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/23 16:49:52 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parse_args.h"

static bool	is_flag(char *value, t_stack *push_swap)
{
	if (ft_strcmp(value, BENCH_FLAG) == NO_DIFF)
		push_swap->bench = true;
	else if (
		ft_strcmp(value, SIMPLE_FLAG) == NO_DIFF
		|| ft_strcmp(value, MEDIUM_FLAG) == NO_DIFF
		|| ft_strcmp(value, COMPLEX_FLAG) == NO_DIFF
		|| ft_strcmp(value, ADAPTIVE_FLAG) == NO_DIFF
	)
	{
		if (push_swap->required_algo != ALGO_NONE)
			return (false);
		if (ft_strcmp(value, SIMPLE_FLAG) == NO_DIFF)
			push_swap->required_algo = ALGO_SIMPLE;
		else if (ft_strcmp(value, MEDIUM_FLAG) == NO_DIFF)
			push_swap->required_algo = ALGO_MEDIUM;
		else if (ft_strcmp(value, COMPLEX_FLAG) == NO_DIFF)
			push_swap->required_algo = ALGO_COMPLEX;
		else
			push_swap->required_algo = ALGO_ADAPTIVE;
	}
	else
		return (false);
	return (true);
}

static bool	is_numerical(char *value)
{
	if (*value == '-' || *value == '+')
		++value;
	if (!*value)
		return (false);
	while (*value)
	{
		if (!(*value >= '0' && *value <= '9'))
			return (false);
		++value;
	}
	return (true);
}

static bool	is_valid_args(char **values, t_stack *push_swap)
{
	while (*values)
	{
		if (!(is_numerical(*values) || is_flag(*values, push_swap)))
			return (false);
		++values;
	}
	return (true);
}

static bool	clean_up(char **values)
{
	size_t	i;

	i = 0;
	while (values[i])
		free(values[i++]);
	free(values);
	stack_clean();  // TODO: Implement
	ft_printf(stderr, PS_ERROR_MSG);
	return (false);
}

bool	fill_stack(int argc, const char **argv, t_stack *push_swap)
{
	size_t	i;
	long	num;
	char	**values;

	while (argc-- > 1)
	{
		values = ft_split(argv[argc], SPACE_DELIMETER);
		i = ft_len(values);
		if (!is_valid_args(values, push_swap))
			return (clean_up(values));
		while (i)
		{
			if (is_numerical(values[--i]))
			{
				num = ft_atol(values[i]);
				if (!(num >= INT_MIN && num <= INT_MAX)
					|| !add_to_stack(&push_swap->a, new_node(num)))  // TODO: Implement
					return (clean_up(values));
			}
			free(values[i]);
			values[i] = NULL;
		}
		free(values);
	}
	return (true);
}

int	parse_args(int argc, char **argv)
{
	t_stack	push_swap;

	push_swap.a = new_stack();  // TODO: Implement
	push_swap.required_algo = ALGO_NONE;
	push_swap.bench = false;
	if (!fill_stack(argc, argv, &push_swap))
		return (1);
	set_strategy(&push_swap);
	return (0);
}
