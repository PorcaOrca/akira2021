/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:05:28 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/24 09:14:37 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		ft_close(int keycode, t_param *param)
{
	if (keycode == 65307)
	{
		//mlx_destroy_image(param->mlx_ptr, param->img->ptr);
		//free(param->img);
		mlx_clear_window (param->mlx, param->win);
		mlx_destroy_window (param->mlx, param->win);
		exit (0);
	}
	return (0);
}