/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:10:23 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/25 09:08:48 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

/*
** get file dimention and allocates memory for all the char in the file
** to add a control function to check for non accepted char
*/

int		ft_map_size(t_map *map)
{
	int		fd;
	int		ret;
	int		fsize;
	char	tmp[1];
	
	fsize = 0;
	if ((fd = open(map->mapfile, O_RDONLY)) < 0)
		return (0);
	while ((ret = read(fd, tmp, 1)) > 0)
		fsize++;
	if (ret < 0)
		return (0);
	map->buff = (char *)malloc((sizeof(char) * (fsize + 1)));
	if (!map->buff)
		return (0);
	close(fd);
	return (fsize);
}