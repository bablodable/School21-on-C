/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_handler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:09:27 by cilla             #+#    #+#             */
/*   Updated: 2021/01/25 20:47:10 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_flag_handle_width(t_bundle *bundle, char *formatted)
{
	size_t	len;
	int		required;
	char	*padding;
	char	*str;
	char	letter;

	letter = ft_tolower(bundle->flags->letter);
	if ((bundle->flags->precision_enabled ||
	bundle->flags->precision_negative) && !ft_strcontain("s%", letter) && (
			(letter != 'x' && letter != 'o') || bundle->flags->precision <
			bundle->flags->width))
	{
		bundle->flags->padding_char = ' ';
	}
	len = ft_strlen(formatted);
	required = bundle->flags->width - len;
	if (required < 0)
		return (formatted);
	padding = ft_chrmult(bundle->flags->padding_char, required);
	if (!padding)
		return (formatted);
	str = ft_strjoin_sided(padding, formatted, bundle->flags->side);
	bundle->forced_len = required + len;
	free(padding);
	return (str);
}

char	*ft_printf_flag_handle_width_m(t_bundle *bundle, char *formatted)
{
	size_t	len;
	int		required;
	char	*padding;
	char	*str;

	if (bundle->flags->precision_enabled && bundle->flags->precision != 0 &&
	bundle->flags->letter != 'c')
		bundle->flags->padding_char = ' ';
	len = bundle->forced_len;
	required = bundle->flags->width - len;
	if (required < 0)
		return (formatted);
	padding = ft_chrmult(bundle->flags->padding_char, required);
	if (!padding)
		return (formatted);
	if (bundle->flags->side)
		str = ft_memjoin(formatted, len, padding, required);
	else
		str = ft_memjoin(padding, required, formatted, len);
	bundle->forced_len = required + len;
	free(padding);
	return (str);
}

char	*ft_printf_flag_handle(t_bundle *bundle, char *formatted)
{
	char	*str;

	if (!bundle->flags->valid)
		return (formatted);
	str = formatted;
	if (bundle->flags->width_enabled)
	{
		if (bundle->forced_len == -1)
			str = ft_printf_flag_handle_width(bundle, str);
		else
			str = ft_printf_flag_handle_width_m(bundle, str);
	}
	if (str != formatted)
		free(formatted);
	return (str);
}
