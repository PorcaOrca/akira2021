/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:29:04 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/20 18:44:53 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char		temp;
	const unsigned char	*s;
	int					i;

	temp = (unsigned char)c;
	s = (const unsigned char *)str;
	i = 0;
	while (s[i])
		i++;
	if (temp == 0)
		return ((char *)&str[i]);
	while (i >= 0)
	{
		if (s[i] - temp == 0)
			return ((char *)&str[i]);
		i--;
	}
	return (NULL);
}
