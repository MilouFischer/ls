/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:19:22 by efischer          #+#    #+#             */
/*   Updated: 2019/05/21 17:19:24 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_get_padding(char *str, size_t *data)
{
	size_t	len;

	len = ft_strlen(str);
	if (*data == 0 || len > *data)
		*data = len;
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


static void		ft_get_mode(int nb_mode, t_dir *dir_info)
{
	ft_memset(dir_info->mode, '-', 10);
	dir_info->mode[9] = '\0';
	if ((nb_mode & OTH_X) == OTH_X)
		dir_info->mode[8] = 'x';
	if ((nb_mode & OTH_W) == OTH_W)
		dir_info->mode[7] = 'w';
	if ((nb_mode & OTH_R) == OTH_R)
		dir_info->mode[6] = 'r';
	if ((nb_mode & GRP_X) == GRP_X)
		dir_info->mode[5] = 'x';
	if ((nb_mode & GRP_W) == GRP_W)
		dir_info->mode[4] = 'w';
	if ((nb_mode & GRP_R) == GRP_R)
		dir_info->mode[3] = 'r';
	if ((nb_mode & USR_X) == USR_X)
		dir_info->mode[2] = 'x';
	if ((nb_mode & USR_W) == USR_W)
		dir_info->mode[1] = 'w';
	if ((nb_mode & USR_R) == USR_R)
		dir_info->mode[0] = 'r';
}

static void		ft_get_type(int nb_mode, t_dir *dir_info)
{
	int			octal_mode;
	char		*tmp;

	octal_mode = ft_atoi((tmp = ft_itoa_base(nb_mode, 8)));
	ft_strdel(&tmp);
	octal_mode /= 1000;
	if (octal_mode == 40)
		dir_info->type = 'd';
	else if (octal_mode == 100)
		dir_info->type = '-';
	else if (octal_mode == 120)
		dir_info->type = 'l';
	else
		dir_info->type = ' ';
}

void		ft_get_dir_info(char *path, char *name, t_dir *dir_info,
			t_padding *padding)
{
	struct stat		buf;
	struct passwd	usr;
	struct group	grp;

	if ((stat(path, &buf)) != -1)
	{
		usr = *getpwuid(buf.st_uid);
		grp = *getgrgid(buf.st_gid);
		ft_get_padding((dir_info->name = ft_strdup(name)), &padding->name);
		ft_get_type(buf.st_mode, dir_info);
		ft_get_mode(buf.st_mode, dir_info);
		ft_get_padding((dir_info->link = ft_itoa(buf.st_nlink)), &padding->link);
		ft_get_padding((dir_info->uid = ft_strdup(usr.pw_name)), &padding->uid);
		ft_get_padding((dir_info->gid = ft_strdup(grp.gr_name)), &padding->gid);
		ft_get_padding((dir_info->size = ft_itoa(buf.st_size)), &padding->size);
		dir_info->brut_time = buf.st_mtime;
		ft_get_time(ctime(&buf.st_mtime), dir_info);
	}
	else
		perror("stat");
	ft_strdel(&path);
}
