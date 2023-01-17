/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 00:57:56 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:29:43 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
Adds the element ’new’ at the end of the list.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (lst)
	{
		if (*lst)
		{
			elem = ft_lstlast(*lst);
			elem->next = new;
		}
		else
			*lst = new;
	}
}
