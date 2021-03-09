/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:48:22 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/09 15:10:04 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

int		ft_key_press(int keycode, t_param *param)
{
		if (keycode == 65307 || keycode == 53)
		{
			ft_close(param);
			return (keycode);
		}
		else if ((keycode == 119 || keycode == 13) && param->keys->mv_up == 0)
			param->keys->mv_up = 1;
		else if ((keycode == 100 || keycode == 2) && param->keys->mv_down == 0)
			param->keys->mv_right = 1;
		else if ((keycode == 97 || keycode == 0) && param->keys->mv_left == 0)
			param->keys->mv_left = 1;
		else if ((keycode == 115 || keycode == 1) && param->keys->mv_right == 0)
			param->keys->mv_down = 1;
		else if ((keycode == 65361 || keycode == 123) && param->keys->rt_right == 0)
			param->keys->rt_right = 1;
		else if ((keycode == 65363 || keycode == 124) && param->keys->rt_left == 0)
			param->keys->rt_left = 1;
		debugint(keycode);
		return (0);
}