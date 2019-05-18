/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:04:32 by efischer          #+#    #+#             */
/*   Updated: 2019/05/17 17:20:08 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;
	unsigned const char	*tmp_s1;
	unsigned const char	*tmp_s2;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (0 - (unsigned char)s2[0]);
	if (!s2)
		return ((unsigned char)s1[0]);
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
