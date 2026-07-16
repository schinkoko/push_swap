/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:22:31 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/16 23:41:59 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Step 2: push nodes in chunk order to b.
** Nodes whose rank falls in [chunk_start, chunk_end] get pushed to b.
** Rotate a to find them efficiently.
** Push largest-rank chunks first so b ends up with smallest on top.
*/

static bool	chunk_in_top_half(t_list *a, int start, int end, int size)
{
	t_list	*cur;
	int		pos;

	cur = a;
	pos = 0;
	while (cur && pos < size / 2)
	{
		if (cur->index >= start && cur->index <= end)
			return (true);
		cur = cur->next;
		++pos;
	}
	return (false);
}

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
			if (ps->a->index > mid)
				rb(ps);
			pb(ps);
			--remaining;
		}
		else if (chunk_in_top_half(ps->a, start, end, size))
			ra(ps);
		else
			rra(ps);
	}
}

static void	push_all_chunks(t_stack *ps, int chunk_size, int n)
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

/*
** Step 3: pull back from b to a in reverse order.
** Find the node in b with the highest remaining index,
** rotate b to bring it to top, then pa.
*/

static void	pull_all(t_stack *ps)
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

/*
** Entry point: O(n√n) chunk sort.
*/

void	chunk_sort(t_stack *ps)
{
	int	n;
	int	chunk_size;

	n = ft_lstsize(ps->a);
	if (n <= 1)
		return ;
	chunk_size = ft_sqrt((double)n);
	if (chunk_size < 1)
		chunk_size = 1;
	push_all_chunks(ps, chunk_size, n);
	pull_all(ps);
}
