/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:19:03 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/24 15:08:30 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_img_fill(t_param *param)
{
	int			x;
	t_vector	raydir;
	double		camerax;

	x = 0;
	while (x < param.win_x)
	{
		camerax = (2 * x) / (param->win_x - 1);
		raydir.x = param->vectors->dir->x + (param->vectors->plane->x * camerax);
		raydir.y = param->vectors->dir->y + (param->vectors->plane->y * camerax);
		
		x++;
	}
}