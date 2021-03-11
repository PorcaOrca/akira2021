/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skybox.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:06:13 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/11 09:27:21 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_skybox(t_param *param)
{
	if (param->keys->rt_left == 1)
		param->sky_data->sky_off += 17;
	if (param->keys->rt_right == 1)
		param->sky_data->sky_off -= 17;
	if (param->keys->mv_right == 1)
		param->sky_data->sky_off += 2;
	if (param->keys->mv_left == 1)
		param->sky_data->sky_off -= 2;
	txtX = ((param->texture->skybox->texture_Width / 2) - (winX / 2));
	if (param->sky_data->sky_off < -txtX)
		param->sky_data->sky_off += param->texture->skybox->texture_Width;
	if (param->sky_data->sky_off > ((winX / 2) + txtX))
		param->sky_data->sky_off -= param->texture->skybox->texture_Width;
	txtX += param->sky_data->sky_off;
	i_x = 0;
	while (i_x < winX)
	{
		if (txtX < 0)
			txtX += param->texture->skybox->texture_Width;
		if (txtX > param->texture->skybox->texture_Width)
			txtX -= param->texture->skybox->texture_Width;
		i_y = 0;
		txtY = 0;
		param->sky_data->stepcount = 0;
		while (i_y < winY / 2)
		{
			trgb = ft_get_txtcolor(txt_sb->txt_data, txtX, txtY);
			ft_img_pixel_put(param->img, i_x, i_y, trgb);
			param->sky_data->stepcount += param->sky_data->step_y;
			if (param->sky_data->stepcount >= 1)
			{
				txtY++;
				param->sky_data->stepcount -= 1;
			}
			i_y++;
		}
		i_x++;
		txtX++;
	}	
}