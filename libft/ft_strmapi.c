/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 14:58:09 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/18 16:40:19 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*fct)(unsigned int, char))
{
	unsigned int		i;
	char				*out;
	unsigned int		str_size;

	i = 0;
	if (!s)
		return (NULL);
	str_size = ft_strlen(s);
	out = (char *)malloc((str_size + 1) * sizeof(char));
	if (!out)
		return (NULL);
	out[str_size] = '\0';
	while (i < str_size)
	{
		out[i] = fct(i, s[i]);
		i++;
	}
	return (out);
}
