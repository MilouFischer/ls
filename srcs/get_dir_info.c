/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:29:21 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 18:25:30 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_dir_info.h"

void			ft_format_s_link(t_dir *dir_info)
{
	char			buf[PATH_MAX];
	ssize_t			ret;

	if ((ret = readlink(dir_info->path, buf, PATH_MAX)) == FAILURE)
		perror("readlink");
	else
	{
		buf[ret] = '\0';
		ft_printf(" -> %s", buf);
	}
}

static void		ft_max_padding(char *str, size_t *data)
{
	size_t	len;

	len = ft_strlen(str);
	if (*data == 0 || len > *data - 1)
		*data = len + 1;
}

void			ft_get_padding(t_padding *padding, t_dir *dir_info)
{
	ft_max_padding(dir_info->name, &padding->name);
	ft_max_padding(dir_info->link, &padding->link);
	ft_max_padding(dir_info->uid, &padding->uid);
	ft_max_padding(dir_info->gid, &padding->gid);
	ft_max_padding(dir_info->size, &padding->size);
	ft_max_padding(dir_info->major, &padding->major);
	ft_max_padding(dir_info->minor, &padding->minor);
	padding->total += dir_info->nb_blocks;
	if (padding->major != 0 || padding->minor != 0)
	{
		if (padding->size < padding->major + padding->minor + 1)
			padding->size = padding->major + padding->minor + 1;
		else
		{
			padding->major += padding->size
				- (padding->major + padding->minor + 1);
		}
	}
}

void			ft_get_main_info(t_dir *dir_info, char *name, char *path, struct stat stat)
{
	dir_info->name = ft_strdup(name);
	dir_info->path = path;
	dir_info->nb_mode = stat.st_mode;
	ft_get_type(stat.st_mode, dir_info);
	ft_get_mode(stat.st_mode, dir_info);
	dir_info->brut_time = stat.st_mtime;
	ft_get_time(ctime(&stat.st_mtime), dir_info);
	dir_info->nb_blocks = stat.st_blocks;
}

void			ft_get_other_info(t_dir *dir_info, struct stat stat)
{
	struct passwd	*usr;
	struct group	*grp;

	usr = getpwuid(stat.st_uid);
	grp = getgrgid(stat.st_gid);
	dir_info->size = ft_itoa(stat.st_size);
	dir_info->major = ft_itoa(major(stat.st_rdev));
	dir_info->minor = ft_itoa(minor(stat.st_rdev));
	dir_info->link = ft_itoa(stat.st_nlink);
	if (usr != NULL)
		dir_info->uid = ft_strdup(usr->pw_name);
	else
		dir_info->uid = ft_itoa(stat.st_uid);
	if (grp != NULL)
		dir_info->gid = ft_strdup(grp->gr_name);
	else
		dir_info->gid = ft_itoa(stat.st_gid);
}

int				ft_get_dir_info(char *path, char *name, t_dir *dir_info,
				uint16_t flags)
{
	struct stat		stat;
	char			*tmp;

	if (ft_strequ(path, "/") == TRUE)
		path = ft_strjoin(path, name);
	else if (path != NULL)
		path = ft_asprintf("%s/%s", path, name);
	else
		path = ft_strdup(name);
	if ((lstat(path, &stat)) == FAILURE)
	{
		perror((tmp = ft_asprintf("ft_ls: %s", path)));
		ft_strdel(&tmp);
		ft_strdel(&path);
		return (FAILURE);
	}
	ft_get_main_info(dir_info, name, path, stat);
	if (flags & FLAG_L)
		ft_get_other_info(dir_info, stat);
	return (SUCCESS);
}
