/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_akira2021.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 08:22:52 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/05 09:38:08 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		main()
{
	t_param		*param;
	t_temp		*temp_cub;

	temp_cub = (t_temp *)malloc(sizeof(t_temp));

	// get the values from the cub files allocatin the char * for the path of the texture
	// remember to free them after initializing the textures and also free the temp struct cause it's temp
	ft_cub_init(temp_cub, "maps/map_files/map.cub");
	param = (t_param *)malloc(sizeof(t_param));
	//initializing all variables
	if (!ft_init(param, temp_cub))
		ft_close(65307, param);

	free(temp_cub);

	//event callers
	mlx_loop_hook(param->mlx, ft_new_frame, param);
	mlx_hook(param->win, 2, 1L<<0, ft_movement, param);
	mlx_key_hook(param->win, ft_close, param);
	mlx_loop(param->mlx);
}
