/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:48:24 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/26 10:45:10 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	
	dst = img->addr + (y * img->sizel + x * (img->bxp / 8));
	*(unsigned int *)dst = color;
}
