/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:23:23 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:37:48 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* The memchr() function locates the first
     occurrence of c (converted to an unsigned
     char) in string s.
	The memchr() function returns a pointer to
     the byte located, or NULL if no such byte
     exists within n bytes.*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*saux;
	size_t			i;

	i = 0;
	saux = (unsigned char *)s;
	while (n > i)
	{
		if ((unsigned char)c == saux[i])
			return (&saux[i]);
		i++;
	}
	return (0);
}
