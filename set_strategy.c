/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:25:20 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/20 17:03:06 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

static double	measure_disorder(t_node *stack_a, size_t size_a)
{
	int		i;
	int		j;
	int		total_pairs;
	double	mistakes;

	i = 0;
	mistakes = 0;
	total_pairs = 0;
	if (size_a <= 1)
		return (0.0);
	while (i < size_a)
	{
		j = i + 1;
		while (j < size_a)
		{
			if (stack_a[i] > stack_a[j])  // TODO: Adjust to LL
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

void	set_strategy(t_stack *push_swap)
{
	double	disorder;

	disorder = measure_disorder(push_swap->a, push_swap->size_a);
	push_swap->disorder = disorder;
	if (push_swap->required_algo == ALGO_SIMPLE)
		push_swap->strategy = SIMPLE_STRATEGY;
	else if (push_swap->required_algo == ALGO_MEDIUM)
		push_swap->strategy = MEDIUM_STRATEGY;
	else if (push_swap->required_algo == ALGO_COMPLEX)
		push_swap->strategy = COMPLEX_STRATEGY;
	else
		push_swap->strategy = choose_adaptive_strategy(disorder);
}
