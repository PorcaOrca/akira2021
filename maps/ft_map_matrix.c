/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:11:20 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/23 18:16:36 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

char	**ft_map_matrix(char *mapfile)
{
	t_map		map;
	
	map.mapfile = mapfile;
	if (ft_map_read(&map) < 0)
		return (NULL);
	map.matrix = (char **)malloc(sizeof(char *) * (map.count + 1));
	if (!map.matrix)
		return (NULL);
	map.matrix[map.count] = NULL;
	if (!ft_map_fill(&map))
		return (NULL);
	return (map.matrix);
}