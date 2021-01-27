/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:31:28 by cilla             #+#    #+#             */
/*   Updated: 2021/01/26 19:32:13 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int policy)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	if (policy != FT_STRJOIN_FREE_DONT)
	{
		if (policy == FT_STRJOIN_FREE_FIRST || policy == FT_STRJOIN_FREE_BOTH)
			free(s1);
		if (policy == FT_STRJOIN_FREE_SECOND || policy == FT_STRJOIN_FREE_BOTH)
			free(s2);
	}
	return (joined);
}
