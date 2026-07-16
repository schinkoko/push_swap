/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chungus_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:22:31 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/16 20:42:42 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

/*
** Step 1: assign ranks (indexes) to each node.
** Rank = how many nodes have a smaller value.
** After this, node->index is the node's sorted position (0-based).
*/

static void	rank_node(t_list *target, t_list *a)
{
	t_list	*cur;
	int		rank;

	rank = 0;
	cur = a;
	while (cur)
	{
		if (cur->value < target->value)
			++rank;
		cur = cur->next;
	}
	target->index = rank;
}

void	assign_ranks(t_list *a)
{
	t_list	*cur;

	cur = a;
	while (cur)
	{
		rank_node(cur, a);
		cur = cur->next;
	}
}

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

	size = ft_lstsize(ps->a);
	mid = (start + end) / 2;
	while (ft_lstsize(ps->a) > 0)
	{
		if (ps->a->index >= start && ps->a->index <= end)
		{
			if (ps->a->index > mid)
				rb(ps);
			pb(ps);
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

static int	max_index_in_b(t_list *b)
{
	int		max;
	t_list	*cur;

	max = b->index;
	cur = b->next;
	while (cur)
	{
		if (cur->index > max)
			max = cur->index;
		cur = cur->next;
	}
	return (max);
}

static void	bring_to_top(t_stack *ps, int target_idx)
{
	int	pos;
	int	size;

	pos = 0;
	size = ft_lstsize(ps->b);
	while (ps->b->index != target_idx)
	{
		if (pos < size / 2)
			rb(ps);
		else
			rrb(ps);
		++pos;
	}
}

static void	pull_all(t_stack *ps)
{
	int	max;
	int	size;

	size = ft_lstsize(ps->b);
	while (size > 0)
	{
		max = max_index_in_b(ps->b);
		bring_to_top(ps, max);
		pa(ps);
	}
}


static int	ft_sqrt(int n)
{
	int	low;
	int	high;
	int	mid;

	if (n <= 0)
		return (0);
	low = 1;
	high = n / 2 + 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (mid == n / mid && n % mid == 0)
			return (mid);
		else if (mid < n / mid)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (high);
}

/*
** Entry point: O(n√n) chunk sort.
*/

void	algo_medium(t_stack *ps)
{
	int	n;
	int	chunk_size;

	n = ft_lstsize(ps->a);
	if (n <= 1)
		return ;
	assign_ranks(ps->a);
	chunk_size = ft_sqrt((double)n);
	if (chunk_size < 1)
		chunk_size = 1;
	push_all_chunks(ps, chunk_size, n);
	pull_all(ps);
}
