/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:15:35 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/02 08:54:18 by lodovico         ###   ########.fr       */
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

	// texture struct init

	param->texture = (t_texture *)malloc(sizeof(t_texture));
	
	// texture init

	ft_txt_init(param, txt_1, "img_manage/textures/texture_files/txt_wall_wood.xpm");
	ft_txt_init(param, txt_f_1, "img_manage/textures/texture_files/txt_floor_dark.xpm");

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
	lagi = 50000;
	lagc = lagi;
	movspeed = 0.5;
	rotspeed = 0.05;

	return (1);
}
