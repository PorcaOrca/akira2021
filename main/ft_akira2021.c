/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_akira2021.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:22:52 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/02 10:22:41 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		main()
{
	t_param		*param;

	param = (t_param *)malloc(sizeof(t_param));

	//initializing all variables
	if (!ft_init(param))
		ft_close(65307, param);

	//reading map and storing in matrix
	Wmap = ft_map_matrix("maps/map_files/map.cub");

	//initialize server mlx connection and create a new win
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, winX, winY, "akira2021");

	//event callers
	mlx_hook(param->win, 2, 1L<<0, ft_movement, param);
	mlx_loop_hook(param->mlx, ft_new_frame, param);
	mlx_key_hook(param->win, ft_close, param);
	mlx_loop(param->mlx);
}
