/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:22:31 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/21 19:32:22 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunk(t_stack *ps, int start, int end)
{
	int	size;
	int	mid;
	int	remaining;

	size = ft_lstsize(ps->a);
	mid = (start + end) / 2;
	remaining = end - start + 1;
	while (remaining > 0)
	{
		if (ps->a->index >= start && ps->a->index <= end)
		{
			pb(ps);
			--remaining;
		}
		rra(ps);
	}
}

void	push_all_chunks(t_stack *ps, int chunk_size, int n)
{
	int	start;
	int	end;

	start = 0;
	while (start < n)
	{
		end = start + chunk_size - 1;
		if (end >= n)
			end = n - 1;
		push_chunk(ps, start, end);
		start += chunk_size;
	}
}

void	pull_all(t_stack *ps)
{
	int	max;
	int	size;

	size = ft_lstsize(ps->b);
	while (size-- > 0)
	{
		max = get_max_index(ps->b);
		move_b_to_top(ps, max);
		pa(ps);
	}
}
