/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 22:15:02 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 23:53:44 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position(t_list *lst, int target_idx)
{
	int	pos;

	pos = 0;
	while (lst)
	{
		if (lst->index == target_idx)
			return (pos);
		lst = lst->next;
		pos++;
	}
	return (-1);
}

void	move_a_to_top(t_stack *ps, int target_idx)
{
	int	pos;
	int	size;

	if (!ps || !ps->a)
		return ;
	size = ft_lstsize(ps->a);
	pos = find_position(ps->a, target_idx);
	if (pos == -1)
		return ;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(ps);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rra(ps);
	}
}

void	move_b_to_top(t_stack *ps, int target_idx)
{
	int	pos;
	int	size;

	if (!ps || !ps->b)
		return ;
	size = ft_lstsize(ps->b);
	pos = find_position(ps->b, target_idx);
	if (pos == -1)
		return ;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(ps);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(ps);
	}
}

int	get_max_index(t_list *lst)
{
	int		max;
	t_list	*cur;

	max = lst->index;
	cur = lst->next;
	while (cur)
	{
		if (cur->index > max)
			max = cur->index;
		cur = cur->next;
	}
	return (max);
}

int	get_min_index(t_list *lst)
{
	int		min;
	t_list	*cur;

	min = lst->index;
	cur = lst->next;
	while (cur)
	{
		if (cur->index < min)
			min = cur->index;
		cur = cur->next;
	}
	return (min);
}
