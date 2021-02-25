/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:16:21 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/25 10:46:31 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"
#include <math.h>

int		ft_movement(int keycode, t_param *param)
{
	double		tempdirX;
	double		tempplaneX;
	
	if (keycode == 115)
	{
		//if (!param->map[(int)posY][(int)(posX + (dirX * param->movspeed))])
		//{
			debugint(posX);
			debugint(posY);
			posX += dirX * param->movspeed;
			debugstr("forward");
		//}
		//if (!param->map[(int)(posY + (dirY * param->movspeed))][(int)posX])
			posY += dirY * param->movspeed;
	}
	if (keycode == 119)
	{
		//if (!param->map[(int)posY][(int)(posX + (dirX * param->movspeed))])
		//{
			debugint(posX);
			debugint(posY);
			posX -= dirX * param->movspeed;
			debugstr("backward");
		//}
		//if (!param->map[(int)(posY + (dirY * param->movspeed))][(int)posX])
			posY -= dirY * param->movspeed;
	}
	tempdirX = dirX;
	tempplaneX = planeX;
	if (keycode == 100)
		{
			debugstr("right");
			debugint(posX);
			debugint(posY);
			dirX = (dirX * cos(-param->rotspeed)) - (dirY * sin(-param->rotspeed));
			dirY = (tempdirX * sin(-param->rotspeed)) + (dirY * cos(-param->rotspeed));
			planeX = (planeX * cos(-param->rotspeed)) - (planeY * sin(-param->rotspeed));
			planeY = (tempplaneX * sin(-param->rotspeed)) + (dirY * cos(-param->rotspeed));
		}
	if (keycode == 97)
		{
			debugint(posX);
			debugint(posY);
			debugstr("left");
			dirX = (dirX * cos(param->rotspeed)) - (dirY * sin(param->rotspeed));
			dirY = (tempdirX * sin(param->rotspeed)) + (dirY * cos(param->rotspeed));
			planeX = (planeX * cos(param->rotspeed)) - (planeY * sin(param->rotspeed));
			planeY = (tempplaneX * sin(param->rotspeed)) + (dirY * cos(param->rotspeed));
		}
	return (keycode);
}
	
	/*
    //rotate to the right
    if (keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if (keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);*/