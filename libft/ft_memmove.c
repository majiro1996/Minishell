/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 13:00:44 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:41:52 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*copies len bytes from string src to string dst. The two strings may overlap;
	the copy is always done in a non-destructive manner.
	returns dst*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*auxdst;
	unsigned char	*auxsrc;

	auxdst = (unsigned char *)dst;
	auxsrc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		auxsrc = auxsrc + (len - 1);
		auxdst = auxdst + (len - 1);
		while (len--)
			*auxdst-- = *auxsrc--;
	}
	else if (src >= dst)
	{
		while (len--)
			*auxdst++ = *auxsrc++;
	}
	return (dst);
}
