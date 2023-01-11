/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:06:43 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:30:02 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
Iterates the list ’lst’ and applies the function
’f’ to the content of each element.  Creates a new
list resulting of the successive applications of
the function ’f’.  The ’del’ function is used to
delete the content of an element if needed.
Returns the new list.  NULL if the allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		temp = (*f)(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			ft_lstclear(&first, del);
			(*del)(temp);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}
