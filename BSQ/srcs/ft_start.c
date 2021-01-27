/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:54:26 by cilla             #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

int		ft_get_width(char *st, t_instr inf, int width)
{
	int	i;
	int c;
	int lines;

	i = inf.length - 1;
	c = 0;
	lines = 0;
	while (st[++i])
		if (st[i] == '\n')
		{
			if (width != -1 && width != c)
				return (-1);
			width = c;
			c = 0;
			lines++;
		}
		else if (st[i] != inf.empty && st[i] != inf.obst)
			return (-1);
		else if (c == 2147483647)
			return (-1);
		else
			c++;
	if (lines == inf.height)
		return (width);
	return (-1);
}

void	ft_start(char *str)
{
	t_instr		*info;
	t_record	*record;
	int			width;

	info = ft_first_line(str);
	record = ft_new_record();
	if (info)
	{
		width = -1;
		info->width = ft_get_width(str, *info, width);
		if (info->width > 0)
		{
			ft_get_record(info, str, record);
			ft_fill_board(record, str, info);
			ft_put_result(str, info->length);
			free(str);
		}
		else
			ft_putstr("map error\n");
	}
	else
		ft_putstr("map error\n");
}
