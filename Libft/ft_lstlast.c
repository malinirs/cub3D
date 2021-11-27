/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:35:53 by awoods            #+#    #+#             */
/*   Updated: 2021/04/25 21:35:56 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	t_list	*new_lst;

	if (!lst)
		return (NULL);
	new_lst = lst;
	while (new_lst->next)
		new_lst = new_lst->next;
	return (new_lst);
}
