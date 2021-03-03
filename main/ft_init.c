/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:15:35 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/03 10:58:34 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		ft_init(t_param *param)
{
	// vectors allocation

	param->vectors = (t_rayc *)malloc(sizeof(t_rayc));
	param->vectors->dir = (t_vector *)malloc(sizeof(t_vector));
	param->vectors->pos = (t_vector *)malloc(sizeof(t_vector));
	param->vectors->plane = (t_vector *)malloc(sizeof(t_vector));

	fl_data = (t_fl_data *)malloc(sizeof(t_fl_data));
	wl_data = (t_wl_data *)malloc(sizeof(t_wl_data));
	param->common_data = (t_common *)malloc(sizeof(t_common));
	// raycasting vectors
	posX = 4;
	posY = 4;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;

	param->settings = (t_settings *)malloc(sizeof(t_settings));
	// settings
	winX = 1080;
	winY = 720;
	lagi = 0;
	lagc = lagi;
	movspeed = 0.2;
	rotspeed = 0.1;

	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, winX, winY, "akira2021");

	// texture struct init

	param->texture = (t_texture *)malloc(sizeof(t_texture));

	// texture init

	txt_1 = ft_txt_init(param, "img_manage/textures/texture_files/txt_wall_stone.xpm");
	txt_2 = ft_txt_init(param, "img_manage/textures/texture_files/txt_wall_brick.xpm");
	txt_3 = ft_txt_init(param, "img_manage/textures/texture_files/txt_wall_sand.xpm");
	txt_4 = ft_txt_init(param, "img_manage/textures/texture_files/txt_wall_wood.xpm");
	txt_f_1 = ft_txt_init(param, "img_manage/textures/texture_files/txt_floor_dark.xpm");
	return (1);
}
