/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:23:38 by cilla             #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	internal_items(long number)
{
	size_t size;

	size = (number < 0 ? 1 : 0);
	while (1)
	{
		number /= 10;
		size++;
		if (number == 0)
			break ;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	long	number;
	char	*array;
	size_t	size;

	number = n;
	size = internal_items(n);
	if (!(array = malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (number < 0)
	{
		array[0] = '-';
		number *= -1;
	}
	array[size] = '\0';
	while (1)
	{
		array[size - 1] = (number % 10 + '0');
		number /= 10;
		size--;
		if (number == 0)
			break ;
	}
	return (array);
}
