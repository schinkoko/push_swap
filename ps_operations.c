#include "push_swap.h"
#include "ft_lstops.h"

void	sa(t_stack *stacks)
{
	t_list	*tmp;
	t_list	*last;

	tmp = ft_lstsecondlast(stacks->a);
	last = tmp->next;
	last->next = tmp;
	tmp->next = last;
	stacks->operations[SA]++;
}

void	sb(t_stack *stacks)
{
	t_list	*tmp;
	t_list	*last;

	tmp = ft_lstsecondlast(stacks->b);
	last = tmp->next;
	last->next = tmp;
	tmp->next = last;
	stacks->operations[SB]++;
}

void	ss(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
	stacks->operations[SS]++;
}

void	pa(t_stack *stacks)
{
	t_list	*last;
	t_list	*prev;

	if (!stacks->b)
		return ;
	prev = ft_lstsecondlast(stacks->b);
	if (prev)
		last = prev->next;
	else
		last = stacks->b;
	if (prev)
		prev->next = NULL;
	else
		stacks->b = NULL;
	ft_lstadd_back(&stacks->a, last);
	stacks->operations[PA]++;
}

void	pb(t_stack *stacks)
{
	t_list	*last;
	t_list	*prev;

	if (!stacks->a)
		return ;
	prev = ft_lstsecondlast(stacks->a);
	if (prev)
		last = prev->next;
	else
		last = stacks->a;
	if (prev)
		prev->next = NULL;
	else
		stacks->a = NULL;
	ft_lstadd_back(&stacks->b, last);
	stacks->operations[PB]++;
}
