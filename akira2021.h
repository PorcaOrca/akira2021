/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   akira2021.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:32:58 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/24 17:47:55 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AKIRA2021_H
# define AKIRA2021_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>

// param struct definition (everything goes there)

typedef struct	s_img
{
	void	*ptr;
	char	*addr;
	int		bxp;
	int		sizel;
	int		endian;
}				t_img;


typedef	struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct	s_rayc
{
	t_vector	*pos;
	t_vector	*dir;
	t_vector	*plane;
}				t_rayc;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	int			win_x;
	int			win_y;
	t_rayc		*vectors;
	t_img		*img;
	char		**map;
	int			lag;
}				t_param;


// maps struct definition

typedef struct		s_map
{
	char	**matrix;
	char	*buff;
	char	*mapfile;
	int		count;
}					t_map;

// image management prototipes

int		ft_color(double shade, int r, int g, int b);
void	ft_img_fill(t_param *param);
t_img	*ft_img_init(t_param *param);
void	ft_img_pixel_put(t_img *img, int x, int y, int color);


// maps functions prototipes

int		ft_map_fill(t_map *map);
void	ft_map_free(t_map *map, int x);
char	**ft_map_matrix(char *mapfile);
int		ft_map_read(t_map *map);
int		ft_map_size(t_map *map);
void	ft_map_str(t_map *map, int y, int len, int x);

// event management prototipes

int		ft_close(int keycode, t_param *param);
int		ft_new_frame(t_param *param);

// main prototipes

int		ft_init(t_param *param);

// write a string cause i am lazy
void	debug();
void	debugstr(char *str);
// write nbr cause i hate printf
void	debugint(int nbr);

#endif