/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:41:38 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 21:41:38 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_formatter_string(t_bundle *bundle)
{
	char	*str;

	str = va_arg(bundle->settings->params, char *);
	if (str == NULL)
		str = "(null)";
	if (bundle->flags->precision_enabled && !bundle->flags->precision_negative)
		return (ft_substr(str, 0, bundle->flags->precision));
	return (ft_strdup(str));
}
