/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:32:57 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:42:58 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Sends the character 'c to the file despriptor specified*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
