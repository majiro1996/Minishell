/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:28:28 by manujime          #+#    #+#             */
/*   Updated: 2022/10/04 16:05:31 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*the strchr() function locates the first occurrence
     of c (converted to a char) in the string pointed to
     by s.  The terminating null character is considered
     to be part of the string; therefore if c is `\0',
     the functions locate the terminating `\0'.
	- The functions strchr() and strrchr() return a
     pointer to the located character, or NULL if the
     character does not appear in the string.*/
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}
