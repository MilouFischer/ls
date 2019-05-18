/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:52:45 by efischer          #+#    #+#             */
/*   Updated: 2019/01/11 17:14:13 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char **tmp)
{
	int		i;

	i = 0;
	if (!tmp || !*tmp)
		return ;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i++] = NULL;
	}
	free(tmp);
	tmp = NULL;
}
