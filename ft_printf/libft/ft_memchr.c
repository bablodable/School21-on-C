/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:24:52 by cilla             #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	UC		*dest;

	index = 0;
	dest = (UC *)s;
	while (index < n)
	{
		if (dest[index] == (UC)c)
			return (&dest[index]);
		index++;
	}
	return (NULL);
}
