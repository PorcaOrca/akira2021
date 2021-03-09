/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:57:44 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/16 11:22:08 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		*tstr;

	i = 0;
	tstr = (unsigned char *)str;
	while (i < n)
	{
		if (tstr[i] == (unsigned char)c)
			return (&tstr[i]);
		i++;
	}
	return (NULL);
}
