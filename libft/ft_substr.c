/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:21:02 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 12:33:37 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*extract substring from string
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newstring;
	size_t	c;
	size_t	j;
	long	chars;

	c = 0;
	j = 0;
	chars = len;
	if (start + len > ft_strlen(s))
		chars = ft_strlen(s) - start;
	if (chars < 0)
		chars = 0;
	newstring = (char *)malloc(sizeof(char) * (chars + 1));
	if (!newstring)
		return (NULL);
	while (s[c] != '\0')
	{
		if (c >= start && j < len)
			newstring[j++] = s[c];
		c++;
	}
	newstring[j] = '\0';
	return (newstring);
}
