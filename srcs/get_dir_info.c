/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:22 by efischer          #+#    #+#             */
/*   Updated: 2019/05/29 15:21:46 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_compute_padding(char *str, size_t *data)
{
	size_t	len;

	len = ft_strlen(str);
	if (*data == 0 || len > *data - 1)
		*data = len + 1;
}

static void		ft_time_or_year(char **tab, size_t i, t_dir *dir_info)
{
	size_t	j;

	j = 0;
	if (time(NULL) - dir_info->brut_time < SIX_MONTHS)
	{
		while (i < 12)
			dir_info->time[i++] = tab[3][j++];
		dir_info->time[i] = '\0';
	}
	else
	{
		dir_info->time[i++] = ' ';
		while (i < 12)
			dir_info->time[i++] = tab[4][j++];
		dir_info->time[i] = '\0';
	}
}

static void		ft_get_time(const char *brut_tm, t_dir *dir_info)
{
	char	**tab;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tab = ft_strsplit(brut_tm, ' ');
	while (tab[1][j] != '\0')
		dir_info->time[i++] = tab[1][j++];
	dir_info->time[i++] = ' ';
	j = 0;
	if (ft_strlen(tab[2]) == 1)
		dir_info->time[i++] = ' ';
	while (tab[2][j] != '\0')
		dir_info->time[i++] = tab[2][j++];
	dir_info->time[i++] = ' ';
	ft_time_or_year(tab, i, dir_info);
	ft_free_tab(tab);
}

static void		ft_get_mode_x(int nb_mode, t_dir *dir_info)
{
	if ((nb_mode & OTH_X) == OTH_X)
		dir_info->mode[8] = 'x';
	if ((nb_mode & OTH_X) == OTH_X && (nb_mode & STICKY_BIT) == STICKY_BIT)
		dir_info->mode[8] = 't';
	if ((nb_mode & OTH_X) != OTH_X && (nb_mode & STICKY_BIT) == STICKY_BIT)
		dir_info->mode[8] = 'T';
	if ((nb_mode & GRP_X) == GRP_X)
		dir_info->mode[5] = 'x';
	if ((nb_mode & GRP_X) == GRP_X && ((nb_mode & SET_UID) == SET_UID
		|| (nb_mode & SET_GID) == SET_GID))
		dir_info->mode[5] = 's';
	if ((nb_mode & GRP_X) != GRP_X && ((nb_mode & SET_UID) == SET_UID
		|| (nb_mode & SET_GID) == SET_GID))
		dir_info->mode[5] = 'S';
	if ((nb_mode & USR_X) == USR_X)
		dir_info->mode[2] = 'x';
	if ((nb_mode & USR_X) == USR_X && ((nb_mode & SET_UID) == SET_UID
		|| (nb_mode & SET_GID) == SET_GID))
		dir_info->mode[2] = 's';
	if ((nb_mode & USR_X) != USR_X && ((nb_mode & SET_UID) == SET_UID
		|| (nb_mode & SET_GID) == SET_GID))
		dir_info->mode[2] = 'S';
}

static void		ft_get_mode(int nb_mode, t_dir *dir_info)
{
	ft_memset(dir_info->mode, '-', 10);
	dir_info->mode[9] = '\0';
	ft_get_mode_x(nb_mode, dir_info);
	if ((nb_mode & OTH_W) == OTH_W)
		dir_info->mode[7] = 'w';
	if ((nb_mode & OTH_R) == OTH_R)
		dir_info->mode[6] = 'r';
	if ((nb_mode & GRP_W) == GRP_W)
		dir_info->mode[4] = 'w';
	if ((nb_mode & GRP_R) == GRP_R)
		dir_info->mode[3] = 'r';
	if ((nb_mode & USR_W) == USR_W)
		dir_info->mode[1] = 'w';
	if ((nb_mode & USR_R) == USR_R)
		dir_info->mode[0] = 'r';
}

static void		ft_get_type(int nb_mode, t_dir *dir_info)
{
	nb_mode >>= 12;
	if ((nb_mode & TYPE_S) == TYPE_S)
		dir_info->type = 's';
	else if ((nb_mode & TYPE_L) == TYPE_L)
		dir_info->type = 'l';
	else if ((nb_mode & TYPE_F) == TYPE_F)
		dir_info->type = '-';
	else if ((nb_mode & TYPE_B) == TYPE_B)
		dir_info->type = 'b';
	else if ((nb_mode & TYPE_D) == TYPE_D)
		dir_info->type = 'd';
	else if ((nb_mode & TYPE_C) == TYPE_C)
		dir_info->type = 'c';
	else if ((nb_mode & TYPE_P) == TYPE_P)
		dir_info->type = 'p';
	else
		dir_info->type = ' ';
}

static void		ft_format_s_link(char *path, t_dir *dir_info)
{
	char			buf[PATH_MAX - 1];
	ssize_t			ret;

	if (dir_info->type == 'l')
	{
		if ((ret = readlink(path, buf, PATH_MAX)) > 0)
		{
			buf[ret] = '\0';
			dir_info->name = ft_join_free(dir_info->name,
			ft_asprintf(" -> %s", buf), 3);
		}
		else
			perror(path);
	}
}

static void		ft_get_padding(t_padding *padding, t_dir *dir_info,
				size_t nb_blocks)
{
	ft_compute_padding(dir_info->name, &padding->name);
	ft_compute_padding(dir_info->link, &padding->link);
	ft_compute_padding(dir_info->uid, &padding->uid);
	ft_compute_padding(dir_info->gid, &padding->gid);
	ft_compute_padding(dir_info->size, &padding->size);
	ft_compute_padding(dir_info->major, &padding->major);
	ft_compute_padding(dir_info->minor, &padding->minor);
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
		ft_format_s_link(path, dir_info);
	}
	ft_strdel(&path);
}
