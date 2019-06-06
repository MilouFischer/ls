/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:49:25 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 13:57:16 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void			ft_get_mode(int nb_mode, t_dir *dir_info)
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

void			ft_get_type(int nb_mode, t_dir *dir_info)
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

static void		ft_time_or_year(char **tab, size_t i, t_dir *dir_info)
{
	int64_t		actual_time;
	size_t		j;

	j = 0;
	if ((actual_time = time(NULL)) == (time_t)FAILURE)
	{
		ft_memset(dir_info->time, 13, 0);
		return ;
	}
	if (actual_time - dir_info->brut_time < SIX_MONTHS)
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

void			ft_get_time(const char *brut_tm, t_dir *dir_info)
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
