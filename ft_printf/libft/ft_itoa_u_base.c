/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:33:03 by cilla             #+#    #+#             */
/*   Updated: 2021/01/27 13:56:48 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_itoa_u_base_nsize(unsigned long number, size_t radix)
{
	size_t	size;

	size = 0;
	while (1)
	{
		number /= radix;
		size++;
		if (number == 0)
			break ;
	}
	return (size);
}

char	*ft_itoa_u_base(unsigned long n, char *base)
{
	long long	number;
	size_t		radix;
	char		*array;
	size_t		size;

	number = n;
	radix = ft_strlen(base);
	size = ft_itoa_u_base_nsize(n, radix);
	if (!(array = malloc((size + 1) * sizeof(char))))
		return (NULL);
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
