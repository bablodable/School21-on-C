/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_which_unit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:57:54 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 22:07:41 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_which_unit(t_flags *flags, int offset)
{
	if (flags->width_enabled && flags->precision_enabled)
	{
		if (flags->width_negative && !flags->precision_negative)
			return (flags->precision);
		else if (!flags->width_negative && flags->precision_negative)
			return (flags->padding_char == '0' ? flags->width - offset : 0);
		else if (flags->width_negative && flags->precision_negative)
			return (0);
		else
		{
			if (flags->padding_char == '0' && flags->precision == 0)
				return (flags->precision > flags->width ? \
				ft_zero_if_neg(flags->width - offset) : flags->precision);
			else
				return (flags->precision);
		}
	}
	else if (flags->width_enabled && !flags->precision_enabled)
		return (!flags->width_negative && flags->padding_char == '0' ?
		flags->width - offset : 0);
	else if (!flags->width_enabled && flags->precision_enabled)
		return (!flags->precision_negative ? flags->precision : 0);
	return (0);
}
