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

void	get_benchmarks(t_stack *algo)
{
	ft_printf("[bench] disorder:  %.2f\n", algo->disorder);
	ft_printf("[bench] strategy:  %s\n", algo->strategy);
	ft_printf("[bench] total_ops:  %zu\n", algo->total_ops);
	ft_printf("[bench] ");
	ft_printf("sa:  %zu  ", algo->operations[SA]);
	ft_printf("sb:  %zu  ", algo->operations[SB]);
	ft_printf("ss:  %zu  ", algo->operations[SS]);
	ft_printf("pa:  %zu  ", algo->operations[PA]);
	ft_printf("pb:  %zu\n", algo->operations[PB]);
	ft_printf("[bench] ");
	ft_printf("ra:  %zu  ", algo->operations[RA]);
	ft_printf("rb:  %zu  ", algo->operations[RB]);
	ft_printf("rr:  %zu  ", algo->operations[RR]);
	ft_printf("rra:  %zu  ", algo->operations[RRA]);
	ft_printf("rrb:  %zu  ", algo->operations[RRB]);
	ft_printf("rrr:  %zu", algo->operations[RRR]);
}
