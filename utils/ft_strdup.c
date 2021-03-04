/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:59:37 by lspazzin          #+#    #+#             */
/*   Updated: 2021/03/04 16:58:18 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		size;

	size = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, str, size + 1);
	return (dup);
}
