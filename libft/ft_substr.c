/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 08:52:44 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/22 09:27:53 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str_out;
	char			*str_temp;
	unsigned int	i;
	unsigned int	str_size;

	i = 0;
	if (!s)
		return (NULL);
	str_size = ft_strlen(s);
	if (start > str_size)
		return (ft_calloc(1, sizeof(char)));
	str_temp = (char *)s;
	while (i < start)
	{
		str_temp++;
		i++;
	}
	str_size -= i - 1;
	if (len > str_size)
		len = str_size;
	str_out = (char *)malloc(sizeof(char) * (len + 1));
	if (str_out == NULL)
		return (NULL);
	ft_strlcpy(str_out, str_temp, len + 1);
	return (str_out);
}
