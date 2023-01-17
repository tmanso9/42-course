/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:14:33 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:29:53 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
Takes as a parameter an element and frees the
memory of the element’s content using the function
’del’ given as a parameter and free the element.
The memory of ’next’ must not be freed.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	(*del)(lst->content);
	free(lst);
}
