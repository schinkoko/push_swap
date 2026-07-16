/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 22:15:02 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 22:32:36 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int n)
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

void	move_to_top(t_stack *ps, t_list *lst, int target_idx)
{
	int	pos;
	int	size;

	if (!lst)
		return ;
	size = ft_lstsize(lst);
	pos = find_position(lst, target_idx);
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
