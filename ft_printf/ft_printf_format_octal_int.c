/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_octal_int.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:11:15 by cilla             #+#    #+#             */
/*   Updated: 2021/01/27 13:58:09 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*i_ft_printf_f_octal_int(char *converted, t_flags *flags, \
int is_zero)
{
	int		size;
	char	*str;

	size = 0;
	if (flags->precision_enabled)
	{
		if (!flags->precision_negative)
			size = flags->precision - ft_strlen(converted);
	}
	else if (!flags->side && flags->padding_char == '0')
		size = flags->width - ft_strlen(converted);
	if (flags->hashtag && !is_zero)
		str = ft_strdup("0");
	else
		str = ft_chrmult('0', ft_zero_if_neg(size));
	return (ft_strjoin_free(str, converted, FT_STRJOIN_FREE_BOTH));
}

char		*ft_printf_formatter_octal_int(t_bundle *bundle)
{
	unsigned int	decimal;
	char			*str;

	decimal = va_arg(bundle->settings->params, unsigned int);
	bundle->flags->hex_upper = bundle->flags->letter == 'X';
	if (!bundle->flags->hashtag && ft_printf_f_decimal_should_be_empty(decimal
	==
	0, bundle->flags))
		return (ft_emptystr());
	str = ft_itoa_base(decimal, BASE_OCTAL);
	str = i_ft_printf_f_octal_int(str, bundle->flags, decimal == 0);
	str = ft_printf_padder_add_number_precision(bundle, str, decimal < 0, 0);
	return (str);
}
