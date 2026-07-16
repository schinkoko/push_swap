/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 20:12:50 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/16 20:46:06 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rank_node(t_list *target, t_list *a)
{
	t_list	*node;
	int		rank;

	rank = 0;
	node = a;
	while (node)
	{
		if (node->value < target->value)
			++rank;
		node = node->next;
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