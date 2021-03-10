/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:57:41 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/10 12:08:35 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_temp_init(t_temp *temp)
{
	temp->sprite_q = 0;
	temp->floor_color = 0xFFFFFFFF;
	temp->ceiling_color = 0xFFFFFFFF;
	temp->t_dirX = 0;
	temp->t_dirY = 0;
	temp->t_planeX = 0;
	temp->t_planeY = 0;
	temp->texture1 = NULL;
	temp->texture2 = NULL;
	temp->texture3 = NULL;
	temp->texture4 = NULL;
	temp->position[0] = 0;
	temp->position[1] = 0;
	temp->width = 0;
	temp->height = 0;
	temp->temp_map = NULL;
}

void	ft_free_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int		ft_resolution(t_temp *temp, char *str)
{
	char	**matrix;
	int		i;
	
	i = 0;
	matrix = ft_split(str, ' ');
	if (!matrix)
		return (0);
	while (matrix[i])
		i++;
	if (i != 3 || ft_strncmp(matrix[0], "R", 2))
	{
		ft_free_matrix(matrix);
		return (0);
	}
	temp->width = ft_atoi(matrix[1]);
	temp->height = ft_atoi(matrix[2]);
	ft_free_matrix(matrix);
	return (1);
}

int			ft_back_color(char **matrix)
{
	int		r;
	int		g;
	int		b;
	int		color;

	r = ft_atoi(matrix[1]);
	g = ft_atoi(matrix[2]);
	b = ft_atoi(matrix[3]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0xFFFFFFFF);
	color = ft_color(0, r, g, b);
	ft_free_matrix(matrix);
	return (color);
}

int			ft_background(char *str)
{
	int		i;
	char	**matrix;
	int		color;
	
	matrix = ft_split(str, ' ');
	if (!matrix)
		return (0xFFFFFFFF);
	while (matrix[i])
		i++;
	if (i != 4 || (ft_strncmp(matrix[0], "F", 2)
		&& ft_strncmp(matrix[0], "C", 2)))
	{
		ft_free_matrix(matrix);
		return (0xFFFFFFFF);
	}
	color = ft_back_color(matrix);
	ft_free_matrix(matrix);
	return (color);
}

char		*ft_txt_wall(char *str)
{
	char 	**matrix;
	char	*temp_str;
	int		i;
	
	i = 0;
	matrix = ft_split(str, ' ');
	if (!matrix)
		return (NULL);
	while (matrix[i])
		i++;
	if (i != 2 || (ft_strncmp(matrix[0], "NO", 3)
				&& ft_strncmp(matrix[0], "WE", 3)
				&& ft_strncmp(matrix[0], "SO", 3)
				&& ft_strncmp(matrix[0], "EA", 3)))
		{
		ft_free_matrix(matrix);
		return (NULL);
		}	
	temp_str = matrix[1];
	free(matrix[0]);
	free(matrix);
	return (temp_str);
}

void		ft_element_select(t_temp *temp, char *str)
{
	if (*str == 'R')
		ft_resolution(temp, str);
	else if (*str == 'F')
		temp->floor_color = ft_background(str);
	else if (*str == 'C')
		temp->ceiling_color = ft_background(str);
	else if (!ft_strncmp("WE", str, 2))
		temp->texture1 = ft_txt_wall(str);
	else if (!ft_strncmp("NO", str, 2))
		temp->texture2 = ft_txt_wall(str);
	else if (!ft_strncmp("EA", str, 2))
		temp->texture3 = ft_txt_wall(str);
	else if (!ft_strncmp("SO", str, 2))
		temp->texture4 = ft_txt_wall(str);
}

void		ft_spawn(t_temp *temp, char position)
{
	if (position == 'N')
	{
		temp->t_dirY = -1;
		temp->t_planeX = 0.66;
	}
	else if (position == 'S')
	{
		temp->t_dirY = 1;
		temp->t_planeX = -0.66;
	}
	else if (position == 'E')
	{
		temp->t_dirX = 1;
		temp->t_planeY = 0.66;
	}
	else if (position == 'W')
	{
		temp->t_dirX = -1;
		temp->t_planeY = -0.66;
	}
}

void		ft_map_fill(char **matrix, t_temp *temp, t_list *line, int map_size)
{
	int		i;
	int		j;
	t_list	*lst_temp;
	
	i = 0;
	while (i < map_size)
	{
		j = 0;
		matrix[i] = (char *)line->content;
		while (matrix[i][j])
		{
			ft_spawn(temp, matrix[i][j]);
			if (matrix[i][j] == 'W' || matrix[i][j] == 'S' || matrix[i][j] == 'E' || matrix[i][j] == 'N')
			{
				temp->position[0] = j;
				temp->position[1] = i;
				matrix[i][j] = '0';
			}	
			if (matrix[i][j] == ' ')
				matrix[i][j] = '0';
			if (matrix[i][j] == '2')
				temp->sprite_q++;
			j++;

		}
		lst_temp = line->next;
		free(line);
		line = lst_temp;
		i++;
	}
}

char		**ft_map(t_temp *temp, int fd, char *str)
{
	t_list		*line;
	t_list		*new;
	int			ret;
	char		**matrix;
	int			map_size;
	
	ret = 1;
	line = ft_lstnew(str);
	while (ret)
	{
		ret = get_next_line(fd, &str);
		new = ft_lstnew(str);
		ft_lstadd_back(&line, new);
	}
	close(fd);
	map_size = ft_lstsize(line);
	matrix = (char **)malloc(sizeof(char *) * (map_size + 1));
	matrix[map_size] = NULL;
	ft_map_fill(matrix, temp, line, map_size);
	return (matrix);
}

void		ft_cub_init(t_temp *temp, char *mapfile)
{
	int		fd;
	char	*str;
	int		ret;

	ret = 1;
	ft_temp_init(temp);
	fd = open(mapfile, O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &str);
		ft_element_select(temp, str);
		if (*str == '1')
			break;
		free(str);
	}
	temp->temp_map = ft_map(temp, fd, str);
	close(fd);
}


/*
int		main(void)
{
	int		i;
	t_temp 	temp;
	
	i = 0;
	ft_cub_init(&temp, "./maps/map_files/map_trip.cub");
	while (temp.temp_map[i])
	{
		debugstr(temp.temp_map[i]);
		i++;
	}
}

*/