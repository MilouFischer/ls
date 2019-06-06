/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:29:36 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 15:29:37 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void		ft_sort(t_list **lst, uint16_t flags)
{
	if ((flags & FLAG_F))
		return ;
	ft_merge_sort(lst, &ft_sort_name);
	if ((flags & FLAG_T) == FLAG_T)
		ft_merge_sort(lst, &ft_sort_time);
	if ((flags & FLAG_REV) == FLAG_REV)
		ft_merge_sort(lst, &ft_sort_rev);
}
