/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_txtcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 10:40:56 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/26 11:03:53 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../akira2021.h"

int		ft_get_txtcolor(t_img *img, int x, int y)
{
	char	*pxl;
	int		trgb;

	pxl = img->addr + (y * img->sizel + x * (img->bxp / 8));
	trgb = *(unsigned int *)pxl;
	return (trgb);
}