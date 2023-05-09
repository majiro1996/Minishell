/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:22:09 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:22:11 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Adds the node 'new' to the end of the list lst*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*k;

	if (new && *lst)
	{
		k = ft_lstlast(*lst);
		k -> next = new;
		return ;
	}
	*lst = new;
	return ;
}
