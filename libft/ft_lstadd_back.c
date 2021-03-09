/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:01:37 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/18 12:27:17 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*element;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	element = ft_lstlast(*lst);
	element->next = new;
}
