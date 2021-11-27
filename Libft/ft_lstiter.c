/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:35:38 by awoods            #+#    #+#             */
/*   Updated: 2021/04/25 21:35:40 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list	*lst, void	(*f)(void *))
{
	t_list	*new_lst;

	if (!lst)
		return ;
	new_lst = lst;
	while (new_lst != NULL)
	{
		f(new_lst->content);
		new_lst = new_lst->next;
	}
}
