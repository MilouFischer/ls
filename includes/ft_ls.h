/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:02:43 by efischer          #+#    #+#             */
/*   Updated: 2019/05/22 13:23:27 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

#include <stdint.h>

# define SIX_MONTHS	15768000
# define FLAG_L		0x01
# define FLAG_A		0x02
# define FLAG_REV	0x04
# define FLAG_T		0x08
# define FLAG_R		0x10
# define OTH_X		0x001
# define OTH_W		0x002
# define OTH_R		0x004
# define GRP_X		0x008
# define GRP_W		0x010
# define GRP_R		0x020
# define USR_X		0x040
# define USR_W		0x080
# define USR_R		0x100
# define TYPE_P		0x01
# define TYPE_C		0x02
# define TYPE_D		0x04
# define TYPE_B		0x06
# define TYPE_F		0x08
# define TYPE_L		0x10
# define TYPE_S		0x12

typedef	struct		s_dir
{
	char			*size;
	char			*name;
	char			mode[10];
	char			*uid;
	char			*gid;
	char			*link;
	char			time[13];
	char			type;
	unsigned long	brut_time;
}					t_dir;

typedef struct		s_padding
{
	size_t			size;
	size_t			name;
	size_t			uid;
	size_t			gid;
	size_t			link;
	size_t			type;
	size_t			total;
}					t_padding;

void				ft_get_dir_info(char *path, char *name, t_dir *dir_info,
					t_padding *padding);
void				ft_directories(t_list *lst_dir, uint8_t flags);
void				ft_open_dir(char *path, uint8_t flags);
void				ft_merge_sort(t_list **lst, void sort(t_list**, t_list**,
					t_list**));
void				ft_sort_name(t_list **lst1, t_list **lst2, t_list **head);
void				ft_sort_time(t_list **lst1, t_list **lst2, t_list **head);
void				ft_sort_rev(t_list **lst1, t_list **lst2, t_list **head);
void				ft_sort_name_av(t_list **lst1, t_list **lst2,
					t_list **head);
void				ft_free_dir_info(t_dir *dir_info);
void				ft_free_lst(t_list **lst);
void				ft_print_dir_info(t_dir *dir, t_padding *padding,
					uint8_t flags);
void				ft_printlist(t_list *lst, t_padding *padding,
					uint8_t flags);

#endif
