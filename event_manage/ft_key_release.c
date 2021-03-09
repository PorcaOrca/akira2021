/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:53:01 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/09 15:09:23 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		ft_key_release(int keycode, t_param *param)
{
		if ((keycode == 119 || keycode == 13) && param->keys->mv_up == 1)
			param->keys->mv_up = 0;
		else if ((keycode == 100 || keycode == 2) && param->keys->mv_right == 1)
			param->keys->mv_right = 0;
		else if ((keycode == 97 || keycode == 0) && param->keys->mv_left == 1)
			param->keys->mv_left = 0;
		else if ((keycode == 115 || keycode == 1) && param->keys->mv_down == 1)
			param->keys->mv_down = 0;
		else if ((keycode == 65361 || keycode == 123) && param->keys->rt_right == 1)
			param->keys->rt_right = 0;
		else if ((keycode == 65363 || keycode == 124) && param->keys->rt_left == 1)
			param->keys->rt_left = 0;
		return (0);
}