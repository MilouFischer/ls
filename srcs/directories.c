/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directories.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:37:23 by efischer          #+#    #+#             */
/*   Updated: 2019/05/29 15:39:51 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_check_right(char *path, t_list *lst)
{
	void	*dir;
	char	*tmp;

	if ((dir = opendir(path)) == NULL)
	{
		perror((tmp = ft_asprintf("ft_ls: %s",
		((t_dir*)(lst->content))->name)));
		ft_strdel(&tmp);
		return (FALSE);
	}
	free(dir);
	return (TRUE);
}

static void		ft_find_next_dir(char *path, t_list *lst, uint8_t flags)
{
	char	*tmp;

	while (lst != NULL)
	{
		if ((((t_dir*)(lst->content))->type == 'd'
		|| (((t_dir*)(lst->content))->type == 'l'
		&& (flags & FLAG_L) != FLAG_L))
		&& ft_strequ(((t_dir*)(lst->content))->name, ".") == 0
		&& ft_strequ(((t_dir*)(lst->content))->name, "..") == 0)
		{
			ft_putchar('\n');
			tmp = ft_asprintf("%s/%s", path, ((t_dir*)(lst->content))->name);
			ft_printf("%s:\n", tmp);
			if (ft_check_right(tmp, lst) == FALSE)
			{
				ft_strdel(&tmp);
				return ;
			}
			ft_check_right(tmp, lst);
			ft_open_dir(tmp, flags);
			ft_strdel(&tmp);
		}
		lst = lst->next;
	}
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
	ft_sort(&lst, flags);
	ft_printlist(lst, &padding, flags, PRINT_TOTAL);
	if ((flags & FLAG_R) == FLAG_R)
		ft_find_next_dir(path, lst, flags);
	free(dir);
	ft_lstdel(&lst, ft_free_struct_list);
}

void			ft_directories(t_list *lst_dir, uint8_t flags)
{
	t_list	*head;

	head = lst_dir;
	while (lst_dir != NULL)
	{
		if (lst_dir != head || lst_dir->next != NULL)
			ft_printf("%s:\n", lst_dir->content);
		ft_open_dir(lst_dir->content, flags);
		if (lst_dir->next != NULL)
			ft_putchar('\n');
		lst_dir = lst_dir->next;
	}
}
