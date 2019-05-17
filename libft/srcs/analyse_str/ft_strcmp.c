/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:04:32 by efischer          #+#    #+#             */
/*   Updated: 2018/11/14 15:25:48 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;
	unsigned const char	*tmp_s1;
	unsigned const char	*tmp_s2;

	tmp_s1 = (unsigned const char *)s1;
	tmp_s2 = (unsigned const char *)s2;
	i = 0;
	while (tmp_s1[i] == tmp_s2[i])
	{
		if (!tmp_s1[i] || !tmp_s2[i])
			return (0);
		i++;
	}
	return ((unsigned char)tmp_s1[i] - (unsigned char)tmp_s2[i]);
}
