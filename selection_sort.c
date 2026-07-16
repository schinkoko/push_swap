/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:21:44 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 23:43:31 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack *ps)
{
	int	min_index;

	if (!ps)
		return ;
	while (ps->a)
	{
		min_index = get_min_index(ps->a);
		move_a_to_top(ps, min_index);
		pb(ps);
	}
	while (ps->b)
		pa(ps);
}
