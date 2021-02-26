/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:19:03 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/26 19:24:38 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_img_fill(t_param *param)
{
	//calculate ray for each x coordinate
	int			x;
	int			y;

	t_vector	raydir;
	t_vector	sidedist;
	t_vector	deltadist;


	double		camerax;
	double		walldist;

	int 		stepx;
    int			stepy;

	int 		hit;
    int 		side;

	int			mapx;
	int			mapy;

	int			lineh;
	int			ystart;
	int			yend;

	// floor casting variables
	t_vector	raydirL;
	t_vector	raydirR;
	t_vector	floorL;
	t_vector	floorstep;
	int			pos;
	int			cellX;
	int			cellY;
	double		posZ;
	double		rowdist;
	

/*	//color management
	int			trgb;
	double		shade;
*/
	// texture management
	int		txtid;
	int		txtX;
	int		txtY;
	double	txtpos;
	double	wallX;
	double	step;
	int		trgb;
	t_img	*txtptr;

	y = winY / 2;

	// here goes the pavimentation
	
		// raydir for the leftmost ray
		raydirL.x = dirX - planeX;
		raydirL.y = dirY - planeY;
	
		// raydir for the rightmost ray
		raydirR.x = dirX + planeX;
		raydirR.y = dirY + planeY;

		// vertical position of the camera (half screen)
		posZ = winY * 0.5;
	// loop for every line
	while (y < winY)
	{

	
		// current y from the center of the screen
		pos = y - (winY / 2);

		//horizontal distance from the camera for each row
		rowdist = posZ / pos;
		
		// step vector for not calculating with a weight in the x loop
		floorstep.x = (rowdist * (raydirR.x - raydirL.x)) / winX;
		floorstep.y = (rowdist * (raydirR.y - raydirL.y)) / winX;
		
		// coordinates of the leftmost column. updated stepping trough x
		floorL.x = posX + (rowdist * raydirL.x);
		floorL.y = posY + (rowdist * raydirL.y);
		
		// do the line yolo
		x = 0;
		while (x < winX)
		{
			// cell coord given from the int part of the floor vector
			cellX = (int)floorL.x;
			cellY = (int)floorL.y;

			// coordinate for the textur pixel
			txtX = (int)(txtW * (floorL.x - cellX));
			txtY = (int)(txtH * (floorL.y - cellY));
			floorL.x += floorstep.x;
			floorL.y += floorstep.y;
			
			trgb = ft_get_txtcolor(txt2, txtX, txtY);
			ft_img_pixel_put(param->img, x, y, trgb);
			
			x++;
		}
		y++;
	}

	// raycasting the walls
	x = 0;
	
	while (x < winX)
	{
		// represent x coordinate in -1, 1 range
		camerax = ((2 * x) / (double)winX) - 1;

		//ray direction is the sum of the dir vector and the plane vector
		raydir.x = dirX + (planeX * camerax);
		raydir.y = dirY + (planeY * camerax);

		// box of the map we are in
		mapx = (int)posX;
		mapy = (int)posY;

		// found collision (as boolean)
		hit = 0;

		// lenght of ray from start to next x or y side
		if (raydir.y == 0)
			deltadist.x = 0;
		else
		{
			if (raydir.x == 0)
				deltadist.x = 1;
			else
				deltadist.x = 1 / raydir.x;
		}
		// convert in absolute value
		if (deltadist.x < 0)
			deltadist.x = -deltadist.x;

		if (raydir.x == 0)
			deltadist.y = 0;
		else
		{
			if (raydir.y == 0)
				deltadist.y = 1;
			else
				deltadist.y = 1 / raydir.y;
		}
		if (deltadist.y < 0)
			deltadist.y = -deltadist.y;

		//calculate step and initial sideDist
		if (raydir.x < 0)
		{
			stepx = -1;
			sidedist.x = (posX - mapx) * deltadist.x;
		}
		else
		{
			stepx = 1;
			sidedist.x = (mapx + 1.0 - posX) * deltadist.x;
		}
		if (raydir.y < 0)
		{
			stepy = -1;
			sidedist.y = (posY - mapy) * deltadist.y;
		}
		else
		{
			stepy = 1;
			sidedist.y = (mapy + 1.0 - posY) * deltadist.y;
		}

		//DDADAJE
		while (hit == 0)
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
			if (param->map[mapy][mapx] > '0')
				hit = 1;
		}

		//calculate euclidian distance from post to wall
		if (side == 0)
			walldist = (mapx - posX + ((1 - stepx) / 2)) / raydir.x;
		else
			walldist = (mapy - posY + ((1 - stepy) / 2)) / raydir.y;

		//calculate height of line to draw
		lineh = (int)(winY / walldist);

		// find min and max y to fill
		ystart = (-lineh / 2) + (winY / 2);
		if (ystart < 0)
			ystart = 0;
		yend = (lineh / 2) + (winY / 2);
		if (yend >= winY)
			yend = winY - 1;

		// wall color fill
/*
		shade = 0;
		if (side == 1)
			shade = 0.5;

		if (Wmap[mapy][mapx] == '1')
			trgb = ft_color(shade, 0, 0, 255);
		if (Wmap[mapy][mapx] == '2')
			trgb = ft_color(shade, 255, 255, 0);
		if (Wmap[mapy][mapx] == '3')
			trgb = ft_color(shade, 0, 255, 0);
		if (Wmap[mapy][mapx] == '4')
			trgb = ft_color(shade, 255, 0, 0);
		while (ystart <= yend)
		{
			ft_img_pixel_put(param->img, x, ystart, trgb);
			ystart++;
		}
*/
		// texturized walls

		txtid = Wmap[mapy][mapx] - '0';

		// calculate exactly the wall hit
		if (side == 0)
			wallX = posY + (walldist * raydir.y);
      	else
			wallX = posX + (walldist * raydir.x);
		wallX -= floor((wallX));

		// x coordinate on the texture
		txtX = (int)(wallX * (double)txtW);
		if(side == 0 && raydir.x > 0)
			txtX = txtW - txtX - 1;
		if(side == 1 && raydir.y < 0)
			txtX = txtW - txtX - 1;

		// How much to increase the texture y coordinate per screen pixel
		step = (1.0 * txtH) / lineh;

		// select texture

		if (txtid == 1)
			txtptr = txt1;
		if (txtid == 3)
			txtptr = txt2;

		txtpos = (ystart - winY / 2 + lineh / 2) * step;
		while (ystart <= yend)
		{
			txtY = (int)txtpos;
			trgb = ft_get_txtcolor(txtptr, txtX, txtY);
			ft_img_pixel_put(param->img, x, ystart, trgb);
			txtpos += step;
			ystart++;
		}
		x++;
	}
}
