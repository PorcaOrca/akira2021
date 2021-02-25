/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:15:35 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/25 09:12:17 by lodovico         ###   ########.fr       */
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
	param->lag = 0;
	param->vectors->pos->x = 9;
	param->vectors->pos->y = 4;
	param->vectors->dir->x = -1;
	param->vectors->dir->y = 0;
	param->vectors->plane->x = 0;
	param->vectors->plane->y = 0.90;
	return (1);
}