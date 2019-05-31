/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:22 by efischer          #+#    #+#             */
/*   Updated: 2019/05/31 16:28:26 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_format_s_link(t_dir *dir_info, uint8_t flags)
{
	char			buf[PATH_MAX - 1];
	ssize_t			ret;

	if (dir_info->type == 'l' && (flags & FLAG_L) == FLAG_L)
	{
		if ((ret = readlink(dir_info->path, buf, PATH_MAX)) > 0)
		{
			buf[ret] = '\0';
			dir_info->name = ft_join_free(dir_info->name,
			ft_asprintf(" -> %s", buf), 3);
		}
		else
			perror(dir_info->path);
	}
}

static void		ft_max_padding(char *str, size_t *data)
{
	size_t	len;

	len = ft_strlen(str);
	if (*data == 0 || len > *data - 1)
		*data = len + 1;
}

static void		ft_get_padding(t_padding *padding, t_dir *dir_info,
				size_t nb_blocks)
{
	ft_max_padding(dir_info->name, &padding->name);
	ft_max_padding(dir_info->link, &padding->link);
	ft_max_padding(dir_info->uid, &padding->uid);
	ft_max_padding(dir_info->gid, &padding->gid);
	ft_max_padding(dir_info->size, &padding->size);
	ft_max_padding(dir_info->major, &padding->major);
	ft_max_padding(dir_info->minor, &padding->minor);
	padding->total += nb_blocks;
	if (padding->major != 0 || padding->minor != 0)
	{
		if (padding->size < padding->major + padding->minor + 1)
			padding->size = padding->major + padding->minor + 1;
		else
			padding->major += padding->size -
			(padding->major + padding->minor + 1);
	}
}

void			ft_get_dir_info(char *path, char *name, t_dir *dir_info,
				t_padding *padding)
{
	struct stat		stat;
	struct passwd	usr;
	struct group	grp;

	if ((lstat(path, &stat)) != -1)
	{
		usr = *getpwuid(stat.st_uid);
		grp = *getgrgid(stat.st_gid);
		dir_info->name = ft_strdup(name);
		dir_info->path = path;
		dir_info->nb_mode = stat.st_mode;
		ft_get_type(stat.st_mode, dir_info);
		ft_get_mode(stat.st_mode, dir_info);
		dir_info->link = ft_itoa(stat.st_nlink);
		dir_info->uid = ft_strdup(usr.pw_name);
		dir_info->gid = ft_strdup(grp.gr_name);
		dir_info->size = ft_itoa(stat.st_size);
		dir_info->brut_time = stat.st_mtime;
		ft_get_time(ctime(&stat.st_mtime), dir_info);
		dir_info->major = ft_itoa(major(stat.st_rdev));
		dir_info->minor = ft_itoa(minor(stat.st_rdev));
		ft_get_padding(padding, dir_info, stat.st_blocks);
	}
}
