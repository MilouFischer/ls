/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:25:57 by efischer          #+#    #+#             */
/*   Updated: 2019/05/22 14:14:53 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static uint8_t	ft_manage_args(int *current_arg, int ac, char **av)
{
	size_t	i;
	uint8_t	flags;

	flags = 0;
	while (*current_arg < ac && av[*current_arg][0] == '-')
	{
		i = 0;
		while (av[*current_arg][i] != '\0')
		{
			if (av[*current_arg][i] == 'l')
				flags |= FLAG_L;
			else if (av[*current_arg][i] == 'a')
				flags |= FLAG_A;
			else if (av[*current_arg][i] == 'r')
				flags |= FLAG_REV;
			else if (av[*current_arg][i] == 't')
				flags |= FLAG_T;
			else if (av[*current_arg][i] == 'R')
				flags |= FLAG_R;
			i++;
		}
		(*current_arg)++;
	}
	return (flags);
}

static void		ft_check_dir(t_list **lst_dir, t_list **lst_file, char *dir,
				size_t len)
{
	char	*tmp;

	tmp = NULL;
	if (opendir(dir) == NULL)
	{
		if (errno == ENOTDIR)
			ft_lstadd(lst_file, ft_lstnew(dir, len));
		else
		{
			perror((tmp = ft_asprintf("ft_ls: %s", dir)));
			ft_strdel(&tmp);
		}
	}
	else if (dir != NULL)
	{
		if (dir[len - 1] != '/')
		{
			tmp = ft_strjoin(dir, "/");
			ft_lstadd(lst_dir, ft_lstnew(tmp, len));
			ft_strdel(&tmp);
		}
		else
			ft_lstadd(lst_dir, ft_lstnew(dir, len));
	}
	write(1, (*lst_dir)->content, (*lst_dir)->content_size);
}

static void		ft_list_dir(t_list **lst_dir, t_list **lst_file, t_list *lst_av)
{
	if (lst_av == NULL)
		ft_lstadd(lst_dir, ft_lstnew("./", 3));
	while (lst_av != NULL)
	{
		ft_check_dir(lst_dir, lst_file, lst_av->content, lst_av->content_size);
		lst_av = lst_av->next;
	}
}

static void		ft_files(t_list *lst_file, uint8_t flags)
{
	t_dir		dir_info;
	t_padding	padding;
	t_list		*lst;

	lst = NULL;
	ft_bzero(&padding, sizeof(padding));
	while (lst_file != NULL)
	{
		ft_bzero(&dir_info, sizeof(dir_info));
		ft_get_dir_info(ft_asprintf("./%s", lst_file->content),
		lst_file->content, &dir_info, &padding);
		ft_lstadd(&lst, ft_lstnew(&dir_info, sizeof(dir_info)));
		lst_file = lst_file->next;
	}
	ft_merge_sort(&lst, &ft_sort_name);
	if ((flags & FLAG_T) == FLAG_T)
		ft_merge_sort(&lst, &ft_sort_time);
	if ((flags & FLAG_REV) == FLAG_REV)
		ft_merge_sort(&lst, &ft_sort_rev);
	ft_printlist(lst, &padding, flags);
	ft_free_lst(&lst);
}

static void		ft_sort_av(t_list **lst_av, int ac, char **av)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		ft_lstadd(lst_av, ft_lstnew(av[i], ft_strlen(av[i]) + 1));
		i++;
	}
	ft_merge_sort(lst_av, ft_sort_name_av);
}

int				main(int ac, char **av)
{
	t_list	*lst_av;
	t_list	*lst_dir;
	t_list	*lst_file;
	int		i;
	uint8_t	flags;

	i = 1;
	lst_av = NULL;
	lst_dir = NULL;
	lst_file = NULL;
	flags = ft_manage_args(&i, ac, av);
	ft_sort_av(&lst_av, ac - i, av + i);
	ft_list_dir(&lst_dir, &lst_file, lst_av);
	if (lst_file != NULL)
	{
		ft_files(lst_file, flags);
		if (lst_dir != NULL)
			ft_printf("\n%.*s:\n", lst_dir->content_size - 1, lst_dir->content);
	}
	ft_directories(lst_dir, flags);
	ft_free_lst(&lst_file);
	ft_free_lst(&lst_dir);
	return (0);
}
