/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:32:25 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 12:12:59 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Applies the function 'f' to each character of the string 's', 
giving as parameters the index of the charcter and its pointer, 
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		c;

	c = 0;
	if (s && f)
	{
		while (s[c] != '\0')
		{
			f(c, &s[c]);
			c++;
		}
	}
}
