/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:36:06 by awoods            #+#    #+#             */
/*   Updated: 2021/04/25 21:36:08 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list	*lst, void	*(*f)(void *), void	(*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	temp = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst != NULL)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&temp, new);
		lst = lst->next;
	}
	return (temp);
}
