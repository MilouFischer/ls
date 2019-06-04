/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:25:57 by efischer          #+#    #+#             */
/*   Updated: 2019/06/04 17:24:02 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_files(t_list *lst_file, uint16_t flags)
{
	t_dir		dir_info;
	t_padding	padding;
	t_list		*lst;

	lst = NULL;
	ft_bzero(&padding, sizeof(padding));
	while (lst_file != NULL)
	{
		ft_bzero(&dir_info, sizeof(dir_info));
		if (ft_get_dir_info(ft_strdup(lst_file->content),
		lst_file->content, &dir_info, flags) == SUCCESS)
		{
			ft_get_padding(&padding, &dir_info);
			ft_lstaddend(&lst, ft_lstnew(&dir_info, sizeof(dir_info)));
		}
		lst_file = lst_file->next;
	}
	ft_sort(&lst, flags);
	ft_printlist(lst, &padding, flags, HIDE_TOTAL);
	ft_lstdel(&lst, ft_free_struct_list);
}

int				main(int ac, char **av)
{
	t_list		*lst_dir;
	t_list		*lst_file;
	int			i;
	uint16_t	flags;

	i = 1;
	lst_dir = NULL;
	lst_file = NULL;
	flags = ft_manage_args(&i, ac, av);
	ft_manage_input(av + i, &lst_dir, &lst_file, flags);
	if ((flags & FLAG_U) == FALSE)
	{
		ft_merge_sort(&lst_dir, ft_sort_input);
		if ((flags & FLAG_REV) == FLAG_REV)
			ft_merge_sort(&lst_dir, ft_sort_rev);
	}
	if (lst_file != NULL)
	{
		ft_files(lst_file, flags);
		if (lst_dir != NULL && lst_dir->next == NULL)
			ft_printf("\n%s:\n", lst_dir->content);
		else if (lst_dir != NULL)
			ft_putchar('\n');
	}
	ft_directories(lst_dir, flags);
	ft_lstdel(&lst_file, ft_free_content);
	ft_lstdel(&lst_dir, ft_free_content);
	return (EXIT_SUCCESS);
}
