/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:42 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/30 14:26:08 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	ps;

	ft_bzero(&ps, sizeof(ps));
	if (!fill_stack(argc, argv, &ps))
		return (1);
	set_strategy(&ps);
	if (!is_sorted(ps.a))
	{
		assign_ranks(ps.a);
		if (ps.algo == ALGO_SIMPLE)
			selection_sort(&ps);
		else if (ps.algo == ALGO_MEDIUM)
			chunk_sort(&ps);
		else if (ps.algo == ALGO_COMPLEX)
			radix_sort(&ps);
	}
	if (ps.bench)
		print_bench(&ps);
	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}
