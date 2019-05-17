/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:20:30 by efischer          #+#    #+#             */
/*   Updated: 2018/11/13 15:08:47 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	char			*tmp;

	tmp = (char *)haystack;
	if (!*needle)
		return (tmp);
	while (*tmp)
	{
		if (*tmp == needle[0])
		{
			i = 0;
			while (tmp[i] == needle[i] && tmp[i] && needle[i])
				i++;
			if (!needle[i])
				return (tmp);
		}
		tmp++;
	}
	return (0);
}
