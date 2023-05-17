/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:51:54 by manujime          #+#    #+#             */
/*   Updated: 2023/05/17 14:33:49 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//sends the string 's' to the specified file descriptor
void	ft_putstr_fd(char *s, int fd)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
	{
		write(fd, &s[c], 1);
		c++;
	}
}

void	ft_putstr(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		write(1, &str[c], 1);
		c++;
	}
}
