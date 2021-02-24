/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:05:28 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/24 17:35:39 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		ft_close(int keycode, t_param *param)
{
	if (keycode == 65307)
	{
		mlx_clear_window (param->mlx, param->win);
		mlx_destroy_window (param->mlx, param->win);
		free(param);
		exit (0);
	}
	return (0);
}