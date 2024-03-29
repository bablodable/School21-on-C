/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:05:21 by cilla             #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct	s_instr
{
	int		height;
	int		length;
	int		width;
	char	empty;
	char	obst;
	char	full;
}				t_instr;

typedef struct	s_record
{
	int x;
	int y;
	int max;
}				t_record;

void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(char *str);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
void			ft_strcpy(char *dest, char *str);
void			ft_start(char *str);
int				ft_get_width(char *str, t_instr info, int width);
t_instr			*ft_first_line(char *str);
int				ft_strlen_mod(char *str);
char			*cat_str(char *str, int n);
void			ft_fill_board(t_record *record, char *str, t_instr *info);
void			ft_get_record(t_instr *info, char *str, t_record *record);
int				ft_check_case(char *str, t_instr *info,
				int position[2], int size);
int				ft_check_square(char *str, int position[2],
				t_instr *info, int size);
t_record		*ft_new_record(void);
void			ft_put_result(char *str, int start);
void			ft_concat(char *dest, char *src, int *size, int buff_size);
int				ft_bigger_sqr(char *str, int position[2],
				t_instr *info, int size);
#endif
