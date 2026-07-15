#include "ft_lstops.h"

void	ra(t_stack *stacks)
{
	t_list	*first;
	t_list	*last;

	if (!stacks || !stacks->a || !stacks->a->next)
		return ;
	first = stacks->a;
	stacks->a = first->next;
	first->next = NULL;
	last = ft_lstlast(stacks->a);
	last->next = first;
	stacks->operations[RA]++;
}

void	rb(t_stack *stacks)
{
	t_list	*first;
	t_list	*last;

	if (!stacks || !stacks->b || !stacks->b->next)
		return ;
	first = stacks->b;
	stacks->b = first->next;
	first->next = NULL;
	last = ft_lstlast(stacks->b);
	last->next = first;
	stacks->operations[RB]++;
}

void	rra(t_stack *stacks)
{
	t_list	*prev;
	t_list	*last;

	if (!stacks || !stacks->a || !stacks->a->next)
		return ;
	prev = stacks->a;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stacks->a;
	stacks->a = last;
	stacks->operations[RRA]++;
}

void	rrb(t_stack *stacks)
{
	t_list	*prev;
	t_list	*last;

	if (!stacks || !stacks->b || !stacks->b->next)
		return ;
	prev = stacks->b;
	while (prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = stacks->b;
	stacks->b = last;
	stacks->operations[RRB]++;
}