/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:19:03 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/09 15:01:17 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_img_fill(t_param *param)
{
/*	i_x = 0;
	while (i_x < winX)
	{
		i_y = 0;
		while (i_y < (winY / 2))
		{
			ft_img_pixel_put(param->img, i_x, i_y, c_trgb);
			i_y++;
		}
		i_x++;
	}
*/	if ((unsigned int)f_trgb == 0xFFFFFFFF)
		ft_img_floor(param);
	else
	{
		i_x = 0;
		while (i_x < winX)
		{
			i_y = winY / 2;
			while (i_y < winY)
			{
				ft_img_pixel_put(param->img, i_x, i_y, f_trgb);
				i_y++;
			}
			i_x++;
		}
	}
	ft_skybox(param);
	ft_img_wall(param);
	ft_sprite(param);
}
