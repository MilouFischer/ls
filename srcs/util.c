/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:56 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 13:37:18 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_free_dir_info(t_dir *dir)
{
	if (dir != NULL)
	{
		ft_strdel(&dir->name);
		ft_strdel(&dir->path);
		ft_strdel(&dir->size);
		ft_strdel(&dir->link);
		ft_strdel(&dir->major);
		ft_strdel(&dir->minor);
		ft_strdel(&dir->uid);
		ft_strdel(&dir->gid);
	}
}

void		ft_free_struct_list(void *content, size_t content_size)
{
	(void)content_size;
	ft_free_dir_info(((t_dir*)(content)));
	free(content);
}

void		ft_print_color(t_dir *dir, t_padding *padding, uint16_t flags)
{
	char	*tmp;

	tmp = ft_strdup(dir->name);
	if (dir->type == 'b')
		tmp = ft_join_free("\033[46;34m", tmp, 2);
	else if (dir->type == 'c')
		tmp = ft_join_free("\033[43;34m", tmp, 2);
	else if (dir->type == 'd')
		tmp = ft_join_free("\033[1;36m", tmp, 2);
	else if (dir->type == 'l')
		tmp = ft_join_free("\033[35m", tmp, 2);
	else if (dir->type == 'p')
		tmp = ft_join_free("\033[43m", tmp, 2);
	else if (dir->type == 's')
		tmp = ft_join_free("\033[1;35m", tmp, 2);
	else if ((dir->nb_mode & USR_X) == USR_X || (dir->nb_mode & GRP_X) == GRP_X
			|| (dir->nb_mode & OTH_X) == OTH_X)
		tmp = ft_join_free("\033[31m", tmp, 2);
	tmp = ft_join_free(tmp, "\033[0m", 1);
	ft_putstr(tmp);
	if ((flags & FLAG_L) == FALSE && (flags & FLAG_1) == FALSE)
		ft_printf("%*s", padding->name - ft_strlen(dir->name), " ");
	ft_strdel(&tmp);
}

void		ft_print_dir_info(t_dir *dir, t_padding *padding, uint16_t flags)
{
	if ((flags & FLAG_A) == FALSE && dir->name[0] == '.'
		&& ft_strchr(dir->name, '/') == NULL)
		return ;
	if (dir->type == 'c' || dir->type == 'b')
	{
		ft_printf("%c%s %*s %-*s %-*s%*s,%*s %s ", dir->type, dir->mode,
		padding->link, dir->link, padding->uid, dir->uid, padding->gid,
		dir->gid, padding->major, dir->major, padding->minor, dir->minor,
		dir->time);
	}
	else
	{
		ft_printf("%c%s %*s %-*s %-*s%*s %s ", dir->type, dir->mode,
		padding->link, dir->link, padding->uid, dir->uid,	padding->gid,
		dir->gid, padding->size, dir->size, dir->time);
	}
	if (flags & FLAG_G)
		ft_print_color(dir, padding, flags);
	else
		ft_putstr(dir->name);
	if (dir->type == 'l' && (flags & FLAG_L))
		ft_format_s_link(dir);
}

static void	ft_printendl(t_list *lst, t_padding *padding, uint16_t flags)
{
	while (lst != NULL)
	{
		if ((flags & FLAG_G) == FLAG_G)
			ft_print_color(((t_dir*)(lst->content)), padding, flags);
		else
			ft_putendl(((t_dir*)(lst->content))->name);
		lst = lst->next;
	}
}

void		ft_printlist(t_list *lst, t_padding *padding, uint16_t flags,
			int print)
{
	struct winsize	winsize;
	
	if (lst == NULL || lst->content == NULL)
		ft_printf("total %d\n", padding->total);
	else if ((flags & FLAG_L) == FLAG_L && print == PRINT_TOTAL)
		ft_printf("total %d\n", padding->total);
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &winsize) == FAILURE)
		padding->ws_col = 0;
	else
		padding->ws_col = winsize.ws_col;
	if ((flags & FLAG_L) == FLAG_L)
		while (lst != NULL && lst->content != NULL)
		{
			ft_print_dir_info(((t_dir*)(lst->content)), padding, flags);
			ft_putchar('\n');
			lst = lst->next;
		}
	else if ((flags & FLAG_1) == FLAG_1 || padding->ws_col == 0)
		ft_printendl(lst, padding, flags);
	else
		ft_column_display(lst, padding, flags);
}
