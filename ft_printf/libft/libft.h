/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:07:27 by cilla             #+#    #+#             */
/*   Updated: 2021/01/27 14:13:07 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>

# define IN 0
# define OUT 1
# define ERR 2

# define BASE_BINARY "01"
# define BASE_DECIMAL "0123456789"
# define BASE_OCTAL "01234567"
# define BASE_HEX_LOW "0123456789abcdef"
# define BASE_HEX_UP "0123456789ABCDEF"

# define FT_STRJOIN_FREE_DONT 0
# define FT_STRJOIN_FREE_FIRST 1
# define FT_STRJOIN_FREE_SECOND 2
# define FT_STRJOIN_FREE_BOTH 3

# define UC unsigned char

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_atoi(const char *str);
void				*ft_memset(void *a, int c, size_t length);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strnstr(const char *haystack, const char *needle, size_t
len);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(char const*s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
int					ft_strcontain(const char*str, char c);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
char				*ft_itoa_base(long n, char *base);
size_t				ft_itoa_base_nsize(long number, size_t radix);
char				*ft_chrmult(char c, size_t times);
char				*ft_memjoin(void *s1, size_t l1, void *s2, size_t l2);
char				*ft_strjoin_sided(char const *s1, char const *s2, int side);
char				*ft_chrtostr(char c);
long long int		ft_abs(long long int number);
char				*ft_emptystr(void);
long long int		ft_zero_if_neg(long long int number);
char				*ft_strjoin_free(char *s1, char *s2, int policy);
int					ft_iswspace(int c);
char				*ft_itoa_u_base(unsigned long n, char *base);
size_t				ft_itoa_u_base_nsize(unsigned long number, size_t radix);
void				ft_fake_use(void *something);

#endif
