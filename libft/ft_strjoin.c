/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:20:50 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/16 11:37:35 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*str_out;
	int		i;

	if (!str1 || !str2)
		return (NULL);
	i = ft_strlen(str1) + ft_strlen(str2) + 1;
	str_out = (char *)malloc(sizeof(char) * i);
	if (str_out == NULL)
		return (NULL);
	ft_strlcpy(str_out, str1, i);
	ft_strlcat(str_out, (char *)str2, i);
	return (str_out);
}
