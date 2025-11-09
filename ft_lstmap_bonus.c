/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kanahiz <kanahiz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 03:53:22 by kanahiz           #+#    #+#             */
/*   Updated: 2025/11/08 07:53:03 by kanahiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ras_new_list;
	t_list	*new_node;
	void	*new_cont;

	if (!lst || !f || !del)
		return (NULL);
	ras_new_list = NULL;
	while (lst)
	{
		new_cont = f(lst->content);
		new_node = ft_lstnew(new_cont);
		if (!new_node)
		{
			del(new_cont);
			ft_lstclear(&ras_new_list, del);
			break ;
		}
		ft_lstadd_back(&ras_new_list, new_node);
		lst = lst->next;
	}
	return (ras_new_list);
}
