/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 08:56:29 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/02 10:21:33 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_fill_px(t_param *param, t_wl_data *data, t_txt *txt,
					int txtX, double step)
{
	int		trgb;
	int		txtY;
	double	txtpos;
	
	txtpos = (data->ystart - winY / 2 + data->lineh / 2) * step;
	while (data->ystart <= data->yend)
		{
			txtY = (int)txtpos;
			trgb = ft_get_txtcolor(txt->data, txtX, txtY);
			ft_img_pixel_put(param->img, data->x, data->ystart, trgb);
			txtpos += step;
			data->ystart++;
		}
}

void	ft_fill_column(t_param *param, t_wl_data *data, t_txt *txt)
{
	int		txtX;
	double	wallX;
	double	step;

	if (data->side == 0)
		wallX = posY + (data->walldist * data->raydir.y);
   	else
		wallX = posX + (data->walldist * data->raydir.x);
	wallX -= floor((wallX));
	txtX = (int)(wallX * (double)txt->texture_Width);
	if(data->side == 0 && data->raydir.x > 0)
		txtX = txt->texture_Width - txtX - 1;
	if(data->side == 1 && data->raydir.y < 0)
		txtX = txt->texture_Width - txtX - 1;
	step = (1.0 * txt->texture_High) / data->lineh;
	ft_fill_px(param, data, txt, txtX, step);		
}

void	ft_calc_column(t_param *param, t_wl_data *data)
{
		if (data->side == 0)
			data->walldist = (data->mapx - posX +
				((1 - data->stepx) / 2)) / data->raydir.x;
		else
			data->walldist = (data->mapy - posY +
				((1 - data->stepy) / 2)) / data->raydir.y;
		data->lineh = (int)(winY / data->walldist);
		data->ystart = (-data->lineh / 2) + (winY / 2);
		if (data->ystart < 0)
			data->ystart = 0;
		data->yend = (data->lineh / 2) + (winY / 2);
		if (data->yend >= winY)
			data->yend = winY - 1;
}

void	ft_DDA(t_param *param, t_wl_data *data)
{
	int		hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->sidedist.x < data->sidedist.y)
		{
			data->sidedist.x += data->deltadist.x;
			data->mapx += data->stepx;
			data->side = 0;
		}
		else
		{
			data->sidedist.y += data->deltadist.y;
			data->mapy += data->stepy;
			data->side = 1;
		}
		if (param->map[data->mapy][data->mapx] > '0')
			hit = 1;
		}
}

void	ft_step(t_param *param, t_wl_data *data)
{
	if (data->raydir.x < 0)
		{
			data->stepx = -1;
			data->sidedist.x = (posX - data->mapx) * data->deltadist.x;
		}
		else
		{
			data->stepx = 1;
			data->sidedist.x = (data->mapx + 1.0 - posX) * data->deltadist.x;
		}
		if (data->raydir.y < 0)
		{
			data->stepy = -1;
			data->sidedist.y = (posY - data->mapy) * data->deltadist.y;
		}
		else
		{
			data->stepy = 1;
			data->sidedist.y = (data->mapy + 1.0 - posY) * data->deltadist.y;
		}
}

void	ft_deltadist(t_wl_data *data)
{
	if (data->raydir.y == 0)
		data->deltadist.x = 0;
	else
	{
		if (data->raydir.x == 0)
			data->deltadist.x = 1;
		else
			data->deltadist.x = 1 / data->raydir.x;
	}
	if (data->deltadist.x < 0)
		data->deltadist.x = -data->deltadist.x;
	if (data->raydir.x == 0)
		data->deltadist.y = 0;
	else
	{
		if (data->raydir.y == 0)
			data->deltadist.y = 1;
		else
			data->deltadist.y = 1 / data->raydir.y;
	}
	if (data->deltadist.y < 0)
		data->deltadist.y = -data->deltadist.y;
}

void	ft_img_wall(t_param *param)
{
	double		camerax;
	t_wl_data	data;

	data.x = 0;
	while (data.x < winX)
	{
		camerax = ((2 * data.x) / (double)winX) - 1;
		data.raydir.x = dirX + (planeX * camerax);
		data.raydir.y = dirY + (planeY * camerax);
		data.mapx = (int)posX;
		data.mapy = (int)posY;
		ft_deltadist(&data);
		ft_step(param, &data);
		ft_DDA(param, &data);
		ft_calc_column(param, &data);
		ft_fill_column(param, &data, txt_1);
		data.x++;
	}
}