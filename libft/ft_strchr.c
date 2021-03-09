/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:19:41 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/16 11:35:24 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	temp;
	size_t	i;
	int		is_eq;

	i = 0;
	temp = (char)c;
	while (str[i])
	{
		is_eq = str[i] - temp;
		if (is_eq == 0)
			return ((char *)&str[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&str[i]);
	return (NULL);
}
