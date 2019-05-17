/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:03:44 by efischer          #+#    #+#             */
/*   Updated: 2019/05/14 17:13:59 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_str(char const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content_size = 0;
	list->next = NULL;
	if (content == NULL)
		list->content = NULL;
	else
	{
		if (!(list->content = ft_strdup(content)))
		{
			free(list);
			list = NULL;
		}
		else
			list->content_size = content_size;
	}
	return (list);
}
