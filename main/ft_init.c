/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:15:35 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/26 17:01:10 by lodovico         ###   ########.fr       */
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

	// raycasting vectors
	posX = 4;
	posY = 4;
	dirX = 1;
	dirY = 0;
	planeX = 0;
	planeY = 1;

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
