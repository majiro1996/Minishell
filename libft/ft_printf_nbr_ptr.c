/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:41:41 by manujime          #+#    #+#             */
/*   Updated: 2023/03/27 13:00:01 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nbr)
{
	int	c;

	c = 0;
	if (nbr == -2147483648)
	{
		c += ft_printstr("-2147483648");
		return (c);
	}
	if (nbr < 0)
	{
		c += ft_printchar('-');
		nbr *= -1;
	}
	if (nbr / 10 != 0)
	{
		if (nbr > 9)
			c += ft_printnbr(nbr / 10);
		else
		{
			return (ft_printchar((nbr % 10) + '0'));
		}
	}
	ft_printchar((nbr % 10) + '0');
	return (c + 1);
}

int	ft_printhex(unsigned long nbr, char f)
{
	int		k;
	int		c;
	char	*base;
	char	str[25];

	c = 0;
	if (f == 'x')
		base = "0123456789abcdef";
	if (f == 'X')
		base = "0123456789ABCDEF";
	if (nbr == 0)
		return (ft_printchar('0'));
	while (nbr != 0)
	{
		str[c] = base[nbr % 16];
		nbr = nbr / 16;
		c++;
	}
	k = c;
	while (c--)
		ft_printchar(str[c]);
	return (k);
}

int	ft_printptr(void *ptr)
{
	int		c;

	c = 0;
	c += ft_printstr("0x");
	c += ft_printhex((unsigned long)ptr, 'x');
	return (c);
}

int	ft_printuns(unsigned int nbr)
{
	int	c;

	c = 0;
	if (nbr / 10 != 0)
	{
		if (nbr > 9)
			c += ft_printuns(nbr / 10);
		else
		{
			return (ft_printchar((nbr % 10) + '0'));
		}
	}
	ft_printchar((nbr % 10) + '0');
	return (c + 1);
}
