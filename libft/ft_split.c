/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:55:50 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/25 11:48:13 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freematrix(char **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	return (NULL);
}

static char	*ft_splitdup(char *str, char c)
{
	char	*dup;
	int		size;

	size = 0;
	while (str[size] != c && str[size])
		size++;
	if (!(dup = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (size == 0)
	{
		*dup = '\0';
		return (dup);
	}
	ft_strlcpy(dup, str, size + 1);
	return (dup);
}

static int	ft_wcount(char *str, char c)
{
	int		w_count;

	w_count = 0;
	while (*str)
	{
		if (*str != c)
			w_count++;
		while (*str && *str != c)
			str++;
		if (*str)
			str++;
	}
	return (w_count);
}

char		**ft_split(char const *str, char c)
{
	int		i;
	int		w_count;
	char	**matrix;
	char	*temp;

	i = 0;
	if (!str)
		return (NULL);
	temp = (char *)str;
	w_count = ft_wcount(temp, c);
	if (!(matrix = (char **)malloc(sizeof(char *) * (w_count + 1))))
		return (NULL);
	matrix[w_count] = NULL;
	while (i < w_count)
	{
		while (*temp == c && *temp)
			temp++;
		if (!(matrix[i] = ft_splitdup(temp, c)))
			return (ft_freematrix(matrix, i));
		while (*temp && *temp != c)
			temp++;
		i++;
	}
	return (matrix);
}
