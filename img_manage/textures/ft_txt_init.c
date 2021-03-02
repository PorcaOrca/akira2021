/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_txt_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 09:19:53 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/02 10:46:01 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../akira2021.h"

void		ft_txt_init(t_param *param, t_txt *txt, char *path)
{	
	txt = (t_txt *)malloc(sizeof(t_txt));
	txt->data = (t_img *) malloc(sizeof(t_img));
	txt->data->ptr = mlx_xpm_file_to_image(param->mlx,
					path, &txt->texture_Width, &txt->texture_High);
	txt->data->addr = mlx_get_data_addr(txt->data->ptr,
										&txt->data->bxp,
										&txt->data->sizel,
										&txt->data->endian);
}
