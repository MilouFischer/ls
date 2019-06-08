/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:29:36 by efischer          #+#    #+#             */
/*   Updated: 2019/06/08 15:07:01 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_list.h"

void		ft_sort_rev(t_list **lst1, t_list **lst2, t_list **head)
{
	(void)lst1;
	*head = *lst2;
	*lst2 = (*lst2)->next;
}

void		ft_sort_time(t_list **lst1, t_list **lst2, t_list **head)
{
	if (((t_dir*)((*lst1)->content))->brut_time <
	((t_dir*)((*lst2)->content))->brut_time)
	{
		*head = *lst2;
		*lst2 = (*lst2)->next;
	}
	else
	{
		*head = *lst1;
		*lst1 = (*lst1)->next;
	}
}

void		ft_sort_name(t_list **lst1, t_list **lst2, t_list **head)
{
	if (ft_strcmp(((t_dir*)((*lst1)->content))->name,
	((t_dir*)((*lst2)->content))->name) > 0)
	{
		*head = *lst2;
		*lst2 = (*lst2)->next;
	}
	else
	{
		*head = *lst1;
		*lst1 = (*lst1)->next;
	}
}

void		ft_sort_size(t_list **lst1, t_list **lst2, t_list **head)
{
	int		size_1;
	int		size_2;

	size_1 = ft_atoi(((t_dir*)((*lst1)->content))->size);
	size_2 = ft_atoi(((t_dir*)((*lst2)->content))->size);
	if (size_2 > size_1)
	{
		*head = *lst2;
		*lst2 = (*lst2)->next;
	}
	else
	{
		*head = *lst1;
		*lst1 = (*lst1)->next;
	}
}

void		ft_sort_input(t_list **lst1, t_list **lst2, t_list **head)
{
	if (ft_strcmp((*lst1)->content, (*lst2)->content) > 0)
	{
		*head = *lst2;
		*lst2 = (*lst2)->next;
	}
	else
	{
		*head = *lst1;
		*lst1 = (*lst1)->next;
	}
}
