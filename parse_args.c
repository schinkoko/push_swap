/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 21:44:11 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/20 22:26:56 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parse_args.h"

static bool	is_numerical(char *value)
{
	if (*value == '-')
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

static bool	if_valid_args(char **values)
{
	while (*values)
	{
		if (!(
				ft_strcmp(*values, SIMPLE_FLAG) == NO_DIFF
				|| ft_strcmp(*values, MEDIUM_FLAG) == NO_DIFF
				|| ft_strcmp(*values, COMPLEX_FLAG) == NO_DIFF
				|| ft_strcmp(*values, ADAPTIVE_FLAG) == NO_DIFF
				|| ft_strcmp(*values, BENCH_FLAG) == NO_DIFF
				|| is_numerical(*values)
			))
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
	ft_printf(ERROR_MESSAGE);
	return (false);
}

static bool	fill_stack(int argc, const char **argv, t_stack *algo)
{
	size_t	i;
	long	num;
	char	**values;

	while (argc-- > 1)
	{
		values = ft_split(argv[argc], SPACE_DELIMETER);
		i = ft_len(values);
		if (!if_valid_args(values))
			return (clean_up(values));
		while (i)
		{
			if (is_numerical(values[--i]))
			{
				num = ft_atol(values[i]);
				if (!(num >= INT_MIN && num <= INT_MAX)
					|| !add(&algo->a, new_node(num)))
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
	t_stack	algo;

	algo.a = new_stack();  // TODO: Implement
	if (!fill_stack(argc, argv, &algo))
		return (1);
	set_settings(argv, &algo);
	return (0);
}
