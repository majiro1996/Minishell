/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:07:10 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 12:28:12 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Deletes all characters from the string 'set'
from the begining and from the end of 's1', until 
it finds a character not included in 'set'. 
-returns the resulting string or NULL if memory allocation fails.*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	c;

	c = ft_strlen(s1);
	if (s1 && set)
	{
		while (*s1 != '\0' && ft_strchr(set, *s1))
			s1++;
		c = ft_strlen(s1);
		while (c && ft_strchr(set, s1[c]))
			c--;
		return (ft_substr(s1, 0, c + 1));
	}
	return (NULL);
}
