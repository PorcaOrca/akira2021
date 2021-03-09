/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:46:07 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/16 11:39:14 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp_str;

	temp_str = (char *)str;
	i = 0;
	if (!to_find[i])
		return (temp_str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < len)
		{
			if (!to_find[j + 1])
				return (&temp_str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
