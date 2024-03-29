/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:57:12 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 22:36:43 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_f_decimal_should_be_empty(int eq_zero, t_flags *flags)
{
	return (eq_zero && flags->precision_enabled && flags->precision == 0);
}

char	*ft_printf_formatter_decimal(t_bundle *bundle)
{
	long	decimal;
	char	*str;

	decimal = va_arg(bundle->settings->params, int);
	if (ft_printf_f_decimal_should_be_empty(decimal == 0, bundle->flags))
		return (ft_emptystr());
	str = ft_itoa_base(ft_abs(decimal), BASE_DECIMAL);
	str = ft_printf_padder_add_number_precision(bundle, str, decimal < 0, 0);
	return (str);
}
