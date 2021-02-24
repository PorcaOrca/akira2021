/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:50:23 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/23 18:57:12 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

static void	ft_putnbr(int nbr)
{
	char	tmp;
	int		mod;

	if (nbr)
	{
		mod = nbr % 10;
		if (mod < 0)
			mod = -mod;
		tmp = mod + '0';
		ft_putnbr(nbr / 10);
		write (1, &tmp, 1);
	}	
}

void	debugint(int nbr)
{
	write(1, "|", 1);
	if (nbr == 0)
		write(1, "0", 1);
	if (nbr < 0)
		write(1, "-", 1);
	ft_putnbr(nbr);
	write(1, "|\n", 2);
}
