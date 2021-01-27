/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:16:37 by cilla             #+#    #+#             */
/*   Updated: 2021/01/25 18:20:16 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putstr(char *str, t_settings *settings, int len)
{
	int index;

	if (!str || len == 0)
		return ;
	if (len == -1)
		while (*str)
			ft_printf_putchar(settings, *str++);
	else
	{
		index = 0;
		while (index < len)
			ft_printf_putchar(settings, str[index++]);
	}
}
