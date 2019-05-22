/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:46 by efischer          #+#    #+#             */
/*   Updated: 2019/05/22 13:24:29 by efischer         ###   ########.fr       */
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

void		ft_sort_name_av(t_list **lst1, t_list **lst2, t_list **head)
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
