/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:34:39 by awoods            #+#    #+#             */
/*   Updated: 2021/04/25 21:34:44 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*new_lst;

	if (!lst && !new)
		return ;
	if (!*lst)
		*lst = new;
	new_lst = *lst;
	while (new_lst->next != NULL)
		new_lst = new_lst->next;
	new_lst->next = new;
	new->next = NULL;
}
