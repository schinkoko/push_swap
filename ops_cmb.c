/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_cmb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:49:32 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/30 17:06:32 by aschinog         ###   ########.fr       */
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
