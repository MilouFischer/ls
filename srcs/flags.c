/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:29:10 by efischer          #+#    #+#             */
/*   Updated: 2019/06/07 16:31:30 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flags.h"

static void		ft_get_flags(char *arg, uint16_t *flags)
{
	while (*arg != '\0')
	{
		if (*arg == 'l')
			*flags |= FLAG_L;
		else if (*arg == 'a')
			*flags |= FLAG_A;
		else if (*arg == 'r')
			*flags |= FLAG_REV;
		else if (*arg == 'R')
			*flags |= FLAG_R;
		else if (*arg == 't')
			*flags |= FLAG_T;
		else if (*arg == 'G')
			*flags |= FLAG_G;
		else if (*arg == 'd')
			*flags |= FLAG_D;
		else if (*arg == '1')
			*flags |= FLAG_1;
		else
		{
			ft_printf("ft_ls: illegal option -- %c\n", *arg);
			ft_putendl("usage: ft_ls [-GRadlrt1] [file ...]");
			exit(EXIT_FAILURE);
		}
		arg++;
	}
}

uint16_t		ft_manage_args(int *current_arg, int ac, char **av)
{
	uint16_t	flags;

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
