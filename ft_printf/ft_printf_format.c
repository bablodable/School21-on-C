/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:39:19 by cilla             #+#    #+#             */
/*   Updated: 2021/01/27 14:08:44 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_format(t_settings *settings, size_t *index)
{
	t_flags		flags;
	void		*formatter;
	size_t		start;
	t_bundle	bundle;

	bundle = (t_bundle) { settings, &flags, index, -1 };
	start = *index;
	ft_printf_flag_init(&flags);
	while ((flags.letter = settings->format[*index]))
	{
		formatter = ft_printf_get_formatter(flags.letter);
		if (formatter != NULL || !ft_printf_is_flag_char(flags.letter))
			break ;
		*index += 1;
	}
	if (start != *index)
		ft_printf_flag_parse(&bundle, start, *index);
	ft_format_process(&bundle, formatter);
}

void	ft_format_process(t_bundle *bundle, char *(*formatter)(t_bundle *))
{
	char *str;

	if (formatter == NULL)
		formatter = &ft_printf_formatter_empty;
	*(bundle->index) += 1;
	str = (*(formatter))(bundle);
	str = ft_printf_flag_handle(bundle, str);
	ft_printf_putstr(str, bundle->settings, bundle->forced_len);
	free(str);
}
