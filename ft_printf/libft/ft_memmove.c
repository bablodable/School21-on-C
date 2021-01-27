/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:16:45 by cilla             #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	n;
	size_t	index;
	UC		*dest;
	UC		*source;

	n = 1;
	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (UC *)dst;
	source = (UC *)src;
	if (dst > src)
	{
		n = -1;
		dest = (UC *)(dst + len - 1);
		source = (UC *)(src + len - 1);
	}
	index = 0;
	while (index < len)
	{
		*dest = *source;
		dest += n;
		source += n;
		index++;
	}
	return (dst);
}
