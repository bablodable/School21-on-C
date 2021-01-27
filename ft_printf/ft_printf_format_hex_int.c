/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_hex_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:38:23 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 22:05:53 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*i_ft_printf_f_hex_int_get_base(t_bundle *bundle)
{
	if (bundle->flags->hex_upper)
		return (BASE_HEX_UP);
	return (BASE_HEX_LOW);
}

static char	*i_ft_printf_f_hex_int(char *converted, t_flags *flags, int is_zero)
{
	int		size;
	char	*padding;
	char	*str;

	size = 0;
	if (flags->precision_enabled && !flags->precision_negative)
		size = flags->precision - ft_strlen(converted);
	else if (!flags->side && flags->padding_char == '0')
		size = flags->width - ft_strlen(converted) - (flags->hashtag ? 2 : 0);
	padding = ft_chrmult('0', ft_zero_if_neg(size));
	if (flags->hashtag && !is_zero)
	{
		str = ft_strjoin(flags->hex_upper ? "0X" : "0x", padding);
		free(padding);
	}
	else
		str = padding;
	return (ft_strjoin_free(str, converted, FT_STRJOIN_FREE_BOTH));
}

char		*ft_printf_formatter_hex_int(t_bundle *bundle)
{
	unsigned int	decimal;
	char			*str;

	decimal = va_arg(bundle->settings->params, unsigned int);
	bundle->flags->hex_upper = bundle->flags->letter == 'X';
	if (ft_printf_f_decimal_should_be_empty(decimal == 0, bundle->flags))
		return (ft_emptystr());
	str = ft_itoa_base(decimal, i_ft_printf_f_hex_int_get_base(bundle));
	str = i_ft_printf_f_hex_int(str, bundle->flags, decimal == 0);
	str = ft_printf_padder_add_number_precision(bundle, str, 0, 0);
	return (str);
}
