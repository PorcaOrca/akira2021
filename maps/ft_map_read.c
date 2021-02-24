/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:30:39 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/23 18:16:20 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

/*
** read from the specified file and stores all the content in a allocated string
*/

int		ft_map_read(t_map *map)
{
	int		fd;
	int		i;
	int		ret;

	if (!ft_map_size(map))
		return(-1);
	i = 0;
	map->count = 1;
	if ((fd = open(map->mapfile, O_RDONLY)) < 0)
	{
		free(map->buff);
		return (-1);
	}
	while ((ret = read(fd, &map->buff[i], 1)) > 0)
		if (map->buff[i++] == '\n')
			map->count++;
	close(fd);
	if (ret < 0)
	{
		free(map->buff);
		return (-1);
	}
	return (0);
}