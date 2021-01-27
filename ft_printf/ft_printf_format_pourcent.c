/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_pourcent.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 21:37:14 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 21:55:44 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_formatter_pourcent(t_bundle *bundle)
{
	ft_fake_use(&bundle);
	return (ft_chrtostr('%'));
}
