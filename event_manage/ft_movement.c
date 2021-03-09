/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:16:21 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/09 11:04:48 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"
#include <math.h>

void		ft_movement(t_param *param)
{
	double		tempdirX;
	double		tempplaneX;
	double		coll;

	coll = 0.1;
	//move forward
	if (param->keys->mv_up)
	{
		if (Wmap[(int)(posY - coll)][(int)((posX + (dirX * movspeed) - coll))] == '0' && Wmap[(int)(posY + coll)][(int)((posX + (dirX * movspeed) + coll))] == '0' &&
			Wmap[(int)(posY + coll)][(int)((posX + (dirX * movspeed) - coll))] == '0' && Wmap[(int)(posY - coll)][(int)((posX + (dirX * movspeed) + coll))] == '0')
			posX += (dirX * movspeed);
		if (Wmap[(int)(posY + (dirY * movspeed) - coll)][(int)(posX - coll)] == '0' && Wmap[(int)(posY + (dirY * movspeed) + coll)][(int)(posX + coll)] == '0' &&
			Wmap[(int)(posY + (dirY * movspeed) - coll)][(int)(posX + coll)] == '0' && Wmap[(int)(posY + (dirY * movspeed) + coll)][(int)(posX - coll)] == '0')
			posY += (dirY * movspeed);
	}
	// strafe right
	if (param->keys->mv_down)
	{
		if (Wmap[(int)(posY - coll)][(int)((posX + (planeX * movspeed) - coll))] == '0' && Wmap[(int)(posY + coll)][(int)((posX + (planeX * movspeed) + coll))] == '0' &&
			Wmap[(int)(posY + coll)][(int)((posX + (planeX * movspeed) - coll))] == '0' && Wmap[(int)(posY - coll)][(int)((posX + (planeX * movspeed) + coll))] == '0')
			posX += (planeX * movspeed);
		if (Wmap[(int)(posY + (planeY * movspeed) - coll)][(int)(posX - coll)] == '0' && Wmap[(int)(posY + (planeY * movspeed) + coll)][(int)(posX + coll)] == '0' &&
			Wmap[(int)(posY + (planeY * movspeed) - coll)][(int)(posX + coll)] == '0' && Wmap[(int)(posY + (planeY * movspeed) + coll)][(int)(posX - coll)] == '0')
			posY += (planeY * movspeed);
	}
	// strafe left
	if (param->keys->mv_left)
	{
		if (Wmap[(int)(posY - coll)][(int)((posX - (planeX * movspeed) - coll))] == '0' && Wmap[(int)(posY + coll)][(int)((posX - (planeX * movspeed) + coll))] == '0' &&
			Wmap[(int)(posY + coll)][(int)((posX - (planeX * movspeed) - coll))] == '0' && Wmap[(int)(posY - coll)][(int)((posX - (planeX * movspeed) + coll))] == '0')
			posX -= (planeX * movspeed);
		if (Wmap[(int)(posY - (planeY * movspeed) - coll)][(int)(posX - coll)] == '0' && Wmap[(int)(posY - (planeY * movspeed) + coll)][(int)(posX + coll)] == '0' &&
			Wmap[(int)(posY - (planeY * movspeed) - coll)][(int)(posX + coll)] == '0' && Wmap[(int)(posY - (planeY * movspeed) + coll)][(int)(posX - coll)] == '0')
			posY -= (planeY * movspeed);
	}
	//move backward
	if (param->keys->mv_right)
	{
		if (Wmap[(int)(posY - coll)][(int)((posX - (dirX * movspeed) - coll))] == '0' && Wmap[(int)(posY + coll)][(int)((posX - (dirX * movspeed) + coll))] == '0' &&
			Wmap[(int)(posY + coll)][(int)((posX - (dirX * movspeed) - coll))] == '0' && Wmap[(int)(posY - coll)][(int)((posX - (dirX * movspeed) + coll))] == '0')
			posX -= dirX * movspeed;
		if (Wmap[(int)(posY - (dirY * movspeed) + coll)][(int)(posX + coll)] == '0' && Wmap[(int)(posY - (dirY * movspeed) - coll)][(int)(posX + coll)] == '0' &&
			Wmap[(int)(posY - (dirY * movspeed) + coll)][(int)(posX - coll)] == '0' && Wmap[(int)(posY - (dirY * movspeed) - coll)][(int)(posX - coll)] == '0')
			posY -= dirY * movspeed;
	}
	// right rotation
	if (param->keys->rt_right)
		{
			tempdirX = dirX;
			tempplaneX = planeX;
			dirX = (tempdirX * cos(-rotspeed)) - (dirY * sin(-rotspeed));
			dirY = (tempdirX * sin(-rotspeed)) + (dirY * cos(-rotspeed));
			planeX = (tempplaneX * cos(-rotspeed)) - (planeY * sin(-rotspeed));
			planeY = (tempplaneX * sin(-rotspeed)) + (planeY * cos(-rotspeed));
		}
	// left rotation

	if (param->keys->rt_left)
		{
			tempdirX = dirX;
			tempplaneX = planeX;
			dirX = (dirX * cos(rotspeed)) - (dirY * sin(rotspeed));
			dirY = (tempdirX * sin(rotspeed)) + (dirY * cos(rotspeed));
			planeX = (planeX * cos(rotspeed)) - (planeY * sin(rotspeed));
			planeY = (tempplaneX * sin(rotspeed)) + (planeY * cos(rotspeed));
		}
}
