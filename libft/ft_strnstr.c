/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:42:01 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 12:27:23 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strnstr() function locates the first
     occurrence of the null-terminated string
     needle in the string haystack, where not more
     than len characters are searched.  Characters
     that appear after a `\0' character are not
     searched.  Since the strnstr() function is a
     FreeBSD specific API, it should only be used
     when portability is not a concern.
	 
	 If needle is an empty string, haystack is
     returned; if needle occurs nowhere in
     haystack, NULL is returned; otherwise a
     pointer to the first character of the first
     occurrence of needle is returned.*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		a;
	size_t		b;

	a = 0;
	b = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[a] != '\0')
	{
		b = 0;
		while (haystack[a + b] == needle[b] && haystack[a + b] != '\0'
			&& (a + b) < len)
		{
			if (needle[b + 1] == '\0')
				return ((char *)&haystack[a]);
			b++;
		}
		a++;
	}
	return (0);
}
