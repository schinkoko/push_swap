/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschinog <aschinog@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:36:50 by aschinog          #+#    #+#             */
/*   Updated: 2026/07/13 18:27:21 by aschinog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LSTOPS_H
# define FT_LSTOPS_H

# include "push_swap.h"

int		ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int value);
t_list	*ft_lstsecondlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new_node);
void	ft_lstclear(t_list **lst, void (*del)(int));

#endif