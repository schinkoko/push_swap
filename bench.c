/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:11:04 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/16 21:21:21 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int		hundredths;
	char	*stringed;
	char	buf[3];

	hundredths = (int)(disorder * 10000 + 0.5);
	stringed = ft_itoa(hundredths / 100);
	buf[0] = '0' + (hundredths % 100) / 10;
	buf[1] = '0' + (hundredths % 100) % 10;
	buf[2] = '\0';
	ft_printf(STDERR_FILENO, "[bench] disorder:  ");
	ft_printf(STDERR_FILENO, stringed);
	ft_printf(STDERR_FILENO, ".");
	write(STDERR_FILENO, buf, 2);
	ft_printf(STDERR_FILENO, "\n");
	free(stringed);
}

void	get_benchmarks(t_stack *ps)
{
	print_disorder(ps->disorder);
	ft_printf(STDERR_FILENO, "[bench] strategy:  %s\n", ps->strategy);
	ft_printf(STDERR_FILENO, "[bench] total_ops:  %i\n", ps->total_ops);
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "sa:  %i  ", ps->operations[SA]);
	ft_printf(STDERR_FILENO, "sb:  %i  ", ps->operations[SB]);
	ft_printf(STDERR_FILENO, "ss:  %i  ", ps->operations[SS]);
	ft_printf(STDERR_FILENO, "pa:  %i  ", ps->operations[PA]);
	ft_printf(STDERR_FILENO, "pb:  %i\n", ps->operations[PB]);
	ft_printf(STDERR_FILENO, "[bench] ");
	ft_printf(STDERR_FILENO, "ra:  %i  ", ps->operations[RA]);
	ft_printf(STDERR_FILENO, "rb:  %i  ", ps->operations[RB]);
	ft_printf(STDERR_FILENO, "rr:  %i  ", ps->operations[RR]);
	ft_printf(STDERR_FILENO, "rra:  %i  ", ps->operations[RRA]);
	ft_printf(STDERR_FILENO, "rrb:  %i  ", ps->operations[RRB]);
	ft_printf(STDERR_FILENO, "rrr:  %i", ps->operations[RRR]);
}
