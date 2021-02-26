/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_txt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:19:53 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/26 15:59:44 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../akira2021.h"

void		ft_txt_init(t_param *param)
{
	txt1 = (t_img *) malloc(sizeof(t_img));
	txt1->ptr = mlx_xpm_file_to_image(param->mlx, "img_manage/textures/texture_files/xpms/wall1.xpm", &winX, &winY);
	debug();
	txt1->addr = mlx_get_data_addr(txt1->ptr, &txt1->bxp, &txt1->sizel, &txt1->endian);

	debug();

	txt2 = (t_img *) malloc(sizeof(t_img));
	txt2->ptr = mlx_xpm_file_to_image(param->mlx, "img_manage/textures/texture_files/xpms/wall2.xpm", &winX, &winY);
	txt2->addr = mlx_get_data_addr(txt2->ptr, &txt2->bxp, &txt2->sizel, &txt2->endian);
}
