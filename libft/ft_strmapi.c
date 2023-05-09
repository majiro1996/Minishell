/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:22:26 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 12:26:36 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*create new string from modifying string with specified function
Applies the function ’f’ to each character of the string ’s’ to create
a new string (with malloc(3)) resulting from successive applications of ’f’.*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		c;
	char				*newstr;

	c = 0;
	if (s && f)
	{
		newstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (newstr == NULL)
			return (NULL);
		while (s[c] != '\0')
		{
			newstr[c] = f(c, s[c]);
			c++;
		}
		newstr[c] = '\0';
		return (newstr);
	}
	return (NULL);
}
