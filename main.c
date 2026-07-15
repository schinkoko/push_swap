#include <stdio.h>

#include "ft_lstops.h"

static void	del(int value)
{
	value = 0;
}

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

int	main(void)
{
	t_stack	*stack;

	stack = calloc(1, sizeof(t_stack));
	
	ft_lstadd_front(&stack->b, ft_lstnew(5));
	ft_lstadd_front(&stack->b, ft_lstnew(10));
	ft_lstadd_front(&stack->b, ft_lstnew(8));
	ft_lstadd_front(&stack->b, ft_lstnew(7));
	ft_lstadd_front(&stack->b, ft_lstnew(6));

	rrb(stack);
	//sa(stack);
	//pa(stack);
	//pa(stack);
	// pa(stack);
	// pa(stack);
	// pa(stack);

	// pb(stack);
	// pb(stack);
	// pb(stack);


	printf("stack->a:\n");
	printlist(stack->a);
	printf("stack->b:\n");
	printlist(stack->b);
	
	ft_lstclear(&stack->a, &del);
	ft_lstclear(&stack->b, &del);
	free(stack);	
	return 0;
}