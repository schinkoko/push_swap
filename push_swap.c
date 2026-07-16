/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:42 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 23:07:53 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <string.h>

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

int	parse_args(int argc, char **argv, t_stack *ps)
{
	if (!fill_stack(argc, argv, ps))
		return (1);
	set_strategy(ps);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	ps;

	memset(&ps, 0, sizeof(t_stack));

	parse_args(argc, argv, &ps);
	ft_printf(STDOUT_FILENO, "strategy: %s\n", ps.strategy);
	ft_printf(STDOUT_FILENO, "bench: %i\n", ps.bench);

	assign_ranks(ps.a);

	ft_printf(STDOUT_FILENO, "ps.a:\n");
	printlist(ps.a);
	ft_printf(STDOUT_FILENO, "ps.b:\n");
	printlist(ps.b);

	selection_sort(&ps);

	ft_printf(STDOUT_FILENO, "ps.a:\n");
	printlist(ps.a);
	ft_printf(STDOUT_FILENO, "ps.b:\n");
	printlist(ps.b);

	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}
