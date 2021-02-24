/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_akira2021.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:22:52 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/24 14:46:23 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		main()
{
	t_param		param;
	
	param.map = ft_map_matrix("maps/map_files/map.cub");
	if (!ft_init(&param))
		ft_close(65307, &param);


	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, param.win_x, param.win_y, "akira2021");
	
	mlx_loop_hook(param.mlx, ft_new_frame, &param);
	mlx_key_hook(param.win, ft_close, &param);
	mlx_loop(param.mlx);
}