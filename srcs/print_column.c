/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:29:32 by efischer          #+#    #+#             */
/*   Updated: 2019/06/08 14:03:28 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_column.h"

static t_dir	**get_arg_tab(t_list *lst, size_t *nb_arg)
{
	t_dir	**tab;
	size_t	i;

	i = 0;
	*nb_arg = ft_lstlen(lst);
	tab = (t_dir**)malloc(sizeof(t_dir*) * (*nb_arg + 1));
	if (tab == NULL)
		return (NULL);
	while (i < *nb_arg && lst != NULL)
	{
		tab[i++] = (t_dir*)(lst->content);
		lst = lst->next;
	}
	tab[i] = NULL;
	return (tab);
}

static size_t	ft_get_total_line(t_padding *padding, size_t nb_arg)
{
	size_t	nb_max_arg_by_line;
	size_t	total_line;

	total_line = 1;
	nb_max_arg_by_line = padding->ws_col / padding->name;
	if (nb_max_arg_by_line != 0)
		total_line = nb_arg / nb_max_arg_by_line + 1;
	return (total_line);
}

static void		ft_fill_line(char **buf, t_dir *dir, t_padding *padding,
				uint16_t flags)
{
	if (flags & FLAG_G)
		*buf = ft_join_free(*buf, ft_print_color(dir, padding, flags), 3);
	else
	{
		*buf = ft_join_free(*buf, ft_asprintf("%-*s", padding->name,
					dir->name), 3);
	}
}

static void		ft_print_column(t_dir **tab, size_t nb_arg, t_padding *padding,
				uint16_t flags)
{
	size_t	total_line;
	size_t	nb_line;
	size_t	i;
	char	*buf;

	buf = NULL;
	total_line = ft_get_total_line(padding, nb_arg);
	nb_line = 0;
	while (nb_line < total_line)
	{
		i = nb_line;
		while (i < nb_arg)
		{
			ft_fill_line(&buf, tab[i], padding, flags);
			i += total_line;
		}
		buf = ft_join_free(buf, "\n", 1);
		nb_line++;
	}
	ft_putstr(buf);
	ft_strdel(&buf);
}

void			ft_column_display(t_list *lst, t_padding *padding,
				uint16_t flags)
{
	t_dir			**tab;
	size_t			nb_arg;

	tab = get_arg_tab(lst, &nb_arg);
	if (tab == NULL || padding->name == 0)
		return ;
	ft_print_column(tab, nb_arg, padding, flags);
	free(tab);
}
