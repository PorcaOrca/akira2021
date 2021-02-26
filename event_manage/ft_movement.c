/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:16:21 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/26 18:00:35 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"
#include <math.h>

int		ft_movement(int keycode, t_param *param)
{
	double		tempdirX;
	double		tempplaneX;

	//move forward
	if (keycode == 119 || keycode == 13)
	{
		if (Wmap[(int)(posY + 0.5)][(int)((posX + (dirX * movspeed)) + 0.5)] == '0')
			posX += (dirX * movspeed);
		if (Wmap[(int)(posY + (dirY * movspeed) + 0.5)][(int)(posX + 0.5)] == '0')
			posY += (dirY * movspeed);
	}

	//move backward
	if (keycode == 115 || keycode == 1)
	{
		if (param->map[(int)(posY - 0.5)][(int)(posX - (dirX * movspeed) - 0.5)] == '0')
			posX -= dirX * movspeed;
		if (param->map[(int)(posY - (dirY * movspeed) - 0.5)][(int)(posX - 0.5)] == '0')
			posY -= dirY * movspeed;
	}
	// rotating visual

	// right rotation
	if (keycode == 100 || keycode == 2)
		{
			tempdirX = dirX;
			tempplaneX = planeX;
			dirX = (tempdirX * cos(-rotspeed)) - (dirY * sin(-rotspeed));
			dirY = (tempdirX * sin(-rotspeed)) + (dirY * cos(-rotspeed));
			planeX = (tempplaneX * cos(-rotspeed)) - (planeY * sin(-rotspeed));
			planeY = (tempplaneX * sin(-rotspeed)) + (planeY * cos(-rotspeed));
		}
	// left rotation

	if (keycode == 97 || keycode == 0)
		{
			tempdirX = dirX;
			tempplaneX = planeX;
			dirX = (dirX * cos(rotspeed)) - (dirY * sin(rotspeed));
			dirY = (tempdirX * sin(rotspeed)) + (dirY * cos(rotspeed));
			planeX = (planeX * cos(rotspeed)) - (planeY * sin(rotspeed));
			planeY = (tempplaneX * sin(rotspeed)) + (planeY * cos(rotspeed));
		}
	return (keycode);
}
