/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 18:37:08 by lspazzin          #+#    #+#             */
/*   Updated: 2021/03/04 16:58:59 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i_dest;
	size_t	i_src;
	size_t	str_lenght;

	i_dest = 0;
	i_src = 0;
	str_lenght = ft_strlen(src);
	while (dest[i_dest])
		i_dest++;
	if (size == 0)
		return (str_lenght);
	if (size <= i_dest)
		return (str_lenght + size);
	while (size && src[i_src] && i_dest + 1 < size)
	{
		dest[i_dest] = src[i_src];
		i_dest++;
		i_src++;
	}
	dest[i_dest] = '\0';
	return (i_dest - i_src + str_lenght);
}
