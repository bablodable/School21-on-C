/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sided.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:37:39 by cilla             #+#    #+#             */
/*   Updated: 2021/01/25 20:38:35 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sided(char const *s1, char const *s2, int side)
{
	if (side)
		return (ft_strjoin(s2, s1));
	return (ft_strjoin(s1, s2));
}
