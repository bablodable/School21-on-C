/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:36:26 by cilla             #+#    #+#             */
/*   Updated: 2021/01/10 16:42:02 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

# define UC unsigned char
# define MAX(a,b) (((a)>(b)) ? (a) : (b))
# define GNL_ERROR -1
# define GNL_READ 1
# define GNL_END_REACHED 0

typedef struct		s_gnl_holder
{
	int				init;
	int				reached;
	size_t			byte_read;
	unsigned char	buffer[BUFFER_SIZE];
	size_t			offset;
	unsigned char	*stored;
	size_t			stored_len;
}					t_gnl_h;

int					get_next_line(int fd, char **line);
void				*ft_memcpy(void *dst, const void *src, size_t n);

#endif
