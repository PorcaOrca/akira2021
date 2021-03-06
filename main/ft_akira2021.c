/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_akira2021.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:22:52 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/13 10:26:22 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		main(void)
{
//	int i = 0;
	t_param		*param;
	t_temp		*temp_cub;

	temp_cub = (t_temp *)malloc(sizeof(t_temp));
	if (!temp_cub)
		return (1);
	if (!ft_cub_init(temp_cub, "maps/map_files/map_trip.cub"))
	{
		free(temp_cub);
		write(1, "wrong .cub configuration", 24);
		exit (0);
	}
/*	while (temp_cub->temp_map[i])
	{
		debugstr(temp_cub->temp_map[i]);
		i++;
	}
*/	param = (t_param *)malloc(sizeof(t_param));
	ft_init(param, temp_cub);
//	i = 0;
/*	while (param->map[i])
	{
		debugstr(param->map[i]);
		i++;
	}
*/	free(temp_cub);
	mlx_hook(param->win, 3, 1L << 1, ft_key_release, param);
	mlx_hook(param->win, 2, 1L << 0, ft_key_press, param);
	mlx_loop_hook(param->mlx, ft_new_frame, param);
	if(param->mlx)
		mlx_loop(param->mlx);
	ft_close(param);
}
