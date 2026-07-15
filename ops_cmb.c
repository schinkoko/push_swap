#include "ft_lstops.h"

void	ss(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
	stacks->operations[SS]++;
}

void	rr(t_stack *stacks)
{
	ra(stacks);
	rb(stacks);
	stacks->operations[RR]++;
}

void	rrr(t_stack *stacks)
{
	rra(stacks);
	rrb(stacks);
	stacks->operations[RRR]++;
}