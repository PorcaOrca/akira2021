/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:23:15 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/02 10:19:55 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_fill_line(t_param *param, t_fl_data *data, int y)
{
	int		trgb;
	int		x;
	int		txtX;
	int		txtY;
	
	x = 0;
	while (x < winX)
	{
		data->cellX = (int)data->floorL.x;
		data->cellY = (int)data->floorL.y;
		txtX = (int)(txt_f_1->texture_Width * (data->floorL.x - data->cellX));
		txtY = (int)(txt_f_1->texture_Width * (data->floorL.y - data->cellY));
		data->floorL.x += data->fstep.x;
		data->floorL.y += data->fstep.y;
		trgb = ft_get_txtcolor(txt_f_1->data, txtX, txtY);
		ft_img_pixel_put(param->img, x, y, trgb);
		x++;
	}
}

void		ft_img_floor(t_param *param)
{
	int			y;
	t_fl_data	data;
	
	y = winY / 2;
	data.rdirL.x = dirX - planeX;
	data.rdirL.y = dirY - planeY;
	data.rdirR.x = dirX + planeX;
	data.rdirR.y = dirY + planeY;
	data.posZ = winY * 0.5;
	while (y < winY)
	{
		data.pos = y - (winY / 2);
		data.rowdist = data.posZ / data.pos;
		data.fstep.x = (data.rowdist * (data.rdirR.x - data.rdirL.x)) / winX;
		data.fstep.y = (data.rowdist * (data.rdirR.y - data.rdirL.y)) / winX;
		data.floorL.x = posX + (data.rowdist * data.rdirL.x);
		data.floorL.y = posY + (data.rowdist * data.rdirL.y);
		ft_fill_line(param, &data, y);		
		y++;
	}
}

