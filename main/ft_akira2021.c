/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_akira2021.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:22:52 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/09 11:09:14 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		main(void)
{
	t_param		*param;
	t_temp		*temp_cub;

	temp_cub = (t_temp *)malloc(sizeof(t_temp));
	if (!temp_cub)
		return (1);
	ft_cub_init(temp_cub, "maps/map_files/map.cub");
	param = (t_param *)malloc(sizeof(t_param));
	ft_init(param, temp_cub);
	free(temp_cub);
	mlx_hook(param->win, 3, 1L << 1, ft_key_release, param);
	mlx_hook(param->win, 2, 1L << 0, ft_key_press, param);
//	mlx_key_hook(param->win, ft_key_hook, param);
	mlx_loop_hook(param->mlx, ft_new_frame, param);
	mlx_loop(param->mlx);
}
