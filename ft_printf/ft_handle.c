/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:25:19 by cilla             #+#    #+#             */
/*   Updated: 2021/01/18 17:40:35 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handle(t_settings *settings)
{
	size_t			index;
	unsigned char	current;

	settings->end = 0;
	index = 0;
	while ((current = settings->format[index]) && !settings->end)
	{
		index++;
		if (current != FT_PRINTF_CHAR_FORMAT)
			ft_printf_putchar(settings, (char)current);
		else
			ft_printf_format(settings, &index);
	}
}
