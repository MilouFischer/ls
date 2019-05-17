/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:29:53 by efischer          #+#    #+#             */
/*   Updated: 2019/03/15 16:16:20 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *haystack, const char *needle)
{
	unsigned int	i;
	char			*tmp;

	tmp = (char *)haystack;
	if (!*needle)
		return (tmp);
	while (*tmp)
	{
		if (ft_tolower(*tmp) == ft_tolower(needle[0]))
		{
			i = 0;
			while (ft_tolower(tmp[i]) == ft_tolower(needle[i]) && tmp[i]
			&& needle[i])
				i++;
			if (!needle[i])
				return (tmp);
		}
		tmp++;
	}
	return (0);
}
