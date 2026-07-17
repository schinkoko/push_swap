/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:42 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/17 13:56:03 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void	printlist(t_list *lst)
{
	if (!lst)
		return ;
	while (1)
	{
		ft_printf(STDOUT_FILENO, "%d, %d\n", lst->value, lst->index);
		if (!lst->next)
			break ;
		lst = lst->next;
	}
}

void	set_ps(t_stack *ps)
{
	ps->strategy = NULL;
	ps->disorder = 0;
	ps->a = NULL;
	ps->b = NULL;
	ps->total_ops = 0;
	ps->bench = false;
	ps->required_algo = ALGO_NONE;
}

int	stub_main(int argc, char **argv)
{
	t_stack	ps;

	set_ps(&ps);
	if (!fill_stack(argc, argv, &ps))
		return (1);
	set_strategy(&ps);
	printlist(ps.a);
	printf("\n\n");
	assign_ranks(ps.a);
	if (ps.required_algo == ALGO_SIMPLE)
		// selection_sort(&ps);
		;
	else if (ps.required_algo == ALGO_MEDIUM)
		chunk_sort(&ps);
	else if (ps.required_algo == ALGO_COMPLEX)
		// radix_sort(&ps);
		;
	printf("\n\n");
	printlist(ps.a);
	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}


int	main(int argc, char **argv)
{
	t_stack	ps;

	return (stub_main(argc, argv));

	set_ps(&ps);
	if (!fill_stack(argc, argv, &ps))
		return (1);
	set_strategy(&ps);
	assign_ranks(ps.a);
	if (ps.required_algo == ALGO_SIMPLE)
		// selection_sort(&ps);
		;
	else if (ps.required_algo == ALGO_MEDIUM)
		chunk_sort(&ps);
	else if (ps.required_algo == ALGO_COMPLEX)
		// radix_sort(&ps);
		;
	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}
