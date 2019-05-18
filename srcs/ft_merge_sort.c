/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:00:02 by efischer          #+#    #+#             */
/*   Updated: 2019/05/18 17:10:28 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_share_lst(t_list **lst)
{
	t_list	*find_last_link;

	find_last_link = *lst;
	while (find_last_link->next != NULL)
	{
		find_last_link = find_last_link->next;
		if (find_last_link->next != NULL)
		{
			*lst = (*lst)->next;
			find_last_link = find_last_link->next;
		}
	}
}

void		ft_add_link(t_list **lst1, t_list **lst2, t_list **head)
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

t_list		*ft_merge_list(t_list *lst1, t_list *lst2)
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	ft_add_link(&lst1, &lst2, &head);
	tmp = head;
	while (lst1 != NULL && lst2 != NULL)
	{
		ft_add_link(&lst1, &lst2, &tmp->next);
		tmp = tmp->next;
	}
	while (lst1 != NULL)
	{
		tmp->next = lst1;
		lst1 = lst1->next;
		tmp = tmp->next;
	}
	while (lst2 != NULL)
	{
		tmp->next = lst2;
		lst2 = lst2->next;
		tmp = tmp->next;
	}
	return (head);
}

void		ft_merge_sort(t_list **lst)
{
	t_list	*lst1;
	t_list	*lst2;

	if (lst == NULL || (*lst)->next == NULL)
		return ;
	lst1 = *lst;
	ft_share_lst(lst);
	lst2 = (*lst)->next;
	(*lst)->next = NULL;
	ft_merge_sort(&lst1);
	ft_merge_sort(&lst2);
	*lst = ft_merge_list(lst1, lst2);
}
