/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:40:49 by manujime          #+#    #+#             */
/*   Updated: 2023/04/02 23:02:41 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strcmp() and strncmp() functions lexico-
     graphically compare the null-terminated
     strings s1 and s2.
     The strncmp() function compares not more than
     n characters.  Because strncmp() is designed
     for comparing strings rather than binary
     data, characters that appear after a `\0'
     character are not compared.
	 
	 The strcmp() and strncmp() functions return
     an integer greater than, equal to, or less
     than 0, according as the string s1 is greater
     than, equal to, or less than the string s2.
     The comparison is done using unsigned charac-
     ters, so that `\200' is greater than `\0'.*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s2[i] || s1[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
