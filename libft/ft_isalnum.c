/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:59:59 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:18:11 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*tests for any character for which isalpha(3) or
     isdigit(3) is true*/
int	ft_isalnum(int c)
{
	if (!((c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9')))
		return (0);
	else
		return (1);
}
