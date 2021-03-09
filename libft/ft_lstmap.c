/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:43:22 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/18 17:52:15 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out;
	t_list	*new_list;

	if (!l || !(new_list = ft_lstnew(f(l->content))))
		return (NULL);
	l = l->next;
	while (l)
	{
		out = ft_lstnew(f(l->content));
		if (!out)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, out);
		l = l->next;
	}
	return (new_list);
}
