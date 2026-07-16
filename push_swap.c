/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:42 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/16 22:42:11 by mtrukhin         ###   ########.fr       */
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

void	set_ps(t_stack *ps)
{
	ps->strategy = NULL;
	ps->disorder = 0;
	ps->a = NULL;
	ps->b = NULL;
	ps->total_ops = 0;
	ps->bench = false;
	ps->presort = false;
	ps->required_algo = ALGO_NONE;
}


int	main(int argc, char **argv)
{
	t_stack	ps;

	set_ps(&ps);
	if (!fill_stack(argc, argv, &ps))
		return (1);
	printlist(ps.a);
	printf("\n\n");
	set_strategy(&ps);
	printf("ra: %i", ps.required_algo);
	if (ps.required_algo == ALGO_SIMPLE)
		// simple_sort(&ps);  // TODO: Rename to actual sort
		;
	else if (ps.required_algo == ALGO_MEDIUM)
		printf("HERE!!!"), chunk_sort(&ps);
	else if (ps.required_algo == ALGO_COMPLEX)
		// complex_sort(&ps);  // TODO: Rename to actual sort
		;
	printlist(ps.a);
	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}
