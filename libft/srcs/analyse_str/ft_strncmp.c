/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:05:33 by efischer          #+#    #+#             */
/*   Updated: 2018/11/13 15:05:14 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*tmp_s1;
	unsigned const char *tmp_s2;

	tmp_s1 = (unsigned const char *)s1;
	tmp_s2 = (unsigned const char *)s2;
	while ((*tmp_s1 || *tmp_s2) && n)
	{
		if (*tmp_s1 != *tmp_s2)
			return ((int)((unsigned char)*tmp_s1 - (unsigned char)*tmp_s2));
		tmp_s1++;
		tmp_s2++;
		n--;
	}
	return (0);
}
