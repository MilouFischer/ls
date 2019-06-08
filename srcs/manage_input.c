/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:29:25 by efischer          #+#    #+#             */
/*   Updated: 2019/06/08 13:12:22 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_input.h"

static void		ft_put_dir_in_list(t_list **lst_dir, t_list **lst_file,
				char *arg, uint16_t flags)
{
	t_dir		dir_info;
	t_padding	padding;

	ft_bzero(&dir_info, sizeof(dir_info));
	ft_bzero(&padding, sizeof(padding));
	ft_get_dir_info(NULL, arg, &dir_info, flags);
	if (((flags & FLAG_L) == FLAG_L && dir_info.type == 'l')
		|| (flags & FLAG_D) == FLAG_D)
		ft_lstaddend(lst_file, ft_lstnew(arg, ft_strlen(arg) + 1));
	else
		ft_lstaddend(lst_dir, ft_lstnew(arg, ft_strlen(arg) + 1));
	ft_free_dir_info(&dir_info);
}

static int		ft_check_dir(t_list **lst_dir, t_list **lst_file, char *arg,
				uint16_t flags)
{
	void		*dir;
	char		*tmp;

	dir = opendir(arg);
	if (dir == NULL)
	{
		if (errno == ENOTDIR)
			ft_lstaddend(lst_file, ft_lstnew(arg, ft_strlen(arg) + 1));
		else
		{
			perror((tmp = ft_asprintf("ft_ls: %s", arg)));
			ft_strdel(&tmp);
			return (TRUE);
		}
	}
	else if (arg != NULL)
	{
		ft_put_dir_in_list(lst_dir, lst_file, arg, flags);
		closedir(dir);
	}
	return (FALSE);
}

static void		ft_list_dir(t_list **lst_dir, t_list **lst_file, char **tab,
				uint16_t flags)
{
	size_t	i;
	int		error;

	i = 0;
	error = 0;
	if ((flags & FLAG_D) == FLAG_D && tab[0] == NULL)
		ft_lstaddend(lst_file, ft_lstnew(".", 2));
	else if (tab[0] == NULL)
		ft_lstaddend(lst_dir, ft_lstnew(".", 2));
	while (tab[i] != NULL)
		error += ft_check_dir(lst_dir, lst_file, tab[i++], flags);
	if (error >= 1 && *lst_dir != NULL && (*lst_dir)->next == NULL
	&& *lst_file == NULL)
		ft_printf("\n%s:\n", (*lst_dir)->content);
	else if (error >= 1 && *lst_dir != NULL && *lst_file == NULL)
		ft_putchar('\n');
}

void			ft_manage_input(char **av, t_list **lst_dir,
				t_list **lst_file, uint16_t flags)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	while (av[i])
		i++;
	if ((tab = (char**)malloc(sizeof(char*) * (i + 1))) == NULL)
		return ;
	i = 0;
	while (av[i])
	{
		tab[i] = av[i];
		i++;
	}
	tab[i] = NULL;
	ft_selection_sort(tab);
	ft_list_dir(lst_dir, lst_file, tab, flags);
	free(tab);
}
