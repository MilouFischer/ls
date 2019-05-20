/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:02:43 by efischer          #+#    #+#             */
/*   Updated: 2019/05/18 18:17:01 by efischer         ###   ########.fr       */
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

typedef	struct		s_dir
{
	char			*size;
	char			*name;
	char			*mode;
	char			*uid;
	char			*gid;
	char			*link;
	char			time[13];
	char			type;
}					t_dir;

typedef struct	s_padding
{
	size_t		size;
	size_t		name;
	size_t		uid;
	size_t		gid;
	size_t		link;
	size_t		type;
}				t_padding;

int		main(int ac, char **av);
void	ft_get_dir_info(char *path, char *name, t_dir *dir_info, t_padding *padding);
void	ft_merge_sort(t_list **lst);

#endif
