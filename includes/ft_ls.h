/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:02:43 by efischer          #+#    #+#             */
/*   Updated: 2019/06/06 13:56:25 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <errno.h>
# include <stdint.h>
# include <sys/ioctl.h>
# include "libft.h"

# define SIX_MONTHS		15768000
# define HIDE_TOTAL		0
# define PRINT_TOTAL	1
# define FLAG_L			0x001
# define FLAG_A			0x002
# define FLAG_REV		0x004
# define FLAG_T			0x008
# define FLAG_R			0x010
# define FLAG_G			0x020
# define FLAG_D			0x040
# define FLAG_U			0x080
# define FLAG_1			0x100
# define OTH_X			0x001
# define OTH_W			0x002
# define OTH_R			0x004
# define GRP_X			0x008
# define GRP_W			0x010
# define GRP_R			0x020
# define USR_X			0x040
# define USR_W			0x080
# define USR_R			0x100
# define STICKY_BIT		0x200
# define SET_GID		0x400
# define SET_UID		0x800
# define TYPE_P			0x1
# define TYPE_C			0x2
# define TYPE_D			0x4
# define TYPE_B			0x6
# define TYPE_F			0x8
# define TYPE_L			0xA
# define TYPE_S			0xC

typedef	struct		s_dir
{
	char		*size;
	char		*name;
	char		*uid;
	char		*gid;
	char		*link;
	char		*major;
	char		*minor;
	char		*path;
	char		*s_link;
	char		mode[10];
	char		time[13];
	char		type;
	int			nb_mode;
	size_t		nb_blocks;
	int64_t		brut_time;
}					t_dir;

typedef struct		s_padding
{
	size_t			size;
	size_t			name;
	size_t			uid;
	size_t			gid;
	size_t			link;
	size_t			type;
	size_t			major;
	size_t			minor;
	size_t			total;
	size_t			ws_col;
}					t_padding;

uint16_t			ft_manage_args(int *current_arg, int ac, char **av);
void				ft_sort_input(t_list **lst1, t_list **lst2, t_list **head);
void				ft_manage_input(char **av, t_list **lst_dir,
						t_list **lst_file, uint16_t flags);
int					ft_get_dir_info(char *path, char *name, t_dir *dir_info,
						uint16_t flags);
void				ft_get_time(const char *brut_tm, t_dir *dir_info);
void				ft_get_type(int nb_mode, t_dir *dir_info);
void				ft_get_mode(int nb_mode, t_dir *dir_info);
void				ft_get_padding(t_padding *padding, t_dir *dir_info);
void				ft_format_s_link(t_dir *dir_info);
void				ft_directories(t_list *lst_dir, uint16_t flags);
void				ft_open_dir(char *path, uint16_t flags);
void				ft_sort(t_list **lst, uint16_t flags);
void				ft_sort_name(t_list **lst1, t_list **lst2, t_list **head);
void				ft_sort_time(t_list **lst1, t_list **lst2, t_list **head);
void				ft_sort_rev(t_list **lst1, t_list **lst2, t_list **head);
void				ft_sort_name_av(t_list **lst1, t_list **lst2,
						t_list **head);
void				ft_print_dir_info(t_dir *dir, t_padding *padding,
						uint16_t flags);
void				ft_printlist(t_list *lst, t_padding *padding,
						uint16_t flags, int print);
void				ft_column_display(t_list *lst, t_padding *padding,
						uint16_t flags);
void				ft_print_color(t_dir *dir, t_padding *padding,
						uint16_t flags);
void				ft_free_dir_info(t_dir *dir);
void				ft_free_struct_list(void *content, size_t content_size);
void				ft_free_content(void *content, size_t content_size);

#endif
