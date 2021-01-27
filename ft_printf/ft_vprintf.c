/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:57:25 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 21:57:25 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vprintf(const char *format, va_list args)
{
	t_settings settings;

	settings.format = format;
	settings.written = 0;
	settings.fd = FT_PRINTF_FD;
	va_copy(settings.params, args);
	ft_handle(&settings);
	va_end(settings.params);
	return (settings.written);
}
