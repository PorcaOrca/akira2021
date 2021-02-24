/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_akira2021.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:22:52 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/24 17:49:28 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		main()
{
	t_param		*param;
		
	param = (t_param *)malloc(sizeof(t_param *));
	param->lag = 0;
	param->map = ft_map_matrix("maps/map_files/map.cub");
	if (!ft_init(param))
		ft_close(65307, param);
	int		x;
	int		y;
	
	x = 0;
	y = 0;
	while (param->map[x])
	{
		y = 0;
		write(1, "|", 1);
		while (param->map[x][y])
		{
			write(1, &param->map[x][y], 1);
			y++;
		}
		write(1, "|", 1);
		write(1, "\n", 1);
		x++;
	}
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, param->win_x, param->win_y, "akira2021");
	mlx_loop_hook(param->mlx, ft_new_frame, param);
	mlx_key_hook(param->win, ft_close, param);
	mlx_loop(param->mlx);
}