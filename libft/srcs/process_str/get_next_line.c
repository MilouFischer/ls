/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:44:56 by efischer          #+#    #+#             */
/*   Updated: 2019/05/13 16:57:24 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_init_list(const int fd)
{
	t_file	*file;
	t_list	*list;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	file->rest = NULL;
	file->cur = NULL;
	file->fd = fd;
	if (!(list = ft_lstnew(file, sizeof(t_file))))
	{
		free(file);
		file = NULL;
		return (NULL);
	}
	free(file);
	file = NULL;
	return (list);
}

static int		ft_rest(t_file *file, char **line)
{
	char	*tmp;
	char	*tmp_rest;

	if (file->rest)
	{
		if ((tmp = ft_strchr(file->rest, '\n')))
		{
			tmp_rest = file->rest;
			*line = ft_strsub(file->rest, 0, tmp - file->rest);
			file->rest = ft_strdup(tmp + 1);
			ft_strdel(&tmp_rest);
			if (*(file->rest) == '\0')
				ft_strdel(&file->rest);
			return (1);
		}
		else
			file->cur = ft_strdup(file->rest);
		ft_strdel(&file->rest);
	}
	return (0);
}

static int		ft_read(t_file *file, char **line)
{
	char	*tmp;
	char	*tmp_rest;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(file->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((tmp_rest = ft_strchr(buf, '\n')))
		{
			tmp = ft_strsub(buf, 0, tmp_rest - buf);
			*line = ft_strjoin(file->cur, tmp);
			ft_strdel(&file->cur);
			ft_strdel(&tmp);
			file->rest = ft_strdup(tmp_rest + 1);
			return (1);
		}
		else
		{
			tmp = file->cur;
			file->cur = ft_strjoin(file->cur, buf);
			ft_strdel(&tmp);
		}
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*tmp;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (!list)
		list = ft_init_list(fd);
	tmp = list;
	while (tmp && T_FILEL->fd != fd)
	{
		if (!tmp->next)
			tmp->next = ft_init_list(fd);
		else
			tmp = tmp->next;
	}
	if ((ft_rest(T_FILEL, line)) == 1 || (ret = ft_read(T_FILEL, line)) == 1)
		return (1);
	if (T_FILEL->cur && *(T_FILEL->cur))
	{
		*line = ft_strdup(T_FILEL->cur);
		ft_strdel(&T_FILEL->cur);
		return (1);
	}
	return (ret);
}
