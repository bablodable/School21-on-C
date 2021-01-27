/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:14:12 by cilla             #+#    #+#             */
/*   Updated: 2021/01/18 19:19:26 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flag_init(t_flags *flags)
{
	flags->letter = '\0';
	flags->padding_char = ' ';
	flags->hashtag = 0;
	flags->hex_upper = 0;
	flags->minus_sign_used = 0;
	flags->precision = 0;
	flags->side = 0;
	flags->width_negative = 0;
	flags->valid = 0;
	flags->precision_enabled = 0;
	flags->precision_negative = 0;
	flags->width = 0;
	flags->width_enabled = 0;
}
