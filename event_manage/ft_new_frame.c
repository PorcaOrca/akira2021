/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:28:29 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/24 14:37:23 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		ft_new_frame(t_param *param)
{
	param->img = ft_img_init(param);
	ft_img_fill(param);
	mlx_clear_window(param->mlx, param->win);
	mlx_put_image_to_window(param->mlx, param->win, param->img->ptr, 0, 0);
	mlx_destroy_image(param->mlx, param->img->ptr);
	free(param->img);
}