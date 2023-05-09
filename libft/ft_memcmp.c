/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:27:10 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:39:32 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The memcmp() function compares byte string s1
     against byte string s2.  Both strings are
     assumed to be n bytes long.
	      The memcmp() function returns zero if the two
     strings are identical, otherwise returns the
     difference between the first two differing
     bytes (treated as unsigned char values, so
     that `\200' is greater than `\0', for exam-
     ple).  Zero-length strings are always identi-
     cal.  This behavior is not required by C and
     portable code should only depend on the sign
     of the returned value.*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}
