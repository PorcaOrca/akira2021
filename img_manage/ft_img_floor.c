/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_floor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:23:15 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/03 16:00:45 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_fill_line(t_param *param)
{
	i_x = 0;
	while (i_x < winX)
	{
		fl_data->cellX = (int)fl_data->floorL.x;
		fl_data->cellY = (int)fl_data->floorL.y;
		txtX = (int)(txt_f_1->texture_Width * (fl_data->floorL.x - fl_data->cellX));
		txtY = (int)(txt_f_1->texture_Width * (fl_data->floorL.y - fl_data->cellY));
		fl_data->floorL.x += fl_data->fstep.x;
		fl_data->floorL.y += fl_data->fstep.y;
		trgb = ft_get_txtcolor(txt_f_1->txt_data, txtX, txtY);
		ft_img_pixel_put(param->img, i_x, i_y, trgb);
		i_x++;
	}
}

void		ft_img_floor(t_param *param)
{
	i_y = winY / 2;
	fl_data->rdirL.x = dirX - planeX;
	fl_data->rdirL.y = dirY - planeY;
	fl_data->rdirR.x = dirX + planeX;
	fl_data->rdirR.y = dirY + planeY;
	fl_data->posZ = winY * 0.5;
	while (i_y < winY)
	{
		fl_data->pos = i_y - (winY / 2);
		fl_data->rowdist = fl_data->posZ / fl_data->pos;
		fl_data->fstep.x = (fl_data->rowdist * (fl_data->rdirR.x - fl_data->rdirL.x)) / winX;
		fl_data->fstep.y = (fl_data->rowdist * (fl_data->rdirR.y - fl_data->rdirL.y)) / winX;
		fl_data->floorL.x = posX + (fl_data->rowdist * fl_data->rdirL.x);
		fl_data->floorL.y = posY + (fl_data->rowdist * fl_data->rdirL.y);
		ft_fill_line(param);
		i_y++;
	}
/*	i_y = 0;
	while (i_y < winY / 2)
	{
		i_x = 0;
		while (i_x < winX)
		{
			trgb = ft_get_txtcolor(txt_f_1->txt_data, txtX, txtY);
			ft_img_pixel_put(param->img, i_x, i_y, trgb);
			i_x++;
		}
		i_y++;
	}*/
}

