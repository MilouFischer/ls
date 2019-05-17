/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:25:57 by efischer          #+#    #+#             */
/*   Updated: 2019/05/17 14:51:48 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_dir_info(t_dir *dir)
{
	ft_printf("%c%s %d %s %s %d %s %s\n", dir->type, dir->mode, dir->link,
	dir->uid, dir->gid, dir->size, dir->time, dir->name);
}

static void		ft_printlist(t_list *lst)
{
	while (lst != NULL && lst->content != NULL)
	{
		ft_print_dir_info(((t_dir*)(lst->content)));
		lst = lst->next;
	}
}

static void		ft_open_dir(char *path)
{
	void			*dir;
	struct dirent	*dirent;
	t_dir			dir_info;
	t_list			*lst;
	char			*tmp;

	dir = opendir(path);
	lst = NULL;
	if (dir == NULL)
		return ;
	while ((dirent = readdir(dir)) != NULL)
	{
		ft_bzero(&dir_info, sizeof(dir_info));
		ft_get_dir_info(path, dirent->d_name, &dir_info);
		ft_lstadd(&lst, ft_lstnew(&dir_info, sizeof(t_dir)));
	}
	ft_printlist(lst);
	while (lst != NULL)
	{
		if (((t_dir*)(lst->content))->type == 'd' && ft_strequ(((t_dir*)(lst->content))->name, ".") == 0
		&& ft_strequ(((t_dir*)(lst->content))->name, "..") == 0)
		{
			ft_putchar('\n');
			tmp = ft_asprintf("%s%s", path, ((t_dir*)(lst->content))->name);
			ft_printf("%s:\n", tmp);
			ft_open_dir(ft_asprintf("%s%s", path, ((t_dir*)(lst->content))->name));
		}
		lst = lst->next;
	}
}

int		main(int ac, char **av)
{
	char	*path;

	if (ac == 1)
		path = ft_strdup(".");
	else
		path = ft_strdup(av[1]);
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_join_free(path, "/", 1);
	ft_open_dir(path);
	return (0);
}
