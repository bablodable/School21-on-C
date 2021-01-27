/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 13:34:05 by cilla             #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		internal_items(char const *s, char c)
{
	size_t	index;
	size_t	count;
	size_t	length;

	index = 0;
	count = 0;
	length = 0;
	while (s[index])
	{
		if (s[index] == c)
		{
			if (length != 0)
				count++;
			length = 0;
		}
		else
			length++;
		index++;
	}
	return (count + (length != 0 ? 1 : 0));
}

static void			internal_do(char const *s, char c, char **array, \
	size_t item_count)
{
	char	*str;
	size_t	array_index;
	size_t	index;
	size_t	length;

	array_index = 0;
	index = 0;
	length = 0;
	while (array_index < item_count)
	{
		if (s[index] == c || s[index] == '\0')
		{
			if (length != 0)
			{
				str = ft_calloc(length + 1, sizeof(char));
				ft_memcpy(str, s + index - length, length);
				array[array_index] = str;
				array_index++;
			}
			length = 0;
		}
		else
			length++;
		index++;
	}
}

char				**ft_split(char const *s, char c)
{
	size_t	item_count;
	char	**array;

	if (!s)
		return (NULL);
	item_count = internal_items(s, c);
	if (!(array = malloc((item_count + 1) * sizeof(char *))))
		return (NULL);
	internal_do(s, c, array, item_count);
	array[item_count] = NULL;
	return (array);
}
