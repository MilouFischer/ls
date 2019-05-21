/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:56 by efischer          #+#    #+#             */
/*   Updated: 2019/05/21 17:22:53 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_free_dir_info(t_dir *dir_info)
{
	ft_strdel(&dir_info->name);
	ft_strdel(&dir_info->link);
	ft_strdel(&dir_info->uid);
	ft_strdel(&dir_info->gid);
	ft_strdel(&dir_info->size);
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
	if ((flags & FLAG_A) != FLAG_A && dir->name[0] == '.')
		return ;
	if ((flags & FLAG_L) == FLAG_L)
		ft_printf("%c%s %*s %*s %*s %*s %s %-*s\n", dir->type, dir->mode,
		padding->link, dir->link, padding->uid, dir->uid, padding->gid, dir->gid,
		padding->size, dir->size, dir->time, padding->name, dir->name);
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
}
