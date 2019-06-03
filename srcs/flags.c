/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:35:48 by efischer          #+#    #+#             */
/*   Updated: 2019/05/29 16:48:40 by efischer         ###   ########.fr       */
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
		else if (arg[i] == 'R')
			*flags |= FLAG_R;
		else if (arg[i] == 't')
			*flags |= FLAG_T;
		else if (arg[i] == 'G')
			*flags |= FLAG_G;
		else if (arg[i] == 'd')
			*flags |= FLAG_D;
		else
		{
			ft_putendl("ft_ls: illegal option -- -");
			ft_putendl("usage: ft_ls [-Ralrt] [file ...]");
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
		if (ft_strequ(av[*current_arg], "--") == TRUE)
		{
			(*current_arg)++;
			return (flags);
		}
		ft_get_flags(av[*current_arg] + 1, &flags);
		(*current_arg)++;
	}
	return (flags);
}
