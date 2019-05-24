/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:56 by efischer          #+#    #+#             */
/*   Updated: 2019/05/24 16:09:57 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_free_dir_info(t_list *lst)
{
	while (lst != NULL)
	{
		ft_strdel(&((t_dir*)(lst->content))->name);
		ft_strdel(&((t_dir*)(lst->content))->link);
		ft_strdel(&((t_dir*)(lst->content))->uid);
		ft_strdel(&((t_dir*)(lst->content))->gid);
		ft_strdel(&((t_dir*)(lst->content))->size);
		lst = lst->next;
	}
}

void		ft_free_lst(t_list **lst)
{
	if (*lst == NULL)
		return ;
	ft_free_lst(&(*lst)->next);
	free((*lst)->content);
	free(*lst);
	*lst = NULL;
}

void		ft_print_dir_info(t_dir *dir, t_padding *padding, uint8_t flags)
{
	if ((flags & FLAG_A) != FLAG_A && dir->name[0] == '.'
		&& ft_strchr(dir->name, '/') == NULL)
		return ;
	if ((flags & FLAG_L) == FLAG_L)
		ft_printf("%c%s %*s %-*s %-*s%*s %s %s\n", dir->type, dir->mode,
		padding->link, dir->link, padding->uid, dir->uid, padding->gid,
		dir->gid, padding->size, dir->size, dir->time, dir->name);
	else
		ft_printf("%-*s", padding->name, dir->name);
}

void		ft_printlist(t_list *lst, t_padding *padding, uint8_t flags)
{
	while (lst != NULL && lst->content != NULL)
	{
		ft_print_dir_info(((t_dir*)(lst->content)), padding, flags);
		lst = lst->next;
	}
	if ((flags & FLAG_L) != FLAG_L)
		ft_putchar('\n');
}
