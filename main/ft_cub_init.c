/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:57:41 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/05 09:53:17 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_cub_init(t_temp *temp, char *mapfile)
{
	int		fd;
	char	*str;
	char	**matrix;
	char	*map_str[256];
	int		i;
	int		j;
	int		ret;
	int		map_line;

	int		r;
	int		g;
	int		b;
	ret = 1;
	map_line = 0;
	temp->sprite_q = 0;
	fd = open(mapfile, O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &str);
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
		else if (*str == '1')
		{
			map_str[map_line] = str;
			map_line = 1;
			break;
		}
		free(str);
	}
	while (ret)
	{
		ret = get_next_line(fd, &str);
		map_str[map_line] = str;
		map_line++;
	}
	close(fd);
	matrix = (char **)malloc(sizeof(char *) * (map_line + 1));
	matrix[map_line] = NULL;

	i = 0;
	while (i < map_line)
	{
		j = 0;
		matrix[i] = map_str[i]; 
		while (matrix[i][j])
		{
			if (matrix[i][j] == '2')
				temp->sprite_q++;
			if (matrix[i][j] == 'N')
			{
				matrix[i][j] = '0';
				temp->position[0] = j;
				temp->position[1] = i;
			}
			if (matrix[i][j] == ' ')
				matrix[i][j] = '0';
			if (matrix[i][j] == '2')
				temp->sprite_q++;
			j++;

		}
		i++;
	}
	temp->temp_map = matrix;
}

/*
int main()
{
	t_temp temp;
	int i = 0;
	
	ft_cub_init(&temp, "./maps/map_files/map.cub");
	debugint(temp.height);
	debugint(temp.width);
	debugstr(temp.texture1);
	debugstr(temp.texture2);
	debugstr(temp.texture3);
	debugstr(temp.texture4);
	debugint(temp.position[0]);
	debugint(temp.position[1]);
	while (temp.temp_map[i])
	{
		debugstr(temp.temp_map[i]);
		i++;
	}
}
*/