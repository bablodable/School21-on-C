/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:05:20 by csebasti          #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bsq.h"

void	ft_put_result(char *str, int start)
{
	int i;

	i = 0;
	while (str[start + i])
		i++;
	write(1, &str[start], i);
}

void	ft_strcpy(char *dest, char *str)
{
	int length;

	length = 0;
	while (str[length])
	{
		dest[length] = str[length];
		length++;
	}
	dest[length] = str[length];
}
