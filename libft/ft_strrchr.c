/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:26:13 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 12:27:56 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*The strrchr() function is identical to strchr(),
     except it locates the last occurrence of c.
     return a
     pointer to the located character, or NULL if the
     character does not appear in the string.*/
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((char *)s);
	while (i > 0 && s[i] != (char)c)
		i --;
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (0);
}
