/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:21:56 by manujime          #+#    #+#             */
/*   Updated: 2022/10/12 11:22:02 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Adds the node 'new to the end of the list lst*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new -> next = *lst;
		*lst = new;
	}
	else
		return ;
}
