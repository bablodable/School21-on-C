/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_empty.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:28:04 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 20:29:58 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_formatter_empty(t_bundle *bundle)
{
	if (bundle->flags->precision_enabled)
		bundle->flags->precision_enabled = 0;
	if (bundle->flags->letter == '\0')
		return (ft_emptystr());
	bundle->forced_len = 1;
	return (ft_chrtostr(bundle->flags->letter));
}
