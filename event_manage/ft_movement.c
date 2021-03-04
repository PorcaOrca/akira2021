/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:16:21 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/03 16:21:00 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"
#include <math.h>

int		ft_movement(int keycode, t_param *param)
{
	double		tempdirX;
	double		tempplaneX;
	double		coll;

	coll = 0.1;
	//move forward
	if (keycode == 119 || keycode == 13)
	{
		if (Wmap[(int)(posY - coll)][(int)((posX + (dirX * movspeed) - coll))] == '0' && Wmap[(int)(posY + coll)][(int)((posX + (dirX * movspeed) + coll))] == '0' &&
			Wmap[(int)(posY + coll)][(int)((posX + (dirX * movspeed) - coll))] == '0' && Wmap[(int)(posY - coll)][(int)((posX + (dirX * movspeed) + coll))] == '0')
			posX += (dirX * movspeed);
		if (Wmap[(int)(posY + (dirY * movspeed) - coll)][(int)(posX - coll)] == '0' && Wmap[(int)(posY + (dirY * movspeed) + coll)][(int)(posX + coll)] == '0' &&
			Wmap[(int)(posY + (dirY * movspeed) - coll)][(int)(posX + coll)] == '0' && Wmap[(int)(posY + (dirY * movspeed) + coll)][(int)(posX - coll)] == '0')
			posY += (dirY * movspeed);
	}
	// strafe right
	if (keycode == 100 || keycode == 13)
	{
		if (Wmap[(int)(posY - coll)][(int)((posX + (planeX * movspeed) - coll))] == '0' && Wmap[(int)(posY + coll)][(int)((posX + (planeX * movspeed) + coll))] == '0' &&
			Wmap[(int)(posY + coll)][(int)((posX + (planeX * movspeed) - coll))] == '0' && Wmap[(int)(posY - coll)][(int)((posX + (planeX * movspeed) + coll))] == '0')
			posX += (planeX * movspeed);
		if (Wmap[(int)(posY + (planeY * movspeed) - coll)][(int)(posX - coll)] == '0' && Wmap[(int)(posY + (planeY * movspeed) + coll)][(int)(posX + coll)] == '0' &&
			Wmap[(int)(posY + (planeY * movspeed) - coll)][(int)(posX + coll)] == '0' && Wmap[(int)(posY + (planeY * movspeed) + coll)][(int)(posX - coll)] == '0')
			posY += (planeY * movspeed);
	}
	// strafe left
	if (keycode == 97 || keycode == 13)
	{
		if (Wmap[(int)(posY - coll)][(int)((posX - (planeX * movspeed) - coll))] == '0' && Wmap[(int)(posY + coll)][(int)((posX - (planeX * movspeed) + coll))] == '0' &&
			Wmap[(int)(posY + coll)][(int)((posX - (planeX * movspeed) - coll))] == '0' && Wmap[(int)(posY - coll)][(int)((posX - (planeX * movspeed) + coll))] == '0')
			posX -= (planeX * movspeed);
		if (Wmap[(int)(posY - (planeY * movspeed) - coll)][(int)(posX - coll)] == '0' && Wmap[(int)(posY - (planeY * movspeed) + coll)][(int)(posX + coll)] == '0' &&
			Wmap[(int)(posY - (planeY * movspeed) - coll)][(int)(posX + coll)] == '0' && Wmap[(int)(posY - (planeY * movspeed) + coll)][(int)(posX - coll)] == '0')
			posY -= (planeY * movspeed);
	}
	//move backward
	if (keycode == 115 || keycode == 1)
	{
		if (Wmap[(int)(posY - coll)][(int)((posX - (dirX * movspeed) - coll))] == '0' && Wmap[(int)(posY + coll)][(int)((posX - (dirX * movspeed) + coll))] == '0' &&
			Wmap[(int)(posY + coll)][(int)((posX - (dirX * movspeed) - coll))] == '0' && Wmap[(int)(posY - coll)][(int)((posX - (dirX * movspeed) + coll))] == '0')
			posX -= dirX * movspeed;
		if (Wmap[(int)(posY - (dirY * movspeed) + coll)][(int)(posX + coll)] == '0' && Wmap[(int)(posY - (dirY * movspeed) - coll)][(int)(posX + coll)] == '0' &&
			Wmap[(int)(posY - (dirY * movspeed) + coll)][(int)(posX - coll)] == '0' && Wmap[(int)(posY - (dirY * movspeed) - coll)][(int)(posX - coll)] == '0')
			posY -= dirY * movspeed;
	}
	// right rotation
	if (keycode == 65363 || keycode == 2)
		{
			tempdirX = dirX;
			tempplaneX = planeX;
			dirX = (tempdirX * cos(-rotspeed)) - (dirY * sin(-rotspeed));
			dirY = (tempdirX * sin(-rotspeed)) + (dirY * cos(-rotspeed));
			planeX = (tempplaneX * cos(-rotspeed)) - (planeY * sin(-rotspeed));
			planeY = (tempplaneX * sin(-rotspeed)) + (planeY * cos(-rotspeed));
		}
	// left rotation

	if (keycode == 65361 || keycode == 0)
		{
			tempdirX = dirX;
			tempplaneX = planeX;
			dirX = (dirX * cos(rotspeed)) - (dirY * sin(rotspeed));
			dirY = (tempdirX * sin(rotspeed)) + (dirY * cos(rotspeed));
			planeX = (planeX * cos(rotspeed)) - (planeY * sin(rotspeed));
			planeY = (tempplaneX * sin(rotspeed)) + (planeY * cos(rotspeed));
		}
	debugint(keycode);
	return (keycode);
}
