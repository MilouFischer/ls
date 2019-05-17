/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:25:57 by efischer          #+#    #+#             */
/*   Updated: 2019/05/15 18:38:25 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_dir_info(t_dir dir)
{
	ft_printf("%s%s %d %s %s %d %s %s\n", dir.type, dir.mode, dir.link,
	dir.uid, dir.gid, dir.size, dir.time, dir.name);
}

static void		ft_open_dir(char *path)
{
	void			*dir;
	struct dirent	*dirent;
	t_dir			dir_info;

	ft_bzero(&dir_info, sizeof(dir_info));
	dir = opendir(path);
	if (dir == NULL)
		return ;
	while ((dirent = readdir(dir)) != NULL)
	{
		ft_get_dir_info(path, dirent->d_name, &dir_info);
		ft_print_dir_info(dir_info);
		if (*(dir_info.type) == 'd' && ft_strequ(dirent->d_name, ".") == 0
		&& ft_strequ(dirent->d_name, "..") == 0)
			ft_open_dir(ft_asprintf("%s%s", path, dirent->d_name));
	}
}

int		main(int ac, char **av)
{
	char	*path;

	if (ac == 1)
		path = ".";
	else
		path = ft_strdup(av[1]);
	if (path[ft_strlen(path) - 1] != '/')
		path = ft_join_free(path, "/", 1);
	ft_open_dir(path);
	return (0);
}
