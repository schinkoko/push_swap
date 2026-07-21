/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 21:21:44 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/21 19:32:37 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	chunk_sort(t_stack *ps)
{
	int	n;
	int	chunk_size;

	n = ft_lstsize(ps->a);
	if (n <= 1)
		return ;
	chunk_size = ft_sqrt(n);
	if (chunk_size < 1)
		chunk_size = 1;
	push_all_chunks(ps, chunk_size, n);
	pull_all(ps);
}

void	radix_sort(t_stack *ps)
{
	int	i;
	int	pos;
	int	size;
	int	bits;

	size = ft_lstsize(ps->a);
	bits = 0;
	while (((size - 1) >> bits) != 0)
		bits++;
	pos = 0;
	while (pos < bits)
	{
		i = 0;
		while (i < size)
		{
			if (((ps->a->index >> pos) & 1) == 0)
				pb(ps);
			else
				ra(ps);
			i++;
		}
		while (ps->b)
			pa(ps);
		pos++;
	}
}
