/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 17:55:32 by awoods            #+#    #+#             */
/*   Updated: 2021/04/20 17:55:36 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t	len)
{
	size_t	i;

	i = 0;
	if ((!dst && !src) || len == 0)
		return (dst);
	if (dst <= src)
	{
		while (i < len)
		{
			((char *) dst)[i] = ((const char *) src)[i];
			i++;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
