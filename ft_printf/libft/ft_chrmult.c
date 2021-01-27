/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrmult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:34:11 by cilla             #+#    #+#             */
/*   Updated: 2021/01/25 20:34:11 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrmult(char c, size_t times)
{
	char	*str;

	if (!(str = malloc((times + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, c, times);
	str[times] = '\0';
	return (str);
}
