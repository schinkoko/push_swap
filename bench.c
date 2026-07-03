/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:11:04 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/06/20 17:00:28 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parse_args.h"

void	get_benchmarks(t_stack *push_swap)
{
	ft_printf(stderr, "[bench] disorder:  %.2f\n", push_swap->disorder);
	ft_printf(stderr, "[bench] strategy:  %s\n", push_swap->strategy);
	ft_printf(stderr, "[bench] total_ops:  %i\n", push_swap->total_ops);
	ft_printf(stderr, "[bench] ");
	ft_printf(stderr, "sa:  %i  ", push_swap->operations[SA]);
	ft_printf(stderr, "sb:  %i  ", push_swap->operations[SB]);
	ft_printf(stderr, "ss:  %i  ", push_swap->operations[SS]);
	ft_printf(stderr, "pa:  %i  ", push_swap->operations[PA]);
	ft_printf(stderr, "pb:  %i\n", push_swap->operations[PB]);
	ft_printf(stderr, "[bench] ");
	ft_printf(stderr, "ra:  %i  ", push_swap->operations[RA]);
	ft_printf(stderr, "rb:  %i  ", push_swap->operations[RB]);
	ft_printf(stderr, "rr:  %i  ", push_swap->operations[RR]);
	ft_printf(stderr, "rra:  %i  ", push_swap->operations[RRA]);
	ft_printf(stderr, "rrb:  %i  ", push_swap->operations[RRB]);
	ft_printf(stderr, "rrr:  %i", push_swap->operations[RRR]);
}
