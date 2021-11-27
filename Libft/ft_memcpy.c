/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 12:51:05 by awoods            #+#    #+#             */
/*   Updated: 2021/04/20 12:51:12 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t	n)
{
	if ((!dst && !src) || n == 0)
		return (dst);
	while (n > 0)
	{
		((char *)dst)[n - 1] = ((const char *)src)[n - 1];
		n--;
	}
	return (dst);
}
