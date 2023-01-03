/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: touteiro <touteiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:10:03 by touteiro          #+#    #+#             */
/*   Updated: 2022/11/29 19:29:46 by touteiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/libft.h"

/*
Adds the element ’new’ at the beginning of the list.
It first checks if the list exists and it has a first link,
then it sets the first link to new->next, and sets new as the first link.
*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
