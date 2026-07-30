/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_cmb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:32 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/30 14:18:44 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *ps)
{
	sa(ps);
	sb(ps);
	record_op(ps, SS, "ss");
}

void	rr(t_stack *ps)
{
	ra(ps);
	rb(ps);
	record_op(ps, RR, "rr");
}

void	rrr(t_stack *ps)
{
	rra(ps);
	rrb(ps);
	record_op(ps, RRR, "rrr");
}
