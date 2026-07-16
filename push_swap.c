/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:42 by aschinog          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/16 22:42:11 by mtrukhin         ###   ########.fr       */
=======
/*   Updated: 2026/07/16 22:58:44 by aschinog         ###   ########.fr       */
>>>>>>> refs/remotes/upstream/main
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

<<<<<<< HEAD
void	handle_op(t_stack *ps, char *op_name)
{
	if (ps->presort)
		ft_printf(STDOUT_FILENO, op_name);
}

void	set_ps(t_stack *ps)
=======
int	parse_args(int argc, char **argv, t_stack *ps)
>>>>>>> refs/remotes/upstream/main
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
