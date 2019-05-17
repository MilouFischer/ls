/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:04:54 by efischer          #+#    #+#             */
/*   Updated: 2019/05/13 16:48:31 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstprint(t_list *lst)
{
	void	*str;
	void	*tmp;
	size_t	len;

	if (!lst)
		return (0);
	if (!(str = (void*)malloc(sizeof(char) * (lst->content_size + 1))))
		return (0);
	str = ft_memcpy(str, lst->content, lst->content_size);
	len = lst->content_size;
	lst = lst->next;
	while (lst)
	{
		tmp = str;
		str = ft_memjoin(tmp, lst->content, len, lst->content_size);
		free(tmp);
		len += lst->content_size;
		lst = lst->next;
	}
	write(1, str, len);
	free(str);
	return (len);
}
