/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:07:59 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/16 11:24:39 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*temp_str1;
	unsigned char	*temp_str2;

	i = 0;
	temp_str1 = (unsigned char *)str1;
	temp_str2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (temp_str1[i] != temp_str2[i])
			return (temp_str1[i] - temp_str2[i]);
		i++;
	}
	return (0);
}
