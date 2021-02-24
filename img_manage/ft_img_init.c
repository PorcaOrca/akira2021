/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:29:25 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/24 14:40:14 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

t_img	*ft_img_init(t_param *param)
{
	t_img	*img;
	
	img = (t_img *) malloc(sizeof(t_img));
	img->ptr = mlx_new_image(param->mlx, param->win_x, param->win_y);
	img->addr = mlx_get_data_addr(img->ptr, &img->bxp, &img->sizel, &img->endian);
	return (img);
}