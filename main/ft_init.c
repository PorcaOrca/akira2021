/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:15:35 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/02 15:40:16 by lspazzin         ###   ########.fr       */
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

	// raycasting vectors
	posX = 4;
	posY = 4;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;

	param->settings = (t_settings *)malloc(sizeof(t_settings));
	// settings
	winX = 1920;
	winY = 1080;
	lagi = 0;
	lagc = lagi;
	movspeed = 0.5;
	rotspeed = 0.1;

	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, winX, winY, "akira2021");

	// texture struct init

	param->texture = (t_texture *)malloc(sizeof(t_texture));

	// texture init

	txt_1 = ft_txt_init(param, "img_manage/textures/texture_files/txt_wall_stone.xpm");
	txt_f_1 = ft_txt_init(param, "img_manage/textures/texture_files/txt_floor_tile.xpm");
	return (1);
}
