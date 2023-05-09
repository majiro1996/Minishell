/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:06:12 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:06:22 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nlen(int c)
{
	size_t	len;

	len = 0;
	if (c <= 0)
		len++;
	while (c != 0)
	{
		len++;
		c = c / 10;
	}
	return (len);
}

static char	*ft_write(char *str, size_t len, int c, int sign)
{
	str[len--] = '\0';
	if (c == 0)
		str[0] = '0';
	while (c > 0)
	{
		str[len--] = '0' + (c % 10);
		c = c / 10;
	}
	if (sign == -1)
		str[len--] = '-';
	return (str);
}

/*Using malloc, make a string that represents the int value 
passed as an argument.
Negative numbers must be handled.
-Returns the string that was created or NULL if memory allocation fails.*/
char	*ft_itoa(int c)
{
	size_t		len;
	char		*str;
	int			sign;
	int			nbr;

	nbr = c;
	sign = 1;
	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_nlen(nbr);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		sign = -1;
		nbr = nbr * -1;
	}
	str = ft_write(str, len, nbr, sign);
	return (str);
}
