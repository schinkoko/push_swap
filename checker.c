/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 22:07:04 by mtrukhin          #+#    #+#             */
/*   Updated: 2026/07/21 19:33:25 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		execute_op(&ps, strip_newline(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(ps.a) && !ps.b)
		ft_printf(STDOUT_FILENO, "OK\n");
	else
		ft_printf(STDOUT_FILENO, "KO\n");
	ft_lstclear(&ps.a);
	ft_lstclear(&ps.b);
	return (0);
}
