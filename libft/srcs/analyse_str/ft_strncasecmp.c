/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:06:11 by efischer          #+#    #+#             */
/*   Updated: 2018/11/14 15:12:04 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*tmp_s1;
	unsigned const char *tmp_s2;

	tmp_s1 = (unsigned const char *)s1;
	tmp_s2 = (unsigned const char *)s2;
	while ((*tmp_s1 || *tmp_s2) && n)
	{
		if (ft_tolower(*tmp_s1) != ft_tolower(*tmp_s2))
			return ((int)((unsigned char)*tmp_s1 - (unsigned char)*tmp_s2));
		tmp_s1++;
		tmp_s2++;
		n--;
	}
	return (0);
}
