/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:16:39 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:18:40 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*tests for any printing character, including space
     (` ')*/
int	ft_isprint(int c)
{
	if ((c >= 32 && c < 127))
		return (1);
	else
		return (0);
}
