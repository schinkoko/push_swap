/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:36:50 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/15 16:47:46 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTOPS_H
# define FT_LSTOPS_H

# include "push_swap.h"

t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(int));

#endif