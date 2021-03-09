/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 10:47:53 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/16 11:34:30 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned const char	*temp_src;
	unsigned char		*temp_dest;

	temp_src = (unsigned const char *)src;
	temp_dest = (unsigned char *)dst;
	if (temp_dest == temp_src)
		return (dst);
	if (temp_src > temp_dest)
		ft_memcpy(temp_dest, temp_src, len);
	if (temp_dest > temp_src)
	{
		while (len > 0)
		{
			len--;
			temp_dest[len] = temp_src[len];
		}
	}
	return (dst);
}
