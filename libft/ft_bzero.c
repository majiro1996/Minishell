/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:48:20 by manujime          #+#    #+#             */
/*   Updated: 2022/10/05 14:52:57 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
/*writes n zeroed bytes to the string s.  If n is zero, bzero() does nothing.*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
