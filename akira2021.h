/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   akira2021.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:32:58 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/02 15:40:00 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AKIRA2021_H
# define AKIRA2021_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <string.h>

// macros definition

# define posX		param->vectors->pos->x
# define posY		param->vectors->pos->y
# define dirX		param->vectors->dir->x
# define dirY		param->vectors->dir->y
# define planeX		param->vectors->plane->x
# define planeY		param->vectors->plane->y
# define movspeed	param->settings->movement
# define rotspeed	param->settings->rotation
# define lagi		param->settings->lag_iterator
# define lagc		param->settings->lag_count
# define winX		param->settings->window_size_x
# define winY		param->settings->window_size_y
# define Wmap		param->map
# define txt_1		param->texture->texture1
# define txt_sb_1	param->texture->skybox_1
# define txt_f_1	param->texture->floor_1

// param structs definition (everything goes there)

// settings struct
typedef struct	s_settings
{
	double		movement;
	double		rotation;
	int			lag_iterator;
	int			lag_count;
	int			window_size_x;
	int			window_size_y;
}				t_settings;

// img datas struct
typedef struct	s_img
{
	void		*ptr;
	char		*addr;
	int			bxp;
	int			sizel;
	int			endian;
}				t_img;

// textures struct imagine all the imagine

typedef	struct	s_txt
{
	t_img	*txt_data;
	int		texture_Width;
	int		texture_High;
}				t_txt;

typedef struct	s_texture
{
	t_txt	*texture1;
	t_txt	*skybox_1;
	t_txt	*floor_1;
}				t_texture;




// model for vector struct
typedef	struct	s_vector
{
	double		x;
	double		y;
}				t_vector;

// raycasting data struct
typedef struct	s_rayc
{
	t_vector	*pos;
	t_vector	*dir;
	t_vector	*plane;
}				t_rayc;

// all the parameter are here btw....it' s not working
typedef struct	s_param
{
	void		*mlx;
	void		*win;
	t_rayc		*vectors;
	t_img		*img;
	t_settings	*settings;
	t_texture	*texture;
	char		**map;
}				t_param;

// floor data struct
typedef struct		s_fl_data
{
	t_vector	rdirL;
	t_vector	rdirR;
	t_vector	floorL;
	t_vector	fstep;
	int			pos;
	int			cellX;
	int			cellY;
	double		posZ;
	double		rowdist;
}					t_fl_data;

// wall data struct
typedef struct		s_wl_data
{
	t_vector	raydir;
	t_vector	sidedist;
	t_vector	deltadist;
	double		walldist;
	int 		stepx;
    int			stepy;
    int 		side;
	int			mapx;
	int			mapy;
	int			lineh;
	int			ystart;
	int			yend;
	int			x;
}					t_wl_data;


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
void	ft_fill_line(t_param *param, t_fl_data *data, int y);
void	ft_img_floor(t_param *param);
void	ft_fill_px(t_param *param, t_wl_data *data, t_txt *txt,
					int txtX, double step);
void	ft_fill_column(t_param *param, t_wl_data *data, t_txt *txt);
void	ft_calc_column(t_param *param, t_wl_data *data);
void	ft_DDA(t_param *param, t_wl_data *data);
void	ft_step(t_param *param, t_wl_data *data);
void	ft_deltadist(t_wl_data *data);
void	ft_img_wall(t_param *param);

// texture management prototipes

t_txt	*ft_txt_init(t_param *param, char *path);
int		ft_get_txtcolor(t_img *img, int x, int y);


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
int		ft_movement(int keycode, t_param *param);

// main prototipes

int		ft_init(t_param *param);

// write a string cause i am lazy
void	debug();
void	debugstr(char *str);
// write nbr cause i hate printf
void	debugint(int nbr);

#endif
