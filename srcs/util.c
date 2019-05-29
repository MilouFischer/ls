/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:56 by efischer          #+#    #+#             */
/*   Updated: 2019/05/29 18:14:36 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_free_content(void *content, size_t content_size)
{
	(void)content_size;
	ft_strdel((char**)&content);
}

void		ft_free_dir_info(t_dir *dir)
{
	if (dir != NULL)
	{
		ft_strdel(&dir->name);
		ft_strdel(&dir->size);
		ft_strdel(&dir->uid);
		ft_strdel(&dir->gid);
		ft_strdel(&dir->link);
		ft_strdel(&dir->major);
		ft_strdel(&dir->minor);
		ft_strdel(&dir->path);
	}
}

void		ft_free_struct_list(void *content, size_t content_size)
{
	(void)content_size;
	ft_free_dir_info(((t_dir*)(content)));
	free(content);
	content = NULL;
}

void		ft_print_color(t_dir *dir, t_padding *padding, uint8_t flags)
{
	if (dir->type == 'b')
		ft_printf("\033[46;34m%s\033[0m", dir->name);
	else if (dir->type == 'c')
		ft_printf("\033[43;34m%s\033[0m", dir->name);
	else if (dir->type == 'd')
		ft_printf("\033[1;36m%s\033[0m", dir->name);
	else if (dir->type == 'l')
		ft_printf("\033[35m%s\033[0m", dir->name);
	else if (dir->type == 'p')
		ft_printf("\033[43m%s\033[0m", dir->name);
	else if (dir->type == 's')
		ft_printf("\033[1;35m%s\033[0m", dir->name);
	else if ((dir->nb_mode & USR_X) == USR_X || (dir->nb_mode & GRP_X) == GRP_X
	|| (dir->nb_mode & OTH_X) == OTH_X)
		ft_printf("\033[31m%s\033[0m", dir->name);
	else
		ft_printf("%s", dir->name);
	if ((flags & FLAG_L) != FLAG_L)
		ft_printf("%*s", padding->name - ft_strlen(dir->name), " ");
	else
		ft_putchar('\n');
}

void		ft_print_dir_info(t_dir *dir, t_padding *padding, uint8_t flags)
{
	ft_format_s_link(dir, flags);
	if ((flags & FLAG_A) != FLAG_A && dir->name[0] == '.'
		&& ft_strchr(dir->name, '/') == NULL)
		return ;
	if ((flags & FLAG_L) == FLAG_L && ((dir->type == 'c' || dir->type == 'b')))
		ft_printf("%c%s %*s %-*s %-*s%*s,%*s %s ", dir->type, dir->mode,
		padding->link, dir->link, padding->uid, dir->uid, padding->gid,
		dir->gid, padding->major, dir->major, padding->minor, dir->minor,
		dir->time);
	else if ((flags & FLAG_L) == FLAG_L)
		ft_printf("%c%s %*s %-*s %-*s%*s %s ", dir->type, dir->mode,
		padding->link, dir->link, padding->uid, dir->uid, padding->gid,
		dir->gid, padding->size, dir->size, dir->time);
	if ((flags & FLAG_G) == FLAG_G)
		ft_print_color(dir, padding, flags);
	else
		ft_printf("%-*s", padding->name, dir->name);
}

void		ft_printlist(t_list *lst, t_padding *padding, uint8_t flags,
			int print)
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
