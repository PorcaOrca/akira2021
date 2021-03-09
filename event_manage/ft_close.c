/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:05:28 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/09 14:37:41 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void		ft_close(t_param *param)
{
	int x;

	x = 0;
	mlx_destroy_image(param->mlx, txt_1->txt_data->ptr);
	mlx_destroy_image(param->mlx, txt_2->txt_data->ptr);
	mlx_destroy_image(param->mlx, txt_3->txt_data->ptr);
	mlx_destroy_image(param->mlx, txt_4->txt_data->ptr);
	mlx_destroy_image(param->mlx, txt_f_1->txt_data->ptr);
	mlx_destroy_image(param->mlx, txt_spr->txt_data->ptr);
//	mlx_destroy_image(param->mlx, txt_sb->txt_data->ptr);
	free(txt_1->txt_data);
	free(txt_2->txt_data);
	free(txt_3->txt_data);
	free(txt_4->txt_data);
	free(txt_f_1->txt_data);
	free(txt_spr->txt_data);
//	free(txt_sb->txt_data);
	free(txt_1);
	free(txt_2);
	free(txt_3);
	free(txt_4);
	free(txt_f_1);
	free(txt_spr);
//	free(txt_sb);
	free(param->texture);
	mlx_clear_window (param->mlx, param->win);
	mlx_destroy_window (param->mlx, param->win);
	while (param->map[x])
	{
		free(param->map[x]);
		x++;
	}
	free(param->map);
	free(param->vectors->dir);
	free(param->vectors->plane);
	free(param->vectors->pos);
	free(param->vectors);
	free(param->settings);
	free(sp_data->zbuffer);
	free(sp_data->order);
	free(sp_data->sp_arr);
	free(sp_data->dist);
	free(fl_data);
	free(wl_data);
	free(sp_data);
	free(param->sky_data);
	free(param->common_data);
	free(param->keys);
	free(param);
	exit (0);
}
