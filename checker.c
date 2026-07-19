/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 22:07:04 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/19 23:11:12 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		++len;
	return (len);
}


static char	*strip_newline(char *op)
{
	size_t	len;

	len = ft_strlen(op);
	if (len > 0 && op[len - 1] == '\n')
		op[len - 1] = '\0';
	return (op);
}


static bool	is_sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

static void	clean_up(t_stack *ps)
{
	ft_lstclear(&ps->a);
	ft_lstclear(&ps->b);
	exit(1);
}

static void	execute_op(t_stack *ps, char *op)
{
	if (ft_strcmp(op, "sa") == NO_DIFF)
		sa(ps);
	else if (ft_strcmp(op, "sb") == NO_DIFF)
		sb(ps);
	else if (ft_strcmp(op, "ss") == NO_DIFF)
		ss(ps);
	else if (ft_strcmp(op, "pa") == NO_DIFF)
		pa(ps);
	else if (ft_strcmp(op, "pb") == NO_DIFF)
		pb(ps);
	else if (ft_strcmp(op, "ra") == NO_DIFF)
		ra(ps);
	else if (ft_strcmp(op, "rb") == NO_DIFF)
		rb(ps);
	else if (ft_strcmp(op, "rr") == NO_DIFF)
		rr(ps);
	else if (ft_strcmp(op, "rra") == NO_DIFF)
		rra(ps);
	else if (ft_strcmp(op, "rrb") == NO_DIFF)
		rrb(ps);
	else if (ft_strcmp(op, "rrr") == NO_DIFF)
		rrr(ps);
	else
	{
		ft_printf(STDOUT_FILENO, PS_ERROR_MSG);
		clean_up(ps);
	}
}


int	main(int argc, char **argv)
{
	t_stack	ps;
	char	*line;

	if (!argv)
		return (1);
	set_ps(&ps);
	if (!fill_stack(argc, argv, &ps))
		return (1);
	line = get_next_line(0);
	while (line)
	{
		execute_op(&ps, strip_newline(line));
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(ps.a) && !ps.b)
		ft_printf(STDOUT_FILENO, "OK\n");
	else
		ft_printf(STDOUT_FILENO, "KO\n");
	clean_up(&ps);
	return (0);
}
