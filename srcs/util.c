/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:56 by efischer          #+#    #+#             */
/*   Updated: 2019/05/29 15:40:47 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_free_content(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel((char**)&content);
}

void		ft_free_dir_info(void *content, size_t content_size)
{
	if (content_size != 0)
	{
		ft_strdel(&((t_dir*)(content))->name);
		ft_strdel(&((t_dir*)(content))->size);
		ft_strdel(&((t_dir*)(content))->uid);
		ft_strdel(&((t_dir*)(content))->gid);
		ft_strdel(&((t_dir*)(content))->link);
		ft_strdel(&((t_dir*)(content))->major);
		ft_strdel(&((t_dir*)(content))->minor);
//		free(content);
	}
}

void		ft_print_dir_info(t_dir *dir, t_padding *padding, uint8_t flags)
{
	if ((flags & FLAG_A) != FLAG_A && dir->name[0] == '.'
		&& ft_strchr(dir->name, '/') == NULL)
		return ;
	if ((flags & FLAG_L) == FLAG_L && ((dir->type == 'c' || dir->type == 'b')))
		ft_printf("%c%s %*s %-*s %-*s%*s,%*s %s %s\n", dir->type, dir->mode,
		padding->link, dir->link, padding->uid, dir->uid, padding->gid,
		dir->gid, padding->major, dir->major, padding->minor, dir->minor,
		dir->time, dir->name);
	else if ((flags & FLAG_L) == FLAG_L)
		ft_printf("%c%s %*s %-*s %-*s%*s %s %s\n", dir->type, dir->mode,
		padding->link, dir->link, padding->uid, dir->uid, padding->gid,
		dir->gid, padding->size, dir->size, dir->time, dir->name);
	else
		ft_printf("%-*s", padding->name, dir->name);
}

void		ft_printlist(t_list *lst, t_padding *padding, uint8_t flags, int print)
{
	if (lst == NULL || lst->content == NULL)
		ft_printf("total %d\n", padding->total);
	else if ((flags & FLAG_L) == FLAG_L && print == PRINT_TOTAL)
		ft_printf("total %d\n", padding->total);
	while (lst != NULL && lst->content != NULL)
	{
		ft_print_dir_info(((t_dir*)(lst->content)), padding, flags);
		lst = lst->next;
	}
	if ((flags & FLAG_L) != FLAG_L)
		ft_putchar('\n');
}
