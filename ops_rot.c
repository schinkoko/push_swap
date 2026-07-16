/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:45 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 22:57:45 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *ps)
{
	t_list	*first;
	t_list	*last;

	if (!ps || !ps->a || !ps->a->next)
		return ;
	first = ps->a;
	ps->a = first->next;
	first->next = NULL;
	last = ft_lstlast(ps->a);
	last->next = first;
	ps->operations[RA]++;
	ft_printf(STDOUT_FILENO, "ra\n");
}

void	rb(t_stack *ps)
{
	t_list	*first;
	t_list	*last;

	if (!ps || !ps->b || !ps->b->next)
		return ;
	first = ps->b;
	ps->b = first->next;
	first->next = NULL;
	last = ft_lstlast(ps->b);
	last->next = first;
	ps->operations[RB]++;
	ft_printf(STDOUT_FILENO, "rb\n");
}

void	rra(t_stack *ps)
{
	t_list	*prev;
	t_list	*last;

	if (!ps || !ps->a || !ps->a->next)
		return ;
	prev = ps->a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = ps->a;
	ps->a = last;
	ps->operations[RRA]++;
	ft_printf(STDOUT_FILENO, "rra\n");
}

void	rrb(t_stack *ps)
{
	t_list	*prev;
	t_list	*last;

	if (!ps || !ps->b || !ps->b->next)
		return ;
	prev = ps->b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = ps->b;
	ps->b = last;
	ps->operations[RRB]++;
	ft_printf(STDOUT_FILENO, "rrb\n");
}
