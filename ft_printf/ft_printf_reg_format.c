/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_reg_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:29:27 by cilla             #+#    #+#             */
/*   Updated: 2021/01/27 15:10:45 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*g_format_key = FT_PRINTF_SUP_TYPES;
char	*(*g_formatters[10])(t_bundle *) = {
		&ft_printf_formatter_char,
		&ft_printf_formatter_string,
		&ft_printf_formatter_pointer,
		&ft_printf_formatter_decimal,
		&ft_printf_formatter_decimal,
		&ft_printf_formatter_uint,
		&ft_printf_formatter_hex_int,
		&ft_printf_formatter_hex_int,
		&ft_printf_formatter_pourcent,
		&ft_printf_formatter_octal_int
};

void	*ft_printf_get_formatter(char key)
{
	size_t index;

	index = 0;
	while (g_format_key[index])
	{
		if (g_format_key[index] == key)
			return (g_formatters[index]);
		index++;
	}
	return (NULL);
}
