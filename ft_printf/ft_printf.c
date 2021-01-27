/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:50:34 by cilla             #+#    #+#             */
/*   Updated: 2021/01/18 17:40:35 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_settings settings;

	settings.format = format;
	settings.written = 0;
	settings.fd = FT_PRINTF_FD;
	va_start(settings.params, format);
	ft_handle(&settings);
	va_end(settings.params);
	return (settings.written);
}
