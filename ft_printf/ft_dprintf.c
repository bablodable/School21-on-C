/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:51:20 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 19:56:03 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	t_settings settings;

	settings.format = format;
	settings.written = 0;
	settings.fd = fd;
	va_start(settings.params, format);
	ft_handle(&settings);
	va_end(settings.params);
	return (settings.written);
}
