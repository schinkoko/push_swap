/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_cmb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:32 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/30 17:53:19 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *ps)
{
	sa(ps, false);
	sb(ps, false);
	record_op(ps, SS, "ss");
}

void	rr(t_stack *ps)
{
	ra(ps, false);
	rb(ps, false);
	record_op(ps, RR, "rr");
}

void	rrr(t_stack *ps)
{
	rra(ps, false);
	rrb(ps, false);
	record_op(ps, RRR, "rrr");
}
