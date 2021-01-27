/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:38:36 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 22:33:16 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

# include "libft/libft.h"

# define FT_PRINTF_CHAR_FORMAT '%'
# define FT_PRINTF_SUP_TYPES "cspdiuxX%o"
# define FT_PRINTF_FD OUT

typedef struct	s_settings
{
	int			written;
	const char	*format;
	va_list		params;
	int			fd;
	int			end;
}				t_settings;

typedef struct	s_flags
{
	char		letter;
	int			width;
	int			valid;
	int			minus_sign_used;
	int			side;
	char		padding_char;
	int			width_enabled;
	int			width_negative;
	int			precision_enabled;
	int			precision;
	int			precision_negative;
	int			hashtag;
	int			hex_upper;
}				t_flags;

typedef struct	s_bundle
{
	t_settings	*settings;
	t_flags		*flags;
	size_t		*index;
	int			forced_len;
}				t_bundle;

void			ft_handle(t_settings *settings);
void			ft_printf_putchar(t_settings *settings, char c);
void			ft_printf_format(t_settings *settings, size_t *index);
void			ft_format_process(t_bundle *bundle, char *(*formatter)\
				(t_bundle *));
void			ft_printf_flag_init(t_flags *flags);
int				ft_printf(const char *format, ...);
int				ft_printf_is_flag_char(char c);
void			ft_printf_putstr(char *str, t_settings *settings, int len);
void			*ft_printf_get_formatter(char key);
void			ft_printf_flag_parse(t_bundle *bundle, size_t start, \
size_t end);
void			ft_printf_flag_validate(t_flags *flags, int *should_end);
char			*ft_printf_flag_handle(t_bundle *bundle, char *formatted);
char			*ft_printf_flag_handle_width_m(t_bundle *bundle, char
*formatted);
char			*ft_printf_flag_handle_width(t_bundle *bundle, char *formatted);
char			*ft_printf_padder_add_number_precision(t_bundle *bundle, char
*abs_itoa, int negative, int offset);
int				ft_printf_f_decimal_should_be_empty(int eq_zero, t_flags
*flags);
char			*ft_printf_formatter_decimal(t_bundle *bundle);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_printf_which_unit(t_flags *flags, int offset);
char			*ft_printf_formatter_empty(t_bundle *bundle);
char			*ft_printf_formatter_char(t_bundle *bundle);
char			*ft_printf_formatter_hex_int(t_bundle *bundle);
char			*ft_printf_formatter_octal_int(t_bundle *bundle);
char			*ft_printf_formatter_string(t_bundle *bundle);
char			*ft_printf_formatter_uint(t_bundle *bundle);
int				ft_vdprintf(int fd, const char *format, va_list args);
int				ft_vprintf(const char *format, va_list args);
char			*ft_printf_formatter_pointer(t_bundle *bundle);
char			*ft_printf_formatter_pourcent(t_bundle *bundle);

#endif
