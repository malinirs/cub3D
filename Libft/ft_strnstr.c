/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoods <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:55:56 by awoods            #+#    #+#             */
/*   Updated: 2021/04/21 19:55:59 by awoods           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t	len)
{
	size_t	h;
	size_t	n;

	n = 0;
	h = 0;
	if (!needle[n])
		return ((char *)&haystack[0]);
	while (n < len && haystack[h])
	{
		if (haystack[h] == needle[0])
		{
			while (haystack[h + n] == needle[n] && h + n <= len && needle[n])
				n++;
			if (!needle[n] && h + n <= len)
				return ((char *)&haystack[h]);
		}
		h++;
	}
	return (NULL);
}
