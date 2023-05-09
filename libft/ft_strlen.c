/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:30:29 by manujime          #+#    #+#             */
/*   Updated: 2022/09/22 12:11:03 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*computes the length of the string, returns the number of characters that 
precede the terminating NUL characters*/

#include<stddef.h>

int	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}
