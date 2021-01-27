/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_validator.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:36:25 by cilla             #+#    #+#             */
/*   Updated: 2021/01/25 20:01:09 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flag_validate(t_flags *flags, int *should_end)
{
	if (flags->valid)
		return ;
	flags->valid = (flags->width_enabled || flags->precision_enabled ||
			flags->hex_upper || flags->hashtag);
	flags->valid = flags->valid && flags->letter != '\0';
	*should_end = flags->letter == '\0';
}
