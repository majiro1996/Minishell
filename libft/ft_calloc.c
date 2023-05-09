/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:39:49 by manujime          #+#    #+#             */
/*   Updated: 2022/10/25 17:51:38 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/*The calloc() function contiguously allocates enough
     space for count objects that are size bytes of memory
     each and returns a pointer to the allocated memory.
     The allocated memory is filled with bytes of value
     zero.
	 If successful, returns a pointer to allocated memory.  If there is an
     error, returns a NULL pointer and set errno to ENOMEM.*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}
