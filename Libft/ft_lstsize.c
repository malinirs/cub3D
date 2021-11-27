/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:36:34 by awoods            #+#    #+#             */
/*   Updated: 2021/04/25 21:36:39 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list	*lst)
{
	int		i;
	t_list	*new_lst;

	if (!lst)
		return (0);
	i = 0;
	new_lst = lst;
	while (new_lst != NULL)
	{
		new_lst = new_lst->next;
		i++;
	}
	return (i);
}
