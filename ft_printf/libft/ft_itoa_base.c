/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:31:28 by cilla             #+#    #+#             */
/*   Updated: 2021/01/27 13:56:35 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_itoa_base_nsize(long number, size_t radix)
{
	size_t	size;

	size = (number < 0 ? 1 : 0);
	while (1)
	{
		number /= radix;
		size++;
		if (number == 0)
			break ;
	}
	return (size);
}

char	*ft_itoa_base(long n, char *base)
{
	long long	number;
	size_t		radix;
	char		*array;
	size_t		size;

	number = n;
	radix = ft_strlen(base);
	size = ft_itoa_base_nsize(n, radix);
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
		array[size - 1] = base[(number % radix)];
		number /= radix;
		size--;
		if (number == 0)
			break ;
	}
	return (array);
}
