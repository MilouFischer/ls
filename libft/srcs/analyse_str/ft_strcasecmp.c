/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:37:48 by efischer          #+#    #+#             */
/*   Updated: 2018/11/14 15:27:31 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	i = 0;
	while (ft_tolower(tmp_s1[i]) == ft_tolower(tmp_s2[i]))
	{
		if (!tmp_s1[i] || !tmp_s2[i])
			return (0);
		i++;
	}
	return ((unsigned char)tmp_s1[i] - (unsigned char)tmp_s2[i]);
}
