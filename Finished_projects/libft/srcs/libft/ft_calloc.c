/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:17:56 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:27:58 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
The calloc() function allocates memory  for an  array  of  count elements
of size bytes each and returns a pointer to the allocated memory.
The  memory  is  set to zero.  If count or size is 0, then  calloc()
returns either NULL, or a unique pointer value that can later be
successfully passed to free(). If  the  multiplication  of  count and size
would result in integer overflow, then calloc()  returns  an  error.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
