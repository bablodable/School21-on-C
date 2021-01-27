/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:33:58 by cilla             #+#    #+#             */
/*   Updated: 2021/01/10 15:11:24 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	go_init(t_gnl_h *holder, int cilla, int return_value)
{
	if (!(holder->init == 1 && !cilla))
	{
		holder->init = 1;
		holder->reached = 0;
		holder->offset = BUFFER_SIZE;
		holder->stored = NULL;
		holder->stored_len = 0;
	}
	return (return_value);
}

static UC	*gnl_store(t_gnl_h *holder, int cilla)
{
	UC c;
	UC *new;

	c = holder->buffer[holder->offset];
	holder->offset += 1;
	if (!(new = malloc((holder->stored_len + 1) * sizeof(char *))))
		return (NULL);
	if (holder->stored != NULL)
	{
		ft_memcpy(new, holder->stored, holder->stored_len);
		free(holder->stored);
	}
	if (c == '\n' || cilla)
	{
		new[holder->stored_len] = '\0';
		holder->stored = NULL;
		holder->stored_len = 0;
		return (new);
	}
	new[holder->stored_len] = c;
	holder->stored_len += 1;
	holder->stored = new;
	return (NULL);
}

static int	gnl_peter_pen(t_gnl_h *holder, char **return_line)
{
	int cilla;
	UC	*line;

	while (holder->offset + 1 < BUFFER_SIZE + 1)
	{
		cilla = holder->offset >= holder->byte_read;
		line = gnl_store(holder, cilla);
		if (line != NULL)
		{
			if (cilla)
				holder->reached = 1;
			*return_line = (char *)line;
			return (1);
		}
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static t_gnl_h	holders[OPEN_MAX];
	t_gnl_h			*holder;

	if (line == NULL || BUFFER_SIZE == 0 || fd < 0)
		return (GNL_ERROR);
	*line = NULL;
	holder = (holders + fd);
	go_init(holder, 0, 1);
	while (1)
	{
		if (holder->offset == BUFFER_SIZE)
		{
			holder->byte_read = read(fd, holder->buffer, BUFFER_SIZE);
			holder->offset = 0;
		}
		if (holder->byte_read == (size_t)-1)
			return (GNL_ERROR);
		if (gnl_peter_pen(holder, line))
		{
			if (holder->byte_read == 0 || holder->reached)
				return (go_init(holder, 1, GNL_END_REACHED));
			return (GNL_READ);
		}
	}
}
