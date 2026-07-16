/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_strategy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:25:20 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/16 21:21:21 by mtrukhin         ###   ########.fr       */
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

static char	*choose_adaptive_strategy(double disorder)
{
	if (disorder < DISORDER_SIMPLE)
		return (SIMPLE_STRATEGY);
	else if (disorder < DISORDER_MEDIUM)
		return (MEDIUM_STRATEGY);
	return (COMPLEX_STRATEGY);
}

void	set_strategy(t_stack *ps)
{
	double	disorder;

	disorder = measure_disorder(ps->a);
	ps->disorder = disorder;
	if (ps->required_algo == ALGO_SIMPLE)
		ps->strategy = SIMPLE_STRATEGY;
	else if (ps->required_algo == ALGO_MEDIUM)
		ps->strategy = MEDIUM_STRATEGY;
	else if (ps->required_algo == ALGO_COMPLEX)
		ps->strategy = COMPLEX_STRATEGY;
	else
		ps->strategy = choose_adaptive_strategy(disorder);
}
