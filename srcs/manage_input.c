/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:40:36 by efischer          #+#    #+#             */
/*   Updated: 2019/05/24 17:09:56 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_check_dir(t_list **lst_dir, t_list **lst_file, char *arg)
{
	char	*tmp;

	tmp = NULL;
	if (opendir(arg) == NULL)
	{
		if (errno == ENOTDIR)
			ft_lstadd(lst_file, ft_lstnew(arg, ft_strlen(arg) + 1));
		else
		{
			perror((tmp = ft_asprintf("ft_ls: %s", arg)));
			ft_strdel(&tmp);
			return (TRUE);
		}
	}
	else if (arg != NULL)
	{
		if (arg[ft_strlen(arg) - 1] == '/')
		{
			tmp = ft_strndup(arg, ft_strlen(arg) - 2);
			ft_lstadd(lst_dir, ft_lstnew(tmp, ft_strlen(tmp) + 1));
			ft_strdel(&tmp);
		}
		else
			ft_lstadd(lst_dir, ft_lstnew(arg, ft_strlen(arg) + 1));
	}
	return (FALSE);
}

static void		ft_list_dir(t_list **lst_dir, t_list **lst_file, char **tab)
{
	size_t	i;
	int		error;

	i = 0;
	error = 0;
	if (tab[0] == NULL)
		ft_lstadd(lst_dir, ft_lstnew(".", 2));
	while (tab[i] != NULL)
		error += ft_check_dir(lst_dir, lst_file, tab[i++]);
	if (error >= 1 && *lst_dir != NULL && (*lst_dir)->next == NULL && *lst_file == NULL)
		ft_printf("\n%s:\n", (*lst_dir)->content);
	else if (error >= 1 && *lst_dir != NULL && *lst_file == NULL)
		ft_putchar('\n');
}

static void		ft_selection_sort(char **tab)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	while (tab[i] != NULL)
	{
		j = i;
		while (tab[j] != NULL)
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			ft_manage_input(int ac, char **av, t_list **lst_dir,
				t_list **lst_file)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	if ((tab = (char**)malloc(sizeof(char*) * (ac + 1))) == NULL)
		return ;
	while (i < ac)
	{
		tab[i] = av[i];
		i++;
	}
	tab[i] = NULL;
	ft_selection_sort(tab);
	ft_list_dir(lst_dir, lst_file, tab);
	free(tab);
}
