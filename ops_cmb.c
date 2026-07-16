/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_cmb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:32 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 21:21:21 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *ps)
{
	sa(ps);
	sb(ps);
	ps->operations[SS]++;
	handle_op(ps, "ss\n");
}

void	rr(t_stack *ps)
{
	ra(ps);
	rb(ps);
	ps->operations[RR]++;
	handle_op(ps, "rr\n");
}

void	rrr(t_stack *ps)
{
	rra(ps);
	rrb(ps);
	ps->operations[RRR]++;
	handle_op(ps, "rrr\n");
}
