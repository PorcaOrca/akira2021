/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:02:20 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/17 14:54:05 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(int nbr, int size)
{
	int		temp;
	char	*dest;

	if (!(dest = (char *)ft_calloc(sizeof(char), (size + 1))))
		return (NULL);
	if (nbr < 0)
		dest[0] = '-';
	while (nbr != 0)
	{
		size--;
		temp = nbr % 10;
		if (temp < 0)
			temp = -temp;
		nbr = nbr / 10;
		dest[size] = '0' + temp;
	}
	return (dest);
}

char		*ft_itoa(int nbr)
{
	int		temp;
	int		i;
	char	*dest;

	temp = nbr;
	i = 0;
	if (nbr < 0)
		i++;
	if (nbr == 0)
	{
		dest = ft_calloc(sizeof(char), 2);
		dest[0] = '0';
		return (dest);
	}
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	dest = ft_convert(nbr, i);
	return (dest);
}
