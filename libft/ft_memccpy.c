/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:27:53 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/16 11:34:09 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*tdst;
	unsigned char		*tsrc;
	unsigned char		limit;

	i = 0;
	tdst = (unsigned char *)dst;
	tsrc = (unsigned char *)src;
	limit = (unsigned char)c;
	while (tsrc[i] != limit && i < n)
	{
		tdst[i] = tsrc[i];
		i++;
	}
	if (i < n)
	{
		tdst[i] = tsrc[i];
		return (&tdst[i + 1]);
	}
	return (NULL);
}
