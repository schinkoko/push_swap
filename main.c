/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 22:52:51 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/19 23:28:12 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stack	ps;
	
	set_ps(&ps);
	if (!fill_stack(argc, argv, &ps))
		return (1);
	set_strategy(&ps);
	assign_ranks(ps.a);
	if (ps.required_algo == ALGO_SIMPLE)
		selection_sort(&ps);
	else if (ps.required_algo == ALGO_MEDIUM)
		chunk_sort(&ps);
	else if (ps.required_algo == ALGO_COMPLEX)
		radix_sort(&ps);
	if (ps.bench)
		get_benchmarks(&ps);
	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}