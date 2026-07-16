/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:42 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 21:21:21 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <string.h>


static void	printlist(t_list *tmp)
{
	if (!tmp)
		return ;
	while (1)
	{
		printf("%d, %d\n", tmp->value, tmp->index);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
}

void	handle_op(t_stack *ps, char *op_name)
{
	if (ps->presort)
		ft_printf(STDOUT_FILENO, op_name);
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
	rrb(&ps);
	sb(&ps);
	pa(&ps);
	printf("strategy: %s\n", ps.strategy);
	printf("bench: %i\n", ps.bench);
	printf("ps.a:\n");
	printlist(ps.a);
	printf("ps.b:\n");
	printlist(ps.b);
	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}
