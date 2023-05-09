/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:46:21 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:30:23 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Returns the last node of the list*/
t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst -> next)
			lst = lst -> next;
		return (lst);
	}
	return (0);
}
