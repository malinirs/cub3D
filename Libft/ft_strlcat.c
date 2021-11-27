/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <awoods@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:33:49 by awoods            #+#    #+#             */
/*   Updated: 2021/04/19 20:13:46 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	size_dst;
	size_t	ind;

	len_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	i = size_dst;
	if (size == 0 || size_dst >= size)
		return (len_src + size);
	ind = 0;
	if (size != 0)
	{
		while (src[ind] != '\0' && i + 1 < size)
			dst[i++] = src[ind++];
		dst[i] = '\0';
	}
	return (len_src + size_dst);
}
