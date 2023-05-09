/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:45:13 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:24:04 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Deletes ands frees the given node 'lst' and
all consecutives nodes, using the function 'del' and free.
-At the end, the pointer to the list must be NULL.
 Elimina y libera el nodo ’lst’ dado y todos los
.*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (*lst)
	{
		while (*lst)
		{
			aux = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = aux;
		}
		*lst = 0;
	}
	return ;
}
