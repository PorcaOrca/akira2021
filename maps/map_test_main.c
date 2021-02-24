/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 08:53:49 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/23 18:14:01 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

/*
char	**ft_map_init(char *mapfile)
{
	char	**map;
	int 	fd;
	char 	buff[1024 * 1024];
	int		i;
	int		count;
	int		x;
	int		y;
	int		len;
	
	i = 0;
	count = 1;
	// read file and store it in array buff, count equals the number of line
	fd = open(mapfile, O_RDONLY);
	while ((read(fd, &buff[i], 1)) > 0)
	{
		if (buff[i] == '\n')
			count++;
		i++;
	}
	//printf("%d", count);
	//buff[i] = '\0';
	close(fd);
	// allocates memory for the pointers to the lines of matrix map
	map = (char **)malloc(sizeof(char *) * (count + 1));
	if (!map)
		return (NULL);
	map[count] = NULL;
	i = 0;
	x = 0;
	// allocate and fill each line
	while (count > x)
	{
		len = 0;
		while (buff[i] != '\n' && buff[i])
		{
			len++;
			i++;
		}
		map[x] = (char *)malloc(sizeof(char *) * (len));
		if (!map[x])
		{
			ft_freeme(map);
			return (NULL);
		}
		y = i;
		buff[i] = '\0';
		while (len >= 0)
		{
			map[x][len] = buff[y];
			len--;
			y--;
		}
		x++;
		i++;
	}
	return (map);
}*/


// check the read
int		main()
{
	int		x;
	int		y;
	char	**map;
	
	x = 0;
	y = 0;
	map = ft_map_matrix("maps/map_files/map.cub");
	while (map[x])
	{
		y = 0;
		write(1, "|", 1);
		while (map[x][y])
		{
			write(1, &map[x][y], 1);
			y++;
		}
		write(1, "|", 1);
		write(1, "\n", 1);
		x++;
	}
}