/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:29:25 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/26 18:12:20 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

t_img	*ft_img_init(t_param *param)
{
	t_img	*img;
	
	img = (t_img *) malloc(sizeof(t_img));
	img->ptr = mlx_new_image(param->mlx, winX, winY);
	img->addr = mlx_get_data_addr(img->ptr, &img->bxp, &img->sizel, &img->endian);
	return (img);
}