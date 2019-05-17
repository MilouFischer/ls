/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dir_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:11:28 by efischer          #+#    #+#             */
/*   Updated: 2019/05/17 14:51:49 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
	while (tab[2][j] != '\0')
		dir_info->time[i++] = tab[2][j++];
	dir_info->time[i++] = ' ';
	j = 0;
	while (i < 12)
		dir_info->time[i++] = tab[3][j++];
	dir_info->time[i] = '\0';
}


static void		ft_get_mode(int nb_mode, t_dir *dir_info)
{
	static const char	*mode_tab[] = { "---", "--x", "-w-", "-wx", "r--", "r-x", "rw-", "rwx"};

	nb_mode = ft_atoi(ft_itoa_base(nb_mode, 8));
	dir_info->mode = ft_asprintf("%s%s%s", mode_tab[nb_mode / 100 % 10],
	mode_tab[nb_mode / 10 % 10], mode_tab[nb_mode % 10]);
}

static void		ft_get_type(int nb_mode, t_dir *dir_info)
{
	int			octal_mode;

	octal_mode = ft_atoi(ft_itoa_base(nb_mode, 8));
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

void		ft_get_dir_info(char *path, char *name, t_dir *dir_info)
{
	struct stat		buf;
	struct passwd	usr;
	struct group	grp;
	char			*tmp;

	tmp = ft_asprintf("%s/%s", path, name);
	if ((stat(tmp, &buf)) != -1)
	{
		usr = *getpwuid(buf.st_uid);
		grp = *getgrgid(buf.st_gid);
		dir_info->name = ft_strdup(name);
		ft_get_type(buf.st_mode, dir_info);
		ft_get_mode(buf.st_mode, dir_info);
		dir_info->link = buf.st_nlink;
		dir_info->uid = ft_strdup(usr.pw_name);
		dir_info->gid = ft_strdup(grp.gr_name);
		dir_info->size = buf.st_size;
		ft_get_time(ctime(&buf.st_ctime), dir_info);
	}
	else
		perror("stat");
	ft_strdel(&tmp);
}
