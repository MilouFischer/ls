/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:35:48 by efischer          #+#    #+#             */
/*   Updated: 2019/05/24 14:50:39 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_get_flags(char *arg, uint8_t *flags)
{
	size_t	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == 'l')
			*flags |= FLAG_L;
		else if (arg[i] == 'a')
			*flags |= FLAG_A;
		else if (arg[i] == 'r')
			*flags |= FLAG_REV;
		else if (arg[i] == 't')
			*flags |= FLAG_T;
		else if (arg[i] == 'R')
			*flags |= FLAG_R;
		else
		{
			ft_putendl("ft_ls: illegal option -- -\nusage: ft_ls [-Ralrt] [file ...]");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

uint8_t			ft_manage_args(int *current_arg, int ac, char **av)
{
	uint8_t	flags;

	flags = 0;
	while (*current_arg < ac && av[*current_arg][0] == '-'
			&& av[*current_arg][1] != '\0')
	{
		if (av[*current_arg][1] == '-')
		{
			(*current_arg)++;
			return (flags);
		}
		ft_get_flags(av[*current_arg] + 1, &flags);
		(*current_arg)++;
	}
	return (flags);
}
