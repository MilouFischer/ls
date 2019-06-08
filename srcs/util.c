/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:29:39 by efischer          #+#    #+#             */
/*   Updated: 2019/06/08 14:32:33 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void		ft_format_s_link(t_dir *dir_info)
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

void		ft_free_dir_info(t_dir *dir)
{
	if (dir != NULL)
	{
		ft_strdel(&dir->name);
		ft_strdel(&dir->path);
		ft_strdel(&dir->size);
		ft_strdel(&dir->link);
		ft_strdel(&dir->major);
		ft_strdel(&dir->minor);
		ft_strdel(&dir->uid);
		ft_strdel(&dir->gid);
	}
}

void		ft_free_struct_list(void *content, size_t content_size)
{
	(void)content_size;
	ft_free_dir_info(((t_dir*)(content)));
	free(content);
}
