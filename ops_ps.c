#include "ft_lstops.h"

void	sa(t_stack *stacks)
{
	int		tmp_value;
	int		tmp_index;

	if (!stacks || !stacks->a || !stacks->a->next)
		return ;
	tmp_value = stacks->a->value;
	tmp_index = stacks->a->index;
	stacks->a->value = stacks->a->next->value;
	stacks->a->index = stacks->a->next->index; 
	stacks->a->next->value = tmp_value;
	stacks->a->next->index = tmp_index;
	stacks->operations[SA]++;
}

void	sb(t_stack *stacks)
{
	int		tmp_value;
	int		tmp_index;

	if (!stacks || !stacks->b || !stacks->b->next)
		return ;
	tmp_value = stacks->b->value;
	tmp_index = stacks->b->index;
	stacks->b->value = stacks->b->next->value;
	stacks->b->index = stacks->b->next->index; 
	stacks->b->next->value = tmp_value;
	stacks->b->next->index = tmp_index;
	stacks->operations[SB]++;
}

void	pa(t_stack *stacks)
{
	t_list	*first;

	if (!stacks || !stacks->b)
		return ;
	first = stacks->b;
	stacks->b = stacks->b->next;
	first->next = NULL;
	ft_lstadd_front(&stacks->a, first);
	stacks->operations[PA]++;
}

void	pb(t_stack *stacks)
{
	t_list	*first;

	if (!stacks || !stacks->a)
		return ;
	first = stacks->a;
	stacks->a = stacks->a->next;
	first->next = NULL;
	ft_lstadd_front(&stacks->b, first);
	stacks->operations[PB]++;
}
