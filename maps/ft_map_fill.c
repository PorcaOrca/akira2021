/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:44:52 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/25 17:03:19 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../akira2021.h"

int		ft_map_fill(t_map *map)
{
	int		i;
	int		x;
	int		len;
	
	i = 0;
	x = -1;
	while (map->count > ++x)
	{
		len = 0;
		while (map->buff[i] != '\n' && map->buff[i])
		{
			len++;
			i++;
		}
		if (!(map->matrix[x] = (char *)malloc(sizeof(char) * len)))
		{
			ft_map_free(map, x);
			return (0);
		}
		ft_map_str(map, i, len, x);
		i++;
	}
	free(map->buff);
	return (1);
}