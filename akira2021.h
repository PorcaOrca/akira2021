/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   akira2021.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:32:58 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/09 11:06:52 by lodovico         ###   ########.fr       */
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
# include "libft/libft.h"

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
# define f_trgb		param->settings->floor_trgb
# define c_trgb		param->settings->ceiling_trgb
# define Wmap		param->map
# define txt_1		param->texture->texture1
# define txt_2		param->texture->texture2
# define txt_3		param->texture->texture3
# define txt_4		param->texture->texture4
# define txt_spr	param->texture->sprite
# define txt_sb		param->texture->skybox
# define txt_f_1	param->texture->floor_1
# define fl_data	param->floor_data
# define wl_data	param->wall_data
# define sp_data	param->sprite_data
# define trgb		param->common_data->color_trgb
# define i_x		param->common_data->iterator_x
# define i_y		param->common_data->iterator_y
# define txtX		param->common_data->texture_X
# define txtY		param->common_data->texture_Y

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
	int			floor_trgb;
	int			ceiling_trgb;
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
	t_txt	*texture2;
	t_txt	*texture3;
	t_txt	*texture4;
	t_txt	*floor_1;
	t_txt	*skybox;
	t_txt	*sprite;
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
	t_txt		*txt;
	double		camerax;
	double		walldist;
	int 		stepx;
    int			stepy;
    int 		side;
	int			mapx;
	int			mapy;
	int			lineh;
	int			ystart;
	int			yend;
	double		txtpos;
	double		wallX;
	double		step;
	int			hit;
}					t_wl_data;

// common data struct
typedef struct		s_common
{
	int		iterator_x;
	int		iterator_y;
	int		color_trgb;
	int		texture_X;
	int		texture_Y;
}					t_common;

// sprite struct

typedef struct		s_spr
{
	double	s_pos_x;
	double	s_pos_y;
	t_txt	*s_txt;
}					t_spr;

// sprite data struct

typedef struct		s_sp_data
{
	t_spr	*sp_arr;
    int		i;
    double	*zbuffer;
    int		*order;
    double	*dist;
    double	spriteX;
    double	spriteY;
    double	invdet;
    double	transX;
    double	transY;
    int		spscreenX;
    int		spriteH;
    int		spriteW;
    int		spstartY;
    int		spendY;
    int		spstartX;
    int		spendX;
	int		stripe;
	int		d;
}					t_sp_data;

// key status struct

typedef struct		t_key_stat
{
	int		mv_up;
	int		mv_down;
	int		mv_left;
	int		mv_right;
	int		rt_left;
	int		rt_right;
}					t_key_stat;


// all the parameter are here btw....it' s not working
typedef struct	s_param
{
	void		*mlx;
	void		*win;
	t_rayc		*vectors;
	t_img		*img;
	t_settings	*settings;
	t_texture	*texture;
	t_common	*common_data;
	t_fl_data	*floor_data;
	t_wl_data	*wall_data;
	t_sp_data	*sprite_data;
	t_key_stat	*keys;
	int			sprite_num;
	char		**map;
}				t_param;

// temp struct for the initial read

typedef struct		s_temp
{
	char	*texture1;
	char	*texture2;
	char	*texture3;
	char	*texture4;
	char	**temp_map;
	int		position[2];
	int		sprite_q;
	int		width;
	int		height;
	int		floor_color;
	int		ceiling_color;
	double	t_dirX;
	double	t_dirY;
	double	t_planeX;
	double	t_planeY;
}					t_temp;
// maps struct definition

typedef struct		s_map
{
	char	**matrix;
	char	*buff;
	char	*mapfile;
	int		count;
}					t_map;

// image management prototipes

int			ft_color(double shade, int r, int g, int b);
void		ft_img_fill(t_param *param);
t_img		*ft_img_init(t_param *param);
void		ft_img_pixel_put(t_img *img, int x, int y, int color);
void		ft_fill_line(t_param *param);
void		ft_img_floor(t_param *param);
void		ft_fill_px(t_param *param);
void		ft_fill_column(t_param *param);
void		ft_calc_column(t_param *param);
void		ft_DDA(t_param *param);
void		ft_step(t_param *param);
void		ft_deltadist(t_wl_data *data);
void		ft_img_wall(t_param *param);
void		ft_sprite_sort(int	*order, double *dist, int q);
void		ft_sprite(t_param *param);



// texture management prototipes

t_txt		*ft_txt_init(t_param *param, char *path);
int			ft_get_txtcolor(t_img *img, int x, int y);


// event management prototipes

void		ft_close(t_param *param);
int			ft_new_frame(t_param *param);
void		ft_movement(t_param *param);
int			ft_key_release(int keycode, t_param *param);
int			ft_key_press(int keycode, t_param *param);

// main prototipes

int			ft_init(t_param *param, t_temp *temp);
void		ft_cub_init(t_temp *temp, char *mapfile);

// utils prototipes
int			get_next_line(int fd, char **line);

// write a string cause i am lazy
void	debug();
void	debugstr(char *str);
// write nbr cause i hate printf
void	debugint(int nbr);

#endif
