/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_pointer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:24:35 by cilla             #+#    #+#             */
/*   Updated: 2021/01/27 13:59:07 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_printf_formatter_pointer_second_part(char *str, \
unsigned long ptr, t_bundle *bundle)
{
	if (ptr == 0 && bundle->flags->precision_enabled &&
	bundle->flags->precision == 0)
	{
		free(str);
		return (ft_emptystr());
	}
	return (str);
}

char		*ft_printf_formatter_pointer(t_bundle *bundle)
{
	unsigned long	ptr;
	char			*itoa;
	char			*str;

	ptr = (unsigned long)va_arg(bundle->settings->params, void *);
	itoa = ft_itoa_u_base(ptr, BASE_HEX_LOW);
	str = ft_printf_padder_add_number_precision(bundle, itoa, 0, 2);
	str = ft_printf_formatter_pointer_second_part(str, ptr, bundle);
	str = ft_strjoin_free("0x", str, FT_STRJOIN_FREE_SECOND);
	return (str);
}
