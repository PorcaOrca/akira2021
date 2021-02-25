/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:50:55 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/25 09:08:53 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_map_str(t_map *map, int y, int len, int x)
{
	map->buff[y] = '\0';
	while (len >= 0)
	{
		map->matrix[x][len] = map->buff[y];
		len--;
		y--;
	}
}