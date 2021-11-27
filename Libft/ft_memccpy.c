/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:56:06 by awoods            #+#    #+#             */
/*   Updated: 2021/04/20 14:56:11 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t	n)
{
	size_t	index;

	index = 0;
	while (n > index)
	{
		((unsigned char *)dst)[index] = ((const unsigned char *)src)[index];
		if (((unsigned char *)src)[index] == (unsigned char)c)
			return (&dst[++index]);
		index++;
	}
	return (NULL);
}
