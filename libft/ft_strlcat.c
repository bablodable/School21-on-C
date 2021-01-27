/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:54:20 by cilla             #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dest;
	char	*source;
	size_t	dstlen;
	size_t	index;

	index = dstsize;
	dest = dst;
	source = (char *)src;
	while (index-- != 0 && *dest != '\0')
		dest++;
	dstlen = dest - dst;
	index = dstsize - dstlen;
	if (index == 0)
		return (dstlen + ft_strlen(src));
	while (*source != '\0')
	{
		if (index > 1)
		{
			*dest++ = *source;
			index--;
		}
		source++;
	}
	*dest = '\0';
	return (dstlen + (source - src));
}
