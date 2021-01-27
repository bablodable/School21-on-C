/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formatter_char.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 18:09:00 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 18:09:00 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_formatter_char(t_bundle *bundle)
{
	char	c;

	c = (char)va_arg(bundle->settings->params, int);
	bundle->forced_len = 1;
	return (ft_chrtostr(c));
}
