/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cilla <cilla@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:00:35 by cilla             #+#    #+#             */
/*   Updated: 2020/12/09 20:10:52 by cilla            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
		t_list *list;

		if (!(list = malloc(sizeof(t_list))))
			return (NULL);
		list->content = content;
		list->next = NULL;
		return (list);
}

//int		main(void)
//{
//	char	str[] = "Alesha Alesha";
//	char	name[] = "this is my name";
//
//	t_list	*elem;
//
//	elem = ft_lstnew(name);
//	printf("\nname : %s\ncontent : ",  (char *)elem->content);
//}
