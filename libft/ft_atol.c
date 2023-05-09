/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 22:22:49 by manujime          #+#    #+#             */
/*   Updated: 2023/03/28 00:15:03 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//converts the initial portion of the string pointed to by str to long 
long int	ft_atol(const char *str)
{
	long int	nbr;
	int			sign;
	int			c;

	nbr = 0;
	sign = 1;
	c = 0;
	while ((str[c] == ' ') || (str[c] == '\t') || (str[c] == '\n')
		|| (str[c] == '\v') || (str[c] == '\f') || (str[c] == '\r'))
		c++;
	if ((str[c] == '-') || (str[c] == '+'))
	{
		if (str[c] == '-')
			sign *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		nbr = (nbr * 10) + (str[c] - '0');
		c++;
	}
	return (sign * nbr);
}
