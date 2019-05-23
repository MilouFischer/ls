/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:22 by efischer          #+#    #+#             */
/*   Updated: 2019/05/22 11:28:07 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_get_padding(char *str, size_t *data)
{
	size_t	len;

	len = ft_strlen(str);
	if (*data == 0 || len > *data - 1)
		*data = len + 1;
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

void			ft_get_dir_info(char *path, char *name, t_dir *dir_info,
				t_padding *padding)
{
	struct stat		buf;
	struct passwd	usr;
	struct group	grp;

	if ((lstat(path, &buf)) != -1)
	{
		usr = *getpwuid(buf.st_uid);
		grp = *getgrgid(buf.st_gid);
		ft_get_padding((dir_info->name = ft_strdup(name)), &padding->name);
		ft_get_type(buf.st_mode, dir_info);
		ft_get_mode(buf.st_mode, dir_info);
		ft_get_padding((dir_info->link = ft_itoa(buf.st_nlink)),
		&padding->link);
		ft_get_padding((dir_info->uid = ft_strdup(usr.pw_name)), &padding->uid);
		ft_get_padding((dir_info->gid = ft_strdup(grp.gr_name)), &padding->gid);
		ft_get_padding((dir_info->size = ft_itoa(buf.st_size)), &padding->size);
		padding->total += buf.st_blocks;
		dir_info->brut_time = buf.st_mtime;
		ft_get_time(ctime(&buf.st_mtime), dir_info);
	}
	else
		perror("stat");
	ft_strdel(&path);
}
