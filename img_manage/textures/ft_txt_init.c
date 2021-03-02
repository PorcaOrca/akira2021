/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_txt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:19:53 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/02 14:31:34 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../akira2021.h"

t_txt		*ft_txt_init(t_param *param, char *path)
{
	t_txt	*txt;

	txt = (t_txt *)malloc(sizeof(t_txt));
	txt->txt_data = (t_img *) malloc(sizeof(t_img));
	txt->txt_data->ptr = mlx_xpm_file_to_image(param->mlx,
					path, &txt->texture_Width, &txt->texture_High);
	txt->txt_data->addr = mlx_get_data_addr(txt->txt_data->ptr,
										&txt->txt_data->bxp,
										&txt->txt_data->sizel,
										&txt->txt_data->endian);
	return (txt);
}
