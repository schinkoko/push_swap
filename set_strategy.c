/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_strategy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:25:20 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/28 05:06:32 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	value_at_index(t_list *lst, int i)
{
	while (i-- && lst)
		lst = lst->next;
	if (!lst)
		return (0);
	return (lst->value);
}

static double	measure_disorder(t_list *a)
{
	int		i;
	int		j;
	int		total_pairs;
	double	mistakes;
	int		lst_size;

	lst_size = ft_lstsize(a);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	if (lst_size <= 1)
		return (0.0);
	while (i < lst_size)
	{
		j = i + 1;
		while (j < lst_size)
		{
			if (value_at_index(a, i) > value_at_index(a, j))
				++mistakes;
			++total_pairs;
			++j;
		}
		++i;
	}
	return (mistakes / total_pairs);
}

static char	*choose_adaptive_complexity(t_stack *ps, double disorder)
{
	if (disorder < DISORDER_SIMPLE)
	{
		ps->algo = ALGO_SIMPLE;
		return (SIMPLE_COMPLEXITY);
	}
	else if (disorder < DISORDER_MEDIUM)
	{
		ps->algo = ALGO_MEDIUM;
		return (MEDIUM_COMPLEXITY);
	}
	ps->algo = ALGO_COMPLEX;
	return (COMPLEX_COMPLEXITY);
}

void	set_strategy(t_stack *ps)
{
	ps->disorder = measure_disorder(ps->a);
	if (ps->algo == ALGO_SIMPLE)
	{
		ps->strategy = SIMPLE_STRATEGY;
		ps->complexity = SIMPLE_COMPLEXITY;
	}
	else if (ps->algo == ALGO_MEDIUM)
	{
		ps->strategy = MEDIUM_STRATEGY;
		ps->complexity = MEDIUM_COMPLEXITY;
	}
	else if (ps->algo == ALGO_COMPLEX)
	{
		ps->strategy = COMPLEX_STRATEGY;
		ps->complexity = COMPLEX_COMPLEXITY;
	}
	else
	{
		ps->strategy = ADAPTIVE_STRATEGY;
		ps->complexity = choose_adaptive_complexity(ps, ps->disorder);
	}
}

bool	add_to_stack(t_stack *ps, const char *value)
{
	long	num;

	if (is_numerical(value))
		return (
			ft_atol(value, &num)
			&& num >= INT_MIN && num <= INT_MAX
			&& ft_lstadd_front(&ps->a, ft_lstnew((int)num))
		);
	return (true);
}
