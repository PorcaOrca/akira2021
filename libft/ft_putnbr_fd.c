/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 16:16:03 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/21 09:34:32 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printnbr(int nbr, int fd)
{
	char	digit;
	int		mod;

	while (nbr)
	{
		mod = nbr % 10;
		if (nbr < 0)
			mod = -mod;
		digit = mod + '0';
		nbr = ft_printnbr(nbr / 10, fd);
		write(fd, &digit, 1);
	}
	return (nbr);
}

void		ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == 0)
		write(fd, "0", 1);
	if (nbr < 0)
		write(fd, "-", 1);
	ft_printnbr(nbr, fd);
}
