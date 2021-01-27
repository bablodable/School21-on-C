/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:56:18 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 21:56:18 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	t_settings settings;

	settings.format = format;
	settings.written = 0;
	settings.fd = fd;
	va_copy(settings.params, args);
	ft_handle(&settings);
	va_end(settings.params);
	return (settings.written);
}
