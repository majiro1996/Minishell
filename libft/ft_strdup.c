/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:21:39 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:47:06 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*allocates sufficient memory for
     a copy of the string s1, does the copy, and returns a
     pointer to it.  The pointer may subsequently be used
     as an argument to the function free(3).*/
char	*ft_strdup(const char *s1)
{
	char		*copy;

	copy = malloc ((ft_strlen(s1) + 1));
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s1, (ft_strlen(s1) + 1));
	return (copy);
}
