/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 01:24:49 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:29:50 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
Deletes and frees the given element and every successor of that element,
using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*swap;

	if (!lst || !*lst || !del)
		return ;
	while (lst && *lst)
	{
		swap = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = swap;
	}
	lst = NULL;
}
