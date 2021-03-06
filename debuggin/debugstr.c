/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lodovico <lodovico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:28:30 by lodovico          #+#    #+#             */
/*   Updated: 2021/02/23 18:57:14 by lodovico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../akira2021.h"

void	debugstr(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	write(1, "\n", 1);
}