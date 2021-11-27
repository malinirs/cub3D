/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:07:54 by awoods            #+#    #+#             */
/*   Updated: 2021/04/22 16:07:56 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t	size)
{
	void	*str;
	size_t	n;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	n = count * size;
	while (n > 0)
	{
		((char *)str)[n - 1] = '\0';
		n--;
	}
	return (str);
}
