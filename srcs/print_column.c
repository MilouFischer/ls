/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:09:47 by efischer          #+#    #+#             */
/*   Updated: 2019/05/31 17:49:42 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static size_t	ft_lstlen(t_list *lst)
{
	size_t	lstlen;

	lstlen = 0;
	while (lst != NULL)
	{
		lstlen++;
		lst = lst->next;
	}
	return (lstlen);
}

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

static void		ft_print_column(t_dir **tab, size_t nb_arg, t_padding *padding,
				uint8_t flags)
{
	struct winsize	winsize;
	size_t			nb_max_arg_by_line;
	size_t			total_line;
	size_t			nb_line;
	size_t			i;

	ioctl(0, TIOCGWINSZ, &winsize);
	nb_max_arg_by_line = winsize.ws_col / padding->name;
	total_line = nb_arg / nb_max_arg_by_line + 1;
	nb_line = 0;
	while (nb_line < total_line)
	{
		i = nb_line;
		while (i < nb_arg)
		{
			if ((flags & FLAG_G) == FLAG_G)
				ft_print_color(tab[i], padding, flags);
			else
				ft_printf("%-*s", padding->name, tab[i]->name);
			i += total_line;
		}
		ft_putchar('\n');
		nb_line++;
	}
}

void			ft_column_display(t_list *lst, t_padding *padding, uint8_t flags)
{
	t_dir			**tab;
	size_t			nb_arg;

	tab = get_arg_tab(lst, &nb_arg);
	if (tab == NULL)
		return ;
	ft_print_column(tab, nb_arg, padding, flags);
	free(tab);
}
