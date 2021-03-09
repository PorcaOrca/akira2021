/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:07:03 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/08 16:17:22 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		ft_key_hook(int keycode, t_param *param)
{
	if (keycode == 65307 || keycode == 53)
		ft_close(param);
	return (keycode);
}