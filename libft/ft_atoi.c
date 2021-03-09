/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lspazzin <lspazzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:13:57 by lspazzin          #+#    #+#             */
/*   Updated: 2021/01/21 10:36:13 by lspazzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

int			ft_atoi(char *str)
{
	int		nbr;
	size_t	i;
	short	sign;

	sign = 1;
	i = 0;
	nbr = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + str[i] - '0';
		if (nbr > -2147483648 && nbr < 0 && sign > 0)
			return (-1);
		if (nbr > -2147483648 && nbr < 0 && sign < 0)
			return (0);
		i++;
	}
	return (nbr * sign);
}
