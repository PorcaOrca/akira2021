/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:19:03 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/24 16:59:32 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_img_fill(t_param *param)
{
	int			x;
	t_vector	raydir;
	//raylenght to next x or y side from start
	t_vector	sidedist;
	//raylenght from x or y side to the next y or y side
	t_vector	deltadist;
	double		camerax;
	double		walldist;
	//what direction to step in x or y-direction (either +1 or -1)
    int 		stepx;
    int			 stepy;
    int 		hit; //was there a wall hit?
    int 		side; //was a NS or a EW wall hit?

	int			mapx;
	int			mapy;
	int			lineh;
	int			ystart;
	int			yend;

	//color management
	int			trgb;
	double		shade;

	// box of the map we are in
	mapx = (int)param->vectors->pos->x;
	mapy = (int)param->vectors->pos->y;
	shade = 0;
	x = 0;
	hit = 0;
	while (x < param->win_x)
	{
		//ray position and direction
		camerax = (2 * x) / (param->win_x - 1);
		raydir.x = param->vectors->dir->x + (param->vectors->plane->x * camerax);
		raydir.y = param->vectors->dir->y + (param->vectors->plane->y * camerax);
		
		if (raydir.y == 0)
			deltadist.x = 0;
		else if (raydir.x == 0)
			deltadist.x = 1;
		else
			deltadist.x = 1 / raydir.x;
		if (raydir.x < 0)
			raydir.x = -raydir.x;
		x++;
		if (raydir.x == 0)
			deltadist.y = 0;
		else if (raydir.y == 0)
			deltadist.y = 1;
		else
			deltadist.y = 1 / raydir.y;
		if (raydir.y < 0)
			raydir.y = -raydir.y;
		//calculate step and initial sideDist
		if (raydir.x < 0)
		{
			stepx = -1;
			sidedist.x = (param->vectors->pos->x - mapx) * deltadist.x;
		}
		else
		{
			stepx = 1;
			sidedist.x = (mapx + 1.0 - param->vectors->pos->x) * deltadist.x;
		}
		if (raydir.y < 0)
		{
			stepy = -1;
			sidedist.y = (param->vectors->pos->y - mapy) * deltadist.y;
		}
		else
		{
			stepy = 1;
			sidedist.y = (mapy + 1.0 - param->vectors->pos->y) * deltadist.y;
		}
		//DDADAJE
		while (hit = 0)
		{
			//jump to next map square, in x or y direction
			if (sidedist.x < sidedist.y)
			{
				sidedist.x += deltadist.x;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedist.y += deltadist.y;
				mapy += stepy;
				side = 1;
			}
			if (param->map[mapx][mapy] > '0')
				hit = 1;
		}
		//calculate euclidian distance from post to wall
		if (side == 0)
			walldist = (mapx - param->vectors->pos->x + ((1 - stepx) / 2)) / raydir.x;
		else
			walldist = (mapy - param->vectors->pos->y + ((1 - stepy) / 2)) / raydir.y;
		//calculate height of line to draw
		lineh = (int)(param->win_y / walldist);
		// find min and max y to fill
		ystart = (-lineh / 2) + (param->win_y / 2);
		if (ystart < 0)
			ystart = 0;
		yend = (lineh / 2) + (param->win_y / 2);
		if (yend >= param->win_y)
			yend = param->win_y - 1;
		if (side == 1)
			shade == 0.5;
		if (param->map[mapx][mapx] == '1')
			trgb = ft_color(shade, 0, 0, 255);
		if (param->map[mapx][mapx] == '2')
			trgb = ft_color(shade, 255, 255, 0);
		if (param->map[mapx][mapx] == '3')
			trgb = ft_color(shade, 255, 0, 255);
		if (param->map[mapx][mapx] == '4')
			trgb = ft_color(shade, 255, 0, 0);
		while (ystart <= yend)
		{
			ft_img_pixel_put(param->img->ptr, x, ystart, trgb);
			ystart++;
		}
		x++;
	}
}
