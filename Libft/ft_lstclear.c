/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:33:41 by awoods            #+#    #+#             */
/*   Updated: 2021/04/25 21:33:45 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void	(*del)(void*))
{
	t_list	*new_lst;

	if (!*lst || !del)
		return ;
	while (*lst != NULL)
	{
		new_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = new_lst;
	}
}
