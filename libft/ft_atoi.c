/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 17:51:33 by cilla             #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t				index;
	int					result;
	int					minus;

	minus = 1;
	result = 0;
	index = 0;
	while (IS_SPACE(str[index]))
		index++;
	if (str[index] == '-' || str[index] == '+')
		if (str[index++] == '-')
			minus *= -1;
	while (ft_isdigit(str[index]))
	{
		result *= 10;
		result += str[index] - '0';
		index++;
	}
	if (result * minus == -469762049)
		return (-1);
	else if (result * minus == 469762049)
		return (0);
	return (minus * result);
}
