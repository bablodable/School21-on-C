/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_uint.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:46:45 by cilla             #+#    #+#             */
/*   Updated: 2021/01/27 13:57:55 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_formatter_uint(t_bundle *bundle)
{
	unsigned int	decimal;
	char			*itoa;

	decimal = va_arg(bundle->settings->params, unsigned int);
	if (ft_printf_f_decimal_should_be_empty(decimal == 0, bundle->flags))
		return (ft_emptystr());
	itoa = ft_itoa_u_base(decimal, BASE_DECIMAL);
	if (itoa && bundle->flags->precision_enabled)
		return (ft_printf_padder_add_number_precision(bundle, itoa, 0, 0));
	return (itoa);
}
