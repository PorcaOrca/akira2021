/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:57:41 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/04 17:58:49 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_cub_init(t_temp *temp, char *mapfile)
{
	int		fd;
	char	*str;
	char	**matrix;
	int		i;
	int		j;
	int		ret;
	int		map_line;

	int		r;
	int		g;
	int		b;
	map_line = 1;
	temp->sprite_q = 0;
	if ((fd = open(mapfile, O_RDONLY)) < 0)
		return (0);
	while (*str != '1' && ret)
	{
		ret = get_next_line(fd, &temp);
		if (*str == 'R')
		{
			matrix = ft_split(str, ' ');
			temp->width = ft_atoi(matrix[1]);
			temp->height = ft_atoi(matrix[2]);
			i = 0;
			while (matrix[i])
			{
				free(matrix[i]);
				i++;
			}
			free(matrix);
		}
		else if (*str == 'F')
		{
			matrix = ft_split(str, ' ');
			r = ft_atoi(matrix[1]);
			g = ft_atoi(matrix[2]);
			b = ft_atoi(matrix[3]);
			temp->floor_color = ft_color(0, r, g, b);
			i = 0;
			while (matrix[i])
			{
				free(matrix[i]);
				i++;
			}
			free(matrix);
		}
		else if (*str == 'C')
		{
			matrix = ft_split(str, ' ');
			r = ft_atoi(matrix[1]);
			g = ft_atoi(matrix[2]);
			b = ft_atoi(matrix[3]);
			temp->ceiling_color = ft_color(0, r, g, b);
			i = 0;
			while (matrix[i])
			{
				free(matrix[i]);
				i++;
			}
			free(matrix);
		}
		else if (!ft_strncmp("NO", str, 2))
		{
			matrix = ft_split(str, ' ');
			temp->texture1 = matrix[1];
			free(matrix[0]);
			free(matrix);
		}
		else if (!ft_strncmp("EA", str, 2))
		{
			matrix = ft_split(str, ' ');
			temp->texture2 = matrix[1];
			free(matrix[0]);
			free(matrix);
		}
		else if (!ft_strncmp("WE", str, 2))
		{
			matrix = ft_split(str, ' ');
			temp->texture3 = matrix[1];
			free(matrix[0]);
			free(matrix);
		}
		else if (!ft_strncmp("SO", str, 2))
		{
			matrix = ft_split(str, ' ');
			temp->texture4 = matrix[1];
			free(matrix[0]);
			free(matrix);
		}
	}
	while (ret)
	{
		ret = get_next_line(fd, &temp);
		map_line++;
	}
	matrix = (char *)malloc(sizeof(char *) * (map_line + 1));
	matrix[map_line] = NULL;
	while (*str != '1' && ret)
		ret = get_next_line(fd, &temp);
	matrix[0] = temp;
	i = 1;
	while (ret)
	{
		j = 0;
		ret = get_next_line(fd, &matrix[i]);
		while (matrix[i][j])
		{
			if (matrix[i][j] == '2')
				temp->sprite_q++;
			if (matrix[i][j] == 'N')
			{
				temp->position[0] = j;
				temp->position[1] = i;
			}
			if (matrix[i][j] == ' ')
				matrix[i][j] = '0';
			j++;
		}
		i++;
	}
	temp->temp_map = matrix;
	close(fd);
}