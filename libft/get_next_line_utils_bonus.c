/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:45:14 by manujime          #+#    #+#             */
/*   Updated: 2023/03/27 13:32:04 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void			*mem;
	unsigned char	*temp;
	size_t			c;

	mem = malloc(size * count);
	if (!mem)
		return (0);
	temp = mem;
	c = 0;
	while (c++ < size * count)
		*temp++ = 0;
	return (mem);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}

int	ft_strlen_gnl(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*newstring;
	size_t	c;
	size_t	j;

	c = -1;
	j = -1;
	if (s1 && s2)
	{
		newstring = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (newstring == NULL)
			return (NULL);
		while (s1[++c] != '\0')
		{
			newstring[c] = s1[c];
		}
		while (s2[++j] != '\0')
		{
			newstring[c + j] = s2[j];
		}
		newstring [c + j] = '\0';
		free(s1);
		return (newstring);
	}
	return (NULL);
}
