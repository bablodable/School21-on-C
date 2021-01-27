/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_padder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:20:09 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 22:03:28 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_padder_add_number_precision(t_bundle *bundle, \
char *abs_itoa, int negative, int offset)
{
	int		required;
	char	*zeros;
	char	*str;
	size_t	len;

	len = ft_strlen(abs_itoa);
	required = ft_printf_which_unit(bundle->flags, negative + offset);
	required -= len;
	required = ft_zero_if_neg(required);
	if (negative)
		required++;
	if (!(zeros = ft_chrmult('0', required)))
		return (abs_itoa);
	str = ft_strjoin_free(zeros, abs_itoa, FT_STRJOIN_FREE_BOTH);
	if (negative)
		str[0] = '-';
	return (str);
}
