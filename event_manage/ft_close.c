/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:05:28 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/26 15:14:59 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		ft_close(int keycode, t_param *param)
{
	if (keycode == 65307 || keycode == 53)
	{
		mlx_clear_window (param->mlx, param->win);
		mlx_destroy_window (param->mlx, param->win);
		free(param);
		exit (0);
	}
	return (0);
}
