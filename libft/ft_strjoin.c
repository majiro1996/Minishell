/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:04:05 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 12:07:32 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/*concatenate two strings into a new string (with malloc)
Allocates (with malloc(3)) and returns a new string, which is the
result of the concatenation of ’s1’ and ’s2’.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	c;
	size_t	j;

	c = 0;
	j = 0;
	if (s1 && s2)
	{
		newstring = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (newstring == NULL)
			return (NULL);
		while (s1[c] != '\0')
		{
			newstring[c] = s1[c];
			c++;
		}
		while (s2[j] != '\0')
		{
			newstring[c + j] = s2[j];
			j++;
		}
		newstring [c + j] = '\0';
		return (newstring);
	}
	return (NULL);
}
