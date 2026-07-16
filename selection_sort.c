/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:21:44 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 22:58:11 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stack *ps)
{
	int	size;
	int	min_index;

	while (ft_lstsize(ps->a) > 0)
	{
		size = ft_lstsize(ps->a);
		min_index = get_min_index(ps->a);
		move_to_top(ps, ps->a, min_index);
		pb(ps);
	}
	while (ps->b)
		pa(ps);
}
