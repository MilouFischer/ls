/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:25:57 by efischer          #+#    #+#             */
/*   Updated: 2019/05/18 18:17:23 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_open_dir(char *path);

static void		ft_free_dir_info(t_dir *dir_info)
{
	ft_strdel(&dir_info->name);
	ft_strdel(&dir_info->mode);
	ft_strdel(&dir_info->link);
	ft_strdel(&dir_info->uid);
	ft_strdel(&dir_info->gid);
	ft_strdel(&dir_info->size);
}

static void		ft_free_lst(t_list **lst)
{
	if (*lst == NULL)
		return ;
	ft_free_lst(&(*lst)->next);
	ft_free_dir_info(((t_dir*)((*lst)->content)));
	free((*lst)->content);
	free(*lst);
	*lst = NULL;
}

static void		ft_print_dir_info(t_dir *dir, t_padding *padding)
{
	ft_printf("%c%s %*s %*s %*s %*s %s %-*s\n", dir->type, dir->mode,
	padding->link, dir->link, padding->uid, dir->uid, padding->gid, dir->gid,
	padding->size, dir->size, dir->time, padding->name, dir->name);
}

static void		ft_printlist(t_list *lst, t_padding *padding)
{
	while (lst != NULL && lst->content != NULL)
	{
		ft_print_dir_info(((t_dir*)(lst->content)), padding);
		lst = lst->next;
	}
}

static void		ft_find_next_dir(char *path, t_list *lst)
{
	char			*tmp;

	while (lst != NULL)
	{
		if (((t_dir*)(lst->content))->type == 'd'
		&& ft_strequ(((t_dir*)(lst->content))->name, ".") == 0
		&& ft_strequ(((t_dir*)(lst->content))->name, "..") == 0)
		{
			ft_putchar('\n');
			tmp = ft_asprintf("%s%s", path, ((t_dir*)(lst->content))->name);
			ft_printf("%s:\n", tmp);
			ft_strdel(&tmp);
			ft_open_dir((ft_asprintf("%s%s/", path, ((t_dir*)(lst->content))->name)));
		}
		lst = lst->next;
	}
}

static void		ft_open_dir(char *path)
{
	void			*dir;
	struct dirent	*dirent;
	t_dir			dir_info;
	t_padding		padding;
	t_list			*lst;

	lst = NULL;
	dir = opendir(path);
	ft_bzero(&padding, sizeof(padding));
	while ((dirent = readdir(dir)) != NULL)
	{
		ft_bzero(&dir_info, sizeof(dir_info));
		ft_get_dir_info(path, dirent->d_name, &dir_info, &padding);
		ft_lstadd(&lst, ft_lstnew(&dir_info, sizeof(t_dir)));
	}
	ft_merge_sort(&lst);
	ft_printlist(lst, &padding);
	ft_find_next_dir(path, lst);
	ft_strdel(&path);
	ft_free_lst(&lst);
}

int		main(int ac, char **av)
{
	char	*path;

	if (ac == 1)
		path = ft_strdup(".");
	else
		path = ft_strdup(av[1]);
	if (opendir(path) == NULL)
	{
		if (errno != ENOTDIR)
			perror(ft_asprintf("ft_ls: file not found '%s'", path));
		else
			ft_putendl(path);
		return (0);
	}
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_join_free(path, "/", 1);
	ft_open_dir(path);
	return (0);
}
