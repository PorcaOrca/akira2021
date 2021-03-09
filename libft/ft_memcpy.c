/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 09:01:55 by lspazzin          #+#    #+#             */
/*   Updated: 2021/03/09 09:35:36 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*tdest;
	unsigned const char	*tsrc;

	i = 0;
	tdest = (unsigned char *)dst;
	tsrc = (unsigned const char *)src;
	if ((void *)&tdest[i] == 0 && (void *)&tsrc[i] == 0)
		return (NULL);
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return (dst);
}
