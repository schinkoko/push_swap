/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrukhin <mtrukhin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:44:29 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/17 13:52:05 by mtrukhin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		++size;
	}
	return (size);
}

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

bool	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return (false);
	tmp = *lst;
	while (tmp)
	{
		if (tmp->value == new->value)
			return (false);
		tmp = tmp->next;
	}
	new->next = *lst;
	*lst = new;
	return (true);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = NULL;
}
