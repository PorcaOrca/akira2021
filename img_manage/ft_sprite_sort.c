/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:09:57 by lodovico          #+#    #+#             */
/*   Updated: 2021/03/04 09:32:59 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	ft_sprite_sort(int	*order, double *dist, int q)
{
	int		i;
	int		j;
	int		temporder;
	double	tempdist;

	i = 0;
	while (i < q)
	{
		j = 1;
		while ((i + j) < q)
		{
			if (dist[i + j] < dist[i])
			{
				temporder = order[i];
				order[i] = order[i + j];
				order[i + j] = temporder;
				tempdist = dist[i];
				dist[i] = dist[i + j];
				dist[i + j] = tempdist;
			}
			j++;
		}
		i++;
	}
}
