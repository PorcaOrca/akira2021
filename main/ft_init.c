/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:15:35 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/24 09:58:55 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		ft_init(t_param *param)
{
	param->win_x = 960;
	param->win_y = 540;
	param->vectors = (t_rayc *)malloc(sizeof(t_rayc *));
	param->vectors->dir = (t_vector *)malloc(sizeof(t_vector));
	param->vectors->pos = (t_vector *)malloc(sizeof(t_vector));
	param->vectors->plane = (t_vector *)malloc(sizeof(t_vector));

	param->vectors->pos->x = 22;
	param->vectors->pos->y = 12;
	param->vectors->dir->x = -1;
	param->vectors->dir->y = 0;
	param->vectors->plane->x = 0;
	param->vectors->plane->y = 0.66;
	return (1);
}

  	//	double posX = 22, posY = 12;  //x and y start position
 	//	double dirX = -1, dirY = 0; //initial direction vector
  	//	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane