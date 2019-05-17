/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dir_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:11:28 by efischer          #+#    #+#             */
/*   Updated: 2019/05/15 18:07:07 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_get_time(const char *brut_tm, t_dir *dir_info)
{
	char	**tab;
	char	final_tm[13];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tab = ft_strsplit(brut_tm, ' ');
	while (tab[1][j] != '\0')
		final_tm[i++] = tab[1][j++];
	final_tm[i++] = ' ';
	j = 0;
	while (tab[2][j] != '\0')
		final_tm[i++] = tab[2][j++];
	final_tm[i++] = ' ';
	j = 0;
	while (i < 12)
		final_tm[i++] = tab[3][j++];
	final_tm[i] = '\0';
	dir_info->time = ft_strdup(final_tm);
}

static void		ft_init_mode_tab(const char *mode_tab[8])
{
	mode_tab[0] = "---";
	mode_tab[1] = "--x";
	mode_tab[2] = "-w-";
	mode_tab[3] = "-wx";
	mode_tab[4] = "r--";
	mode_tab[5] = "r-x";
	mode_tab[6] = "rw-";
	mode_tab[7] = "rwx";
}

static void		ft_get_mode(int nb_mode, t_dir *dir_info)
{
	int			octal_mode;
	const char	*mode_tab[8];

	ft_init_mode_tab(mode_tab);
	octal_mode = ft_atoi(ft_itoa_base(nb_mode, 8));
	dir_info->mode = ft_asprintf("%s%s%s", mode_tab[octal_mode / 100 % 10],
	mode_tab[octal_mode / 10 % 10], mode_tab[octal_mode % 10]);
}

static void		ft_get_type(int nb_mode, t_dir *dir_info)
{
	int			octal_mode;

	octal_mode = ft_atoi(ft_itoa_base(nb_mode, 8));
	octal_mode /= 1000;
	if (octal_mode == 40)
		dir_info->type = "d";
	else if (octal_mode == 100)
		dir_info->type = "-";
	else if (octal_mode == 120)
		dir_info->type = "l";
	else
		dir_info->type = " ";
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
		dir_info->name = name;
		ft_get_type(buf.st_mode, dir_info);
		ft_get_mode(buf.st_mode, dir_info);
		dir_info->link = buf.st_nlink;
		dir_info->uid = usr.pw_name;
		dir_info->gid = grp.gr_name;;
		dir_info->size = buf.st_size;
		ft_get_time(ctime(&buf.st_ctime), dir_info);
	}
	else
		perror("stat");
	ft_strdel(&tmp);
}
