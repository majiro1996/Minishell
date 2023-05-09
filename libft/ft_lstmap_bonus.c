/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:10:28 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:31:33 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Iterates the list ’lst’ and applies the function ’f’ to the content of
each element. Creates a new list resulting of the successive applications of
the function ’f’. The ’del’ function is used to delete the content of an
element if needed.
-Returns the new list or NULL if the memory allocation fails.*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*nd;

	if (lst)
	{
		aux = 0;
		while (lst)
		{
			nd = ft_lstnew(f(lst -> content));
			if (nd == NULL)
			{
				ft_lstclear(&aux, del);
				return (0);
			}
			ft_lstadd_back(&aux, nd);
			lst = lst -> next;
		}
		return (aux);
	}
	return (NULL);
}
