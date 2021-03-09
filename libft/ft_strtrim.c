/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:38:45 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/20 10:01:28 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	char	*out_start;
	char	*out_end;
	char	*out;
	int		i;

	if (!str || !set)
		return (NULL);
	i = 0;
	out_start = (char *)str;
	out_end = (char *)&str[ft_strlen(str) - 1];
	while (ft_strchr(set, *out_start))
		out_start++;
	while (ft_strchr(set, *out_end))
	{
		out_end--;
		if (out_end < out_start)
			return (out = (char *)ft_calloc(sizeof(char), 1));
	}
	while (&out_start[i] <= out_end)
		i++;
	if (!(out = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strlcpy(out, out_start, i + 1);
	return (out);
}
