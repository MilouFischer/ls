/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:56 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 14:22:28 by efischer         ###   ########.fr       */
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

char		*ft_print_color(t_dir *dir, t_padding *padding, uint16_t flags)
{
	char	*out;

	out = ft_strdup(dir->name);
	if (dir->type == 'b')
		out = ft_join_free("\033[46;34m", out, 2);
	else if (dir->type == 'c')
		out = ft_join_free("\033[43;34m", out, 2);
	else if (dir->type == 'd')
		out = ft_join_free("\033[1;36m", out, 2);
	else if (dir->type == 'l')
		out = ft_join_free("\033[35m", out, 2);
	else if (dir->type == 'p')
		out = ft_join_free("\033[43m", out, 2);
	else if (dir->type == 's')
		out = ft_join_free("\033[1;35m", out, 2);
	else if ((dir->nb_mode & USR_X) == USR_X || (dir->nb_mode & GRP_X) == GRP_X
			|| (dir->nb_mode & OTH_X) == OTH_X)
		out = ft_join_free("\033[31m", out, 2);
	out = ft_join_free(out, "\033[0m", 1);
	if ((flags & FLAG_L) == FALSE && (flags & FLAG_1) == FALSE)
		out = ft_join_free(out, ft_asprintf("%*s", padding->name - ft_strlen(dir->name), " "), 3);
	return (out);
}

void		ft_print_dir_info(t_dir *dir, t_padding *padding, uint16_t flags)
{
	char	*out;

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
	{
		out = ft_print_color(dir, padding, flags);
		ft_putstr(out);
		ft_strdel(&out);
	}
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
