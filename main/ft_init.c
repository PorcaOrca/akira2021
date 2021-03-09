/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 09:15:35 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/09 16:14:06 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		ft_init(t_param *param, t_temp *temp)
{
	// map pointer
	int		i;
	int		j;
	int		s;

	i = 0;
	s = 0;
	Wmap = temp->temp_map;

	// vectors allocation
	param->vectors = (t_rayc *)malloc(sizeof(t_rayc));
	param->vectors->dir = (t_vector *)malloc(sizeof(t_vector));
	param->vectors->pos = (t_vector *)malloc(sizeof(t_vector));
	param->vectors->plane = (t_vector *)malloc(sizeof(t_vector));
	// raycasting vectors
	posX = temp->position[0];
	posY = temp->position[1];
	dirX = temp->t_dirX;
	dirY = temp->t_dirY;
	planeX = temp->t_planeX;
	planeY = temp->t_planeY;

	param->settings = (t_settings *)malloc(sizeof(t_settings));
	// settings
	winX = temp->width;
	winY = temp->height;
	lagi = 0;
	lagc = lagi;
	movspeed = 0.1;
	rotspeed = 0.05;
	f_trgb = temp->floor_color;
	c_trgb = temp->ceiling_color;

	param->sky_data = (t_sky_data *)malloc(sizeof(t_sky_data));
	fl_data = (t_fl_data *)malloc(sizeof(t_fl_data));
	wl_data = (t_wl_data *)malloc(sizeof(t_wl_data));
	param->common_data = (t_common *)malloc(sizeof(t_common));
	sp_data = (t_sp_data *)malloc(sizeof(t_sp_data));

	//initialize server mlx connection and create a new win
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, winX, winY, "akira2021");

	// texture struct init
	param->texture = (t_texture *)malloc(sizeof(t_texture));

	// texture init

	txt_1 = ft_txt_init(param, temp->texture1);
	free(temp->texture1);
	txt_2 = ft_txt_init(param, temp->texture2);
	free(temp->texture2);
	txt_3 = ft_txt_init(param, temp->texture3);
	free(temp->texture3);
	txt_4 = ft_txt_init(param, temp->texture4);
	free(temp->texture4);
	txt_sb = ft_txt_init(param, "img_manage/textures/texture_files/txt_skybox.xpm");
	txt_f_1 = ft_txt_init(param, "img_manage/textures/texture_files/txt_floor_blue_1.xpm");

	// sprite arrays needed to do after map read
	param->sprite_num = temp->sprite_q;
	sp_data->zbuffer = (double *)malloc(sizeof(double) * winX);
	sp_data->dist = (double *)malloc(sizeof(double) * param->sprite_num);
	sp_data->order = (int *)malloc(sizeof(int) * param->sprite_num);
	sp_data->sp_arr = (t_spr *)malloc(sizeof(t_spr) * param->sprite_num);
	txt_spr = ft_txt_init(param, "img_manage/textures/texture_files/sprite1.xpm");
	while (Wmap[i])
	{
		j = 0;
		while (Wmap[i][j])
		{
			if (Wmap[i][j] == '2')
			{
				sp_data->sp_arr[s].s_pos_x = j + 0.5;
				sp_data->sp_arr[s].s_pos_y = i + 0.5;
				sp_data->sp_arr[s].s_txt = txt_spr;
				Wmap[i][j] = '0';
				s++;
			}
			j++;
		}
		i++;
	}
	
	// skybox init data
	param->sky_data->sky_off = 0;
	param->sky_data->step_y = param->texture->skybox->texture_High;
	param->sky_data->step_y /= (winY / 2);
	
	// key management
	param->keys = (t_key_stat *)malloc(sizeof(t_key_stat));
	param->keys->mv_down = 0;
	param->keys->mv_up = 0;
	param->keys->mv_left = 0;
	param->keys->mv_right = 0;
	param->keys->rt_left = 0;
	param->keys->rt_right = 0;
	return (1);
}
