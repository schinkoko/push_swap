/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:44:11 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/30 16:50:55 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_flag(char *value, t_stack *ps)
{
	if (ft_strcmp(value, BENCH_FLAG) == NO_DIFF)
		ps->bench = true;
	else if (
		ft_strcmp(value, SIMPLE_FLAG) == NO_DIFF
		|| ft_strcmp(value, MEDIUM_FLAG) == NO_DIFF
		|| ft_strcmp(value, COMPLEX_FLAG) == NO_DIFF
		|| ft_strcmp(value, ADAPTIVE_FLAG) == NO_DIFF
	)
	{
		if (ps->algo != ALGO_NONE)
			return (false);
		if (ft_strcmp(value, SIMPLE_FLAG) == NO_DIFF)
			ps->algo = ALGO_SIMPLE;
		else if (ft_strcmp(value, MEDIUM_FLAG) == NO_DIFF)
			ps->algo = ALGO_MEDIUM;
		else if (ft_strcmp(value, COMPLEX_FLAG) == NO_DIFF)
			ps->algo = ALGO_COMPLEX;
		else
			ps->algo = ALGO_ADAPTIVE;
	}
	else
		return (false);
	return (true);
}

bool	is_numerical(const char *value)
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

static bool	is_valid_args(char **values, t_stack *ps)
{
	if (!values)
		return (false);
	while (*values)
	{
		if (!(is_numerical(*values) || is_flag(*values, ps)))
			return (false);
		++values;
	}
	return (true);
}

bool	clean_up(char **values, t_stack *ps)
{
	size_t	i;

	i = 0;
	while (values && values[i])
		free(values[i++]);
	free(values);
	ft_lstclear(&ps->a);
	ft_lstclear(&ps->b);
	ft_printf(STDERR_FILENO, PS_ERROR_MSG);
	return (false);
}

bool	fill_stack(int argc, char **argv, t_stack *ps)
{
	size_t	i;
	char	**values;

	values = NULL;
	while (argc-- > 1)
	{
		if (is_empty_argument(argv[argc]))
			return (clean_up(values, ps));
		values = ft_split(argv[argc], SPACE_DELIMETER);
		if (!values)
			return (clean_up(NULL, ps));
		i = ft_arrlen(values);
		if (!is_valid_args(values, ps))
			return (clean_up(values, ps));
		while (i)
		{
			if (!add_to_stack(ps, values[--i]))
				return (clean_up(values, ps));
			free(values[i]);
			values[i] = NULL;
		}
		free(values);
		values = NULL;
	}
	return (true);
}
