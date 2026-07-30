/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_ps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:58 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/30 14:19:53 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *ps)
{
	int		tmp_value;
	int		tmp_index;

	if (!ps || !ps->a || !ps->a->next)
		return ;
	tmp_value = ps->a->value;
	tmp_index = ps->a->index;
	ps->a->value = ps->a->next->value;
	ps->a->index = ps->a->next->index;
	ps->a->next->value = tmp_value;
	ps->a->next->index = tmp_index;
	record_op(ps, SA, "sa");
}

void	sb(t_stack *ps)
{
	int		tmp_value;
	int		tmp_index;

	if (!ps || !ps->b || !ps->b->next)
		return ;
	tmp_value = ps->b->value;
	tmp_index = ps->b->index;
	ps->b->value = ps->b->next->value;
	ps->b->index = ps->b->next->index;
	ps->b->next->value = tmp_value;
	ps->b->next->index = tmp_index;
	record_op(ps, SB, "sb");
}

void	pa(t_stack *ps)
{
	t_list	*first;

	if (!ps || !ps->b)
		return ;
	first = ps->b;
	ps->b = ps->b->next;
	first->next = NULL;
	ft_lstadd_front(&ps->a, first);
	record_op(ps, PA, "pa");
}

void	pb(t_stack *ps)
{
	t_list	*first;

	if (!ps || !ps->a)
		return ;
	first = ps->a;
	ps->a = ps->a->next;
	first->next = NULL;
	ft_lstadd_front(&ps->b, first);
	record_op(ps, PB, "pb");
}
