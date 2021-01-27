/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:43:36 by cilla             #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t pos;
	size_t index;

	pos = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[pos] != '\0' && pos < len)
	{
		if (haystack[pos] == needle[0])
		{
			index = 1;
			while (needle[index] != '\0' && haystack[pos + index] ==
			needle[index] && (pos + index) < len)
				index++;
			if (needle[index] == '\0')
				return ((char *)&haystack[pos]);
		}
		pos++;
	}
	return (0);
}
