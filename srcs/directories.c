/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directories.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:37:23 by efischer          #+#    #+#             */
/*   Updated: 2019/05/24 18:36:43 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_find_next_dir(char *path, t_list *lst, uint8_t flags)
{
	char			*tmp;

	while (lst != NULL)
	{
		if (((t_dir*)(lst->content))->type == 'd'
		&& ft_strequ(((t_dir*)(lst->content))->name, ".") == 0
		&& ft_strequ(((t_dir*)(lst->content))->name, "..") == 0)
		{
			ft_putchar('\n');
			tmp = ft_asprintf("%s%s/", path, ((t_dir*)(lst->content))->name);
			ft_printf("%.*s:\n", ft_strlen(tmp) - 1, tmp);
			if (opendir(tmp) == NULL)
			{
				ft_strdel(&tmp);
				perror((tmp = ft_asprintf("ft_ls: %s", ((t_dir*)(lst->content))->name)));
				ft_strdel(&tmp);
				return ;
			}
			ft_open_dir(tmp, flags);
		}
		lst = lst->next;
	}
}

static void		ft_sort_dir(t_list **lst, uint8_t flags)
{
	ft_merge_sort(lst, &ft_sort_name);
	if ((flags & FLAG_T) == FLAG_T)
		ft_merge_sort(lst, &ft_sort_time);
	if ((flags & FLAG_REV) == FLAG_REV)
		ft_merge_sort(lst, &ft_sort_rev);
}

void			ft_open_dir(char *path, uint8_t flags)
{
	void			*dir;
	struct dirent	*dirent;
	t_dir			dir_info;
	t_padding		padding;
	t_list			*lst;

	lst = NULL;
	dir = opendir(path);
	ft_bzero(&padding, sizeof(padding));
	while ((dirent = readdir(dir)) != NULL)
	{
		ft_bzero(&dir_info, sizeof(dir_info));
		if (dirent->d_name[0] != '.' || (flags & FLAG_A) == FLAG_A)
		{
			ft_get_dir_info(ft_asprintf("%s/%s", path, dirent->d_name),
			dirent->d_name, &dir_info, &padding);
			ft_lstadd(&lst, ft_lstnew(&dir_info, sizeof(t_dir)));
		}
	}
	ft_sort_dir(&lst, flags);
	ft_printlist(lst, &padding, flags);
	if ((flags & FLAG_R) == FLAG_R)
		ft_find_next_dir(path, lst, flags);
	ft_strdel(&path);
	ft_free_dir_info(lst);
	ft_free_lst(&lst);
}

void			ft_directories(t_list *lst_dir, uint8_t flags)
{
	t_list	*head;

	head = lst_dir;
	while (lst_dir != NULL)
	{
		if (lst_dir != head || lst_dir->next != NULL)
			ft_printf("%s:\n", lst_dir->content);
		ft_open_dir(ft_asprintf("%s/", lst_dir->content), flags);
		if (lst_dir->next != NULL)
			ft_putchar('\n');
		lst_dir = lst_dir->next;
	}
}
